
#include <ASTDeclNode.h>
#include <llvm/Support/NativeFormatting.h>

#include "AST.h"
#include "InternalError.h"
#include "SemanticAnalysis.h"
#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Intrinsics.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/TargetParser/Host.h"
#include "llvm/Transforms/Scalar.h"

#include "loguru.hpp"

using namespace llvm;

namespace {

llvm::LLVMContext llvmContext;
llvm::IRBuilder<> irBuilder(llvmContext);

/*
 * Functions are represented with indices into a table.
 * This permits function values to be passed, i.e, as Int64 indices.
 */
std::map<std::string, int> functionIndex;
std::map<std::string, std::vector<std::string>> functionFormalNames;

std::map<std::string, llvm::AllocaInst *> namedValues;

llvm::StructType *globalRecordType;

llvm::PointerType *pointerToGlobalRecordType;

// Maps field names to their index in the globalRecord
std::map<std::basic_string<char>, int> fieldIndex;

// Vector of fields in a global record
std::vector<std::basic_string<char>> fieldVector;

// Permits getFunction to access the current module being compiled
std::shared_ptr<llvm::Module> CurrentModule;

/*
 * We use calls to llvm intrinsics for several purposes.  To construct a "nop",
 * using an LLVM internal intrinsic, to perform TIP specific IO, and
 * to allocate heap memory.
 */
llvm::Function *nop = nullptr;
llvm::Function *inputIntrinsic = nullptr;
llvm::Function *outputIntrinsic = nullptr;
llvm::Function *errorIntrinsic = nullptr;
llvm::Function *callocFun = nullptr;

// A counter to create shared labels
int labelNum = 0;

// Indicate whether the expression code gen is for an L-value
bool lValueGen = false;

// Indicate whether the expression code gen is for an alloc'd value
bool allocFlag = false;

llvm::GlobalVariable *tipFunctionTable = nullptr;

int64_t numTIPArgs = 0;

/*
 * The global argument count and array are used to communicate command
 * line inputs to the TIP main function.
 */
llvm::GlobalVariable *tipNumInputs = nullptr;
llvm::GlobalVariable *tipInputArray = nullptr;

/*
 * Some constants are used repeatedly in code generation.  We define them
 * hear to eliminate redundancy.
 */
llvm::Constant *zeroV =
    llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvmContext), 0);
llvm::Constant *oneV =
    llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvmContext), 1);

/*
 * Create LLVM Function in Module associated with current program.
 * This function declares the function, but it does not generate code.
 * This is a key element of the shallow pass that builds the function
 * dispatch table.
 */

llvm::Function *getFunction(const std::string& functionName) {
  auto formalNames = functionFormalNames[functionName];

  /*
   * Main is handled specially.  It is declared as "_tip_main" with
   * no arguments - any arguments are converted to locals with special
   * initializaton in Function::codegen().
   */

  if (functionName == "main") {
    if (auto *M = CurrentModule->getFunction("_tip_main")) {
      return M;
    }

    numTIPArgs = formalNames.size();

    // Declare "_tip_main"
    auto *scratchModule = llvm::Function::Create(
        llvm::FunctionType::get(llvm::Type::getInt64Ty(llvmContext), false),
        llvm::Function::ExternalLinkage, "_tip_" + functionName,
        CurrentModule.get());
    return scratchModule;
  } else {
    if (auto *F = CurrentModule->getFunction(functionName)) {
      return F;
    }

    // Function Not Found, Create it.

    std::vector<llvm::Type *> FormalTypes(formalNames.size(),
                                          llvm::Type::getInt64Ty(llvmContext));

    // Use type factory to create function from formal type to int

    auto *scratchFunctionType = llvm::FunctionType::get(
        llvm::Type::getInt64Ty(llvmContext), FormalTypes, false);

    auto *scratchFunction = llvm::Function::Create(
        scratchFunctionType, llvm::Function::InternalLinkage, functionName,
        CurrentModule.get());

    // assign names to function arguments
    unsigned i = 0;
    for (auto &param : scratchFunction->args()) {
      param.setName(formalNames[i++]);
    }
    return scratchFunction;
  }
}

/*
 * Create an alloca instruction in the entry block of the function.
 * This is used for mutable variables, including arguments to functions.
 */
llvm::AllocaInst *CreateEntryBlockAlloca(llvm::Function *TheFunction,
                                         const std::string &VarName) {
  llvm::IRBuilder<> tmpAlloca(&TheFunction->getEntryBlock(),
                              TheFunction->getEntryBlock().begin());
  return tmpAlloca.CreateAlloca(llvm::Type::getInt64Ty(llvmContext), nullptr,
                                VarName);
}
} // namespace

/********************* CodeGen routines ***********************/

std::shared_ptr<llvm::Module>
ASTProgram::codegen(SemanticAnalysis *semanticAnalysis,
                    const std::string &programName) {
  LOG_S(1) << "Generating code for program " << programName;

  auto TheModule = std::make_shared<llvm::Module>(programName, llvmContext);

  llvm::Triple targetTriple(llvm::sys::getProcessTriple());
  TheModule->setTargetTriple(targetTriple.str());

  nop = llvm::Intrinsic::getDeclaration(TheModule.get(),
                                        llvm::Intrinsic::donothing);

  labelNum = 0;

  // Transfer the module for access by shared codegen routines
  CurrentModule = std::move(TheModule);

  /*
   * This shallow pass over the function declarations builds the
   * function symbol table, creates the function declarations, and
   * builds the function dispatch table.
   */
  {
    /*
     * First create the local function symbol table which stores
     * the function index and formal parameters
     */

    int funIndex = 0;
    for (auto const &fn : ASTProgram::getFunctions()) {
      functionIndex[fn->getName()] = funIndex++;

      auto formalNames = fn->getFormals();
      std::vector<std::string> names;
      std::transform(formalNames.begin(), formalNames.end(),
                     std::back_inserter(names),
                     [](auto &d) { return d->getName(); });

      functionFormalNames[fn->getName()] = names;
    }

    /*
     * Create the llvm functions.
     * Store as a vector of constants, which works because Function
     * is a subtype of Constant, to a workaround the inability of the
     * compiler to find a conversion from Function to Constant
     * below in creating the ftableInit.
     */

    std::vector<llvm::Constant *> programFunctions;
    for (auto const &func : ASTProgram::getFunctions()) {
      programFunctions.emplace_back(getFunction(func->getName()));
    }

    // Holder for function pointer.
    auto *FunctionOpaquePtrType = llvm::PointerType::get(llvmContext, 0);
    // Create Record Dispatch Table

    // Function table is array of pointers, which is the size of funIndex, i.e.
    // Number of total declared functions.
    auto *functionTableType =
        llvm::ArrayType::get(FunctionOpaquePtrType, funIndex);

    std::vector<llvm::Constant *> castProgramFunctions;

    castProgramFunctions.reserve(programFunctions.size());
    for (auto const &pf : programFunctions) {
      castProgramFunctions.push_back(
          llvm::ConstantExpr::getPointerCast(pf, FunctionOpaquePtrType));
    }
    /*
     * Create initializer for function table and set the initial value.
     */
    auto *ftableInit =
        llvm::ConstantArray::get(functionTableType, castProgramFunctions);

    // Create the global function dispatch table
    tipFunctionTable = new llvm::GlobalVariable(
        *CurrentModule, functionTableType, true,
        llvm::GlobalValue::InternalLinkage, ftableInit, "_tip_ftable");
  }

  /*
   * Generate globals that establish the parameter passing structures from the
   * rtlib main() and define a "_tip_main" if one is not already defind.
   */
  {
    /*
     * If there is no "main(...)" defined in this TIP program we
     * create main that calls the "_tip_main_undefined()" rtlib function.
     *
     * For this function we perform all code generation here, and
     * we never visit it during the codegen() traversals - since
     * the function doesn't exist in the TIP program.
     */
    auto fidx = functionIndex.find("main");
    if (fidx == functionIndex.end()) {
      auto *M = llvm::Function::Create(
          llvm::FunctionType::get(llvm::Type::getInt64Ty(llvmContext), false),
          llvm::Function::ExternalLinkage, "_tip_main", CurrentModule.get());
      llvm::BasicBlock *BB = llvm::BasicBlock::Create(llvmContext, "entry", M);
      irBuilder.SetInsertPoint(BB);

      auto *undef = llvm::Function::Create(
          llvm::FunctionType::get(llvm::Type::getVoidTy(llvmContext), false),
          llvm::Function::ExternalLinkage, "_tip_main_undefined",
          CurrentModule.get());
      irBuilder.CreateCall(undef);
      irBuilder.CreateRet(zeroV);
    }

    // create global _tip_num_inputs with init of numTIPArgs
    tipNumInputs = new llvm::GlobalVariable(
        *CurrentModule, llvm::Type::getInt64Ty(llvmContext), true,
        llvm::GlobalValue::ExternalLinkage,
        llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvmContext), numTIPArgs),
        "_tip_num_inputs");

    // create global _tip_input_array with up to numTIPArgs of Int64
    auto *inputArrayType =
        llvm::ArrayType::get(llvm::Type::getInt64Ty(llvmContext), numTIPArgs);
    std::vector<llvm::Constant *> zeros(numTIPArgs, zeroV);
    tipInputArray = new llvm::GlobalVariable(
        *CurrentModule, inputArrayType, false, llvm::GlobalValue::CommonLinkage,
        llvm::ConstantArray::get(inputArrayType, zeros), "_tip_input_array");
  }

  // declare the calloc function
  // the calloc function takes in two ints: the number of items and the size of
  // the items
  std::vector<llvm::Type *> twoInt(2, llvm::Type::getInt64Ty(llvmContext));
  auto *FT = llvm::FunctionType::get(llvm::PointerType::get(llvmContext, 0),
                                     twoInt, false);
  callocFun = llvm::Function::Create(FT, llvm::Function::ExternalLinkage,
                                     "calloc", CurrentModule.get());
  callocFun->addFnAttr(llvm::Attribute::NoUnwind);

  callocFun->setAttributes(callocFun->getAttributes().addAttributeAtIndex(
      callocFun->getContext(), 0, llvm::Attribute::NoAlias));

  /* We create a single unified record structure that is capable of representing
   * all records in a TIP program.  While wasteful of memory, this approach is
   * compatible with the limited type checking provided for records in TIP.
   *
   * We refer to this single unified record structure as the "global record"
   */
  std::vector<llvm::Type *> member_values;
  int index = 0;
  for (const auto &field : semanticAnalysis->getSymbolTable()->getFields()) {
    member_values.push_back(llvm::IntegerType::getInt64Ty((llvmContext)));
    fieldVector.push_back(field);
    fieldIndex[field] = index;
    index++;
  }
  globalRecordType =
      llvm::StructType::create(llvmContext, member_values, "globalRecord");
  pointerToGlobalRecordType = llvm::PointerType::get(llvmContext, 0);

  // Code is generated into the module by the other routines
  for (auto const &fn : getFunctions()) {
    fn->codegen();
  }

  TheModule = std::move(CurrentModule);

  verifyModule(*TheModule);

  return TheModule;
}

llvm::Value *ASTFunction::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  llvm::Function *TheFunction = getFunction(getName());
  if (TheFunction == nullptr) {
    throw InternalError("failed to declare the function" + // LCOV_EXCL_LINE
                        getName());                        // LCOV_EXCL_LINE
  }

  // create basic block to hold body of function definition
  llvm::BasicBlock *BB =
      llvm::BasicBlock::Create(llvmContext, "entry", TheFunction);
  irBuilder.SetInsertPoint(BB);

  // keep scope separate from prior definitions
  namedValues.clear();

  /*
   * Add arguments to the symbol table
   *   - for main function, we initialize allocas with array loads
   *   - for other functions, we initialize allocas with the arg values
   */
  if (getName() == "main") {
    int argIdx = 0;
    // Note that the args are not in the LLVM function decl, so we use the AST
    // formals
    for (auto &argName : functionFormalNames[getName()]) {
      // Create an alloca for this argument and store its value
      llvm::AllocaInst *argAlloc = CreateEntryBlockAlloca(TheFunction, argName);

      // Emit the GEP instruction to index into input array
      std::vector<llvm::Value *> indices;
      indices.push_back(zeroV);
      indices.push_back(
          llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvmContext), argIdx));
      auto *gep = irBuilder.CreateInBoundsGEP(
          tipInputArray->getValueType(), tipInputArray, indices, "inputidx");

      // Load the value and store it into the arg's alloca
      auto *inVal =
          irBuilder.CreateLoad(llvm::Type::getInt64Ty(llvmContext), gep,
                               "tipinput" + std::to_string(argIdx++));

      irBuilder.CreateStore(inVal, argAlloc);

      // Record name binding to alloca
      namedValues[argName] = argAlloc;
    }
  } else {
    for (auto &arg : TheFunction->args()) {
      // Create an alloca for this argument and store its value
      llvm::AllocaInst *argAlloc =
          CreateEntryBlockAlloca(TheFunction, arg.getName().str());
      irBuilder.CreateStore(&arg, argAlloc);

      // Record name binding to alloca
      namedValues[arg.getName().str()] = argAlloc;
    }
  }

  // add local declarations to the symbol table
  for (auto const &decl : getDeclarations()) {
    if (decl->codegen() == nullptr) {
      TheFunction->eraseFromParent();                    // LCOV_EXCL_LINE
      throw InternalError(                               // LCOV_EXCL_LINE
          "failed to generate bitcode for the function " // LCOV_EXCL_LINE
          "declarations");                               // LCOV_EXCL_LINE
    }
  }

  for (auto &stmt : getStmts()) {
    if (stmt->codegen() == nullptr) {
      TheFunction->eraseFromParent();                    // LCOV_EXCL_LINE
      throw InternalError(                               // LCOV_EXCL_LINE
          "failed to generate bitcode for the function " // LCOV_EXCL_LINE
          "statement");                                  // LCOV_EXCL_LINE
    }
  }

  verifyFunction(*TheFunction);
  return TheFunction;
} // LCOV_EXCL_LINE

llvm::Value *ASTNumberExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  return llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvmContext),
                                getValue());
} // LCOV_EXCL_LINE

llvm::Value *ASTBinaryExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  llvm::Value *L = getLeft()->codegen();
  llvm::Value *R = getRight()->codegen();
  if (L == nullptr || R == nullptr) {
    throw InternalError("null binary operand");
  }

  if (getOp() == "+") {
    return irBuilder.CreateAdd(L, R, "addtmp");
  } else if (getOp() == "-") {
    return irBuilder.CreateSub(L, R, "subtmp");
  } else if (getOp() == "*") {
    return irBuilder.CreateMul(L, R, "multmp");
  } else if (getOp() == "/") {
    return irBuilder.CreateSDiv(L, R, "divtmp");
  } else if (getOp() == ">") {
    auto *cmp = irBuilder.CreateICmpSGT(L, R, "_gttmp");
    return irBuilder.CreateIntCast(
        cmp, llvm::IntegerType::getInt64Ty(llvmContext), false, "gttmp");
  } else if (getOp() == "==") {
    auto *cmp = irBuilder.CreateICmpEQ(L, R, "_eqtmp");
    return irBuilder.CreateIntCast(
        cmp, llvm::IntegerType::getInt64Ty(llvmContext), false, "eqtmp");
  } else if (getOp() == "!=") {
    auto *cmp = irBuilder.CreateICmpNE(L, R, "_neqtmp");
    return irBuilder.CreateIntCast(
        cmp, llvm::IntegerType::getInt64Ty(llvmContext), false, "neqtmp");
  }

  else if (getOp() == "and") {
    auto *cmp = irBuilder.CreateAnd(L, R, "_and");
    return irBuilder.CreateIntCast(
      cmp, llvm::IntegerType::getInt64Ty(llvmContext), false, "andtmp");
  } else if (getOp() == "or") { // bool
    auto *cmp = irBuilder.CreateOr(L, R, "_ortmp");
    return irBuilder.CreateIntCast(
      cmp, llvm::IntegerType::getInt64Ty(llvmContext),false, "ortmp");
  } else if (getOp() == ">=") { // bool
    auto *cmp = irBuilder.CreateICmpSGE(L, R, "_gtetmp");
    return irBuilder.CreateIntCast(
      cmp, llvm::IntegerType::getInt64Ty(llvmContext),false, "gtetmp");
  } else if (getOp() == "<") { // bool
    auto *cmp = irBuilder.CreateICmpSLT(L, R, "_lttmp");
    return irBuilder.CreateIntCast(cmp, llvm::IntegerType::getInt64Ty(llvmContext),
                                 false, "lttmp");
  } else if (getOp() == "<=") { // bool
    auto *cmp = irBuilder.CreateICmpSLE(L, R, "_ltetmp");
    return irBuilder.CreateIntCast(cmp, llvm::IntegerType::getInt64Ty(llvmContext),
                                 false, "ltetmp");
  } else if (getOp() == "%") { // Int
    return irBuilder.CreateSRem(L, R, "modtmp");
  }
  else {
    throw InternalError("Invalid binary operator: " + OP);
  }
}

/*
 * First lookup the variable in the symbol table for names and
 * if that fails, then look in the symbol table for functions.
 *
 * This relies on the fact that TIP programs have been checked to
 * ensure that names obey the scope rules.
 */
llvm::Value *ASTVariableExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  auto nv = namedValues.find(getName());
  if (nv != namedValues.end()) {
    if (lValueGen) {
      return namedValues[nv->first];
    } else {
      return irBuilder.CreateLoad(nv->second->getAllocatedType(), nv->second,
                                  getName().c_str());
    }
  }

  auto fidx = functionIndex.find(getName());
  if (fidx == functionIndex.end()) {
    throw InternalError("Unknown variable name: " + getName());
  }

  return llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvmContext),
                                fidx->second);
}

llvm::Value *ASTInputExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  if (inputIntrinsic == nullptr) {
    auto *FT =
        llvm::FunctionType::get(llvm::Type::getInt64Ty(llvmContext), false);
    inputIntrinsic = llvm::Function::Create(FT, llvm::Function::ExternalLinkage,
                                            "_tip_input", CurrentModule.get());
  }
  return irBuilder.CreateCall(inputIntrinsic);
} // LCOV_EXCL_LINE

/*
 * Function application in TIP can either be through explicitly named
 * functions or through expressions that evaluate to a function reference.
 * We consolidate these two cases by binding function names to values
 * and then using those values, which may flow through the program as function
 * references, to index into a function dispatch table to invoke the function.
 *
 * The function name values and table are set up in a shallow-pass over
 * functions performed during codegen for the Program.
 */
llvm::Value *ASTFunAppExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  /*
   * Evaluate the function expression - it will resolve to an integer value
   * whether it is a function literal or an expression.
   */
  auto *funVal = getFunction()->codegen();
  if (funVal == nullptr) {
    throw InternalError("failed to generate bitcode for the function");
  }

  /*
   * Emit the GEP instruction to compute the address of LLVM function
   * pointer to be called.
   */
  std::vector<llvm::Value *> indices;
  indices.push_back(zeroV);
  indices.push_back(funVal);

  auto *gep = irBuilder.CreateInBoundsGEP(
      tipFunctionTable->getValueType(), tipFunctionTable, indices, "ftableidx");

  // Load the function pointer
  auto *functionPointer = irBuilder.CreateLoad(
      llvm::PointerType::get(llvmContext, 0), gep, "genfptr");

  /*
   * All functions are pointer types and return INT64.
   *
   */
  std::vector<llvm::Type *> actualTypes(getActuals().size(),
                                        llvm::Type::getInt64Ty(llvmContext));
  auto *funType = llvm::FunctionType::get(llvm::Type::getInt64Ty(llvmContext),
                                          actualTypes, false);

  // Compute the actual parameters
  std::vector<llvm::Value *> argsV;
  for (auto const &arg : getActuals()) {
    llvm::Value *argVal = arg->codegen();
    if (argVal == nullptr) {
      throw InternalError(                                // LCOV_EXCL_LINE
          "failed to generate bitcode for the argument"); // LCOV_EXCL_LINE
    }
    argsV.push_back(argVal);
  }

  return irBuilder.CreateCall(funType, functionPointer, argsV, "calltmp");
}

/* 'alloc' Allocate expression
 * Generates a pointer to the allocs arguments (ints, records, ...)
 */
llvm::Value *ASTAllocExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  allocFlag = true;
  llvm::Value *argVal = getInitializer()->codegen();
  allocFlag = false;
  if (argVal == nullptr) {
    throw InternalError("failed to generate bitcode for the initializer of the "
                        "alloc expression");
  }

  // Allocate an int pointer with calloc
  std::vector<llvm::Value *> twoArg;
  twoArg.push_back(
      llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvmContext), 1));
  twoArg.push_back(
      llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvmContext), 8));
  auto *allocInst = irBuilder.CreateCall(callocFun, twoArg, "allocPtr");

  // Initialize with argument
  irBuilder.CreateStore(argVal, allocInst);

  return irBuilder.CreatePtrToInt(
      allocInst, llvm::Type::getInt64Ty(llvmContext), "allocIntVal");
}

llvm::Value *ASTNullExpr::codegen() {
  auto *nullPtr =
      llvm::ConstantPointerNull::get(llvm::PointerType::get(llvmContext, 0));
  return irBuilder.CreatePtrToInt(nullPtr, llvm::Type::getInt64Ty(llvmContext),
                                  "nullPtrIntVal");
}

/* '&' address of expression
 *
 * The argument must be capable of generating an l-value.
 * This is checked in the weeding pass.
 *
 */
llvm::Value *ASTRefExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  lValueGen = true;
  llvm::Value *lValue = getVar()->codegen();
  lValueGen = false;

  if (lValue == nullptr) {
    throw InternalError("could not generate l-value for address of");
  }

  return irBuilder.CreatePtrToInt(lValue, llvm::Type::getInt64Ty(llvmContext),
                                  "addrOfPtr");
} // LCOV_EXCL_LINE

/* '*' dereference expression
 *
 * The argument is assumed to be a reference expression, but
 * our code generation strategy stores everything as an integer.
 * Consequently, we convert the value with "inttoptr" before loading
 * the value at the pointed-to memory location.
 */
llvm::Value *ASTDeRefExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  bool isLValue = lValueGen;

  if (isLValue) {
    // This flag is reset here so that sub-expressions are treated as r-values
    lValueGen = false;
  }

  llvm::Value *argVal = getPtr()->codegen();
  if (argVal == nullptr) {
    throw InternalError("failed to generate bitcode for the pointer");
  }

  // compute the address
  llvm::Value *address = irBuilder.CreateIntToPtr(
      argVal, llvm::PointerType::get(llvmContext, 0), "ptrIntVal");

  if (isLValue) {
    // For an l-value, return the address
    return address;
  } else {
    // For an r-value, return the value at the address
    return irBuilder.CreateLoad(llvm::Type::getInt64Ty(llvmContext), address,
                                "valueAt");
  }
}

/* {field1 : val1, ..., fieldN : valN} record expression
 *
 * Builds an instance of the GlobalRecord using the declared fields
 */
llvm::Value *ASTRecordExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  // If this is an alloc, we calloc the record
  if (allocFlag) {
    // Allocate a pointer to an global record
    auto *allocaRecord = irBuilder.CreateAlloca(pointerToGlobalRecordType);

    // Use irBuilder to create the calloc call using pre-defined callocFun
    auto sizeOfGlobalRecord = CurrentModule->getDataLayout()
                                  .getStructLayout(globalRecordType)
                                  ->getSizeInBytes();
    std::vector<llvm::Value *> callocArgs;
    callocArgs.push_back(oneV);
    callocArgs.push_back(llvm::ConstantInt::get(
        llvm::Type::getInt64Ty(llvmContext), sizeOfGlobalRecord));
    auto *calloc = irBuilder.CreateCall(callocFun, callocArgs, "callocedPtr");

    // Bitcast the calloc call to theStruct Type
    auto recordPtr = calloc;

    // Store the ptr to the record in the record alloc
    irBuilder.CreateStore(recordPtr, allocaRecord);

    // Load allocaRecord
    auto loadInst =
        irBuilder.CreateLoad(pointerToGlobalRecordType, allocaRecord);

    // For each field, generate GEP for location of field in the globalRecord
    // Generate the code for the field and store it in the GEP
    for (auto const &field : getFields()) {
      auto *gep = irBuilder.CreateStructGEP(globalRecordType, loadInst,
                                            fieldIndex[field->getField()],
                                            field->getField());
      auto value = field->codegen();
      irBuilder.CreateStore(value, gep);
    }

    // Return int64 pointer to the pointer to the record
    return irBuilder.CreatePtrToInt(
        recordPtr, llvm::Type::getInt64Ty(llvmContext), "recordPtr");
  } else {
    // Allocate the space for a global record
    auto *allocaRecord = irBuilder.CreateAlloca(globalRecordType);

    // Codegen the fields present in this record and store them in the
    // appropriate location We do not give a value to fields that are not
    // explictly set. Thus, accessing them is undefined behavior
    for (auto const &field : getFields()) {
      auto *gep = irBuilder.CreateStructGEP(
          allocaRecord->getAllocatedType(), allocaRecord,
          fieldIndex[field->getField()], field->getField());
      auto value = field->codegen();
      irBuilder.CreateStore(value, gep);
    }
    // Return int64 pointer to the record since all variables are pointers to
    // ints
    return irBuilder.CreatePtrToInt(
        allocaRecord, llvm::Type::getInt64Ty(llvmContext), "record");
  }
}

/* field : val field expression
 *
 * Expression for generating the code for the value of a field
 */
llvm::Value *ASTFieldExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  return this->getInitializer()->codegen();
} // LCOV_EXCL_LINE

/* record.field Access Expression
 *
 * In an l-value context this returns the location of the field being accessed
 * In an r-value context this returns the value of the field being accessed
 */
llvm::Value *ASTAccessExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  bool isLValue = lValueGen;

  if (isLValue) {
    // This flag is reset here so that sub-expressions are treated as r-values
    lValueGen = false;
  }

  // Get current field and check if it exists
  auto currField = this->getField();
  if (fieldIndex.count(currField) == 0) {
    throw InternalError("This field doesn't exist");
  }

  // Generate record instruction address
  llvm::Value *recordVal = this->getRecord()->codegen();
  llvm::Value *recordAddress =
      irBuilder.CreateIntToPtr(recordVal, pointerToGlobalRecordType);

  // Generate the field index
  auto index = fieldIndex[currField];

  // Generate the location of the field
  auto *gep = irBuilder.CreateStructGEP(globalRecordType, recordAddress, index,
                                        currField);

  // If LHS, return location of field
  if (isLValue) {
    return gep;
  }

  // Load value at GEP and return it
  auto fieldLoad =
      irBuilder.CreateLoad(llvm::IntegerType::getInt64Ty(llvmContext), gep);
  return irBuilder.CreatePtrToInt(
      fieldLoad, llvm::Type::getInt64Ty(llvmContext), "fieldAccess");
}

llvm::Value *ASTDeclNode::codegen() {
  throw InternalError("Declarations do not emit code");
}

llvm::Value *ASTDeclStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  // The LLVM builder records the function we are currently generating
  llvm::Function *TheFunction = irBuilder.GetInsertBlock()->getParent();

  llvm::AllocaInst *localAlloca = nullptr;

  // Register all variables and emit their initializer.
  for (auto l : getVars()) {
    localAlloca = CreateEntryBlockAlloca(TheFunction, l->getName());

    // Initialize all locals to "0"
    irBuilder.CreateStore(zeroV, localAlloca);

    // Remember this binding.
    namedValues[l->getName()] = localAlloca;
  }

  // Return the body computation.
  return localAlloca;
} // LCOV_EXCL_LINE

llvm::Value *ASTAssignStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  // trigger code generation for l-value expressions
  lValueGen = true;
  llvm::Value *lValue = getLHS()->codegen();
  lValueGen = false;

  if (lValue == nullptr) {
    throw InternalError(
        "failed to generate bitcode for the lhs of the assignment");
  }

  llvm::Value *rValue = getRHS()->codegen();
  if (rValue == nullptr) {
    throw InternalError(
        "failed to generate bitcode for the rhs of the assignment");
  }

  return irBuilder.CreateStore(rValue, lValue);
} // LCOV_EXCL_LINE

llvm::Value *ASTBlockStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  llvm::Value *lastStmt = nullptr;

  for (auto const &s : getStmts()) {
    lastStmt = s->codegen();
  }

  // If the block was empty return a nop
  return (lastStmt == nullptr) ? irBuilder.CreateCall(nop) : lastStmt;
} // LCOV_EXCL_LINE

/*
 * The code generated for an WhileStmt looks like this:
 *
 *       <COND> == 0		this is called the "header" block
 *   true   /  ^  \   false
 *         v  /    \
 *      <BODY>     /
 *                /
 *               v
 *              nop        	this is called the "exit" block
 *
 * Much of the code involves setting up the different blocks, establishing
 * the insertion point, and then letting other codegen functions write
 * code at that insertion point.  A key difference is that the condition
 * is generated into a basic block since it will be branched to after the
 * body executes.
 */
llvm::Value *ASTWhileStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  llvm::Function *TheFunction = irBuilder.GetInsertBlock()->getParent();

  /*
   * Create blocks for the loop header, body, and exit; HeaderBB is first
   * so it is added to the function in the constructor.
   *
   * Blocks don't need to be contiguous or ordered in
   * any particular way because we will explicitly branch between them.
   * This can be optimized by later passes.
   */
  labelNum++; // create shared labels for these BBs

  llvm::BasicBlock *HeaderBB = llvm::BasicBlock::Create(
      llvmContext, "header" + std::to_string(labelNum), TheFunction);
  llvm::BasicBlock *BodyBB =
      llvm::BasicBlock::Create(llvmContext, "body" + std::to_string(labelNum));
  llvm::BasicBlock *ExitBB =
      llvm::BasicBlock::Create(llvmContext, "exit" + std::to_string(labelNum));

  // Add an explicit branch from the current BB to the header
  irBuilder.CreateBr(HeaderBB);

  // Emit loop header
  {
    irBuilder.SetInsertPoint(HeaderBB);

    llvm::Value *CondV = getCondition()->codegen();
    if (CondV == nullptr) {
      throw InternalError(                                   // LCOV_EXCL_LINE
          "failed to generate bitcode for the conditional"); // LCOV_EXCL_LINE
    }

    // Convert condition to a bool by comparing non-equal to 0.
    CondV = irBuilder.CreateICmpNE(
        CondV, llvm::ConstantInt::get(CondV->getType(), 0), "loopcond");

    irBuilder.CreateCondBr(CondV, BodyBB, ExitBB);
  }

  // Emit loop body
  {
    TheFunction->insert(TheFunction->end(), BodyBB);
    irBuilder.SetInsertPoint(BodyBB);

    llvm::Value *BodyV = getBody()->codegen();
    if (BodyV == nullptr) {
      throw InternalError(                                 // LCOV_EXCL_LINE
          "failed to generate bitcode for the loop body"); // LCOV_EXCL_LINE
    }

    irBuilder.CreateBr(HeaderBB);
  }

  // Emit loop exit block.
  TheFunction->insert(TheFunction->end(), ExitBB);
  irBuilder.SetInsertPoint(ExitBB);
  return irBuilder.CreateCall(nop);
} // LCOV_EXCL_LINE

/*
 * The code generated for an IfStmt looks like this:
 *
 *       <COND> == 0
 *   true   /     \   false
 *         v       v
 *      <THEN>   <ELSE>  if defined, otherwise use a nop
 *          \     /
 *           v   v
 *            nop        this is called the merge basic block
 *
 * Much of the code involves setting up the different blocks, establishing
 * the insertion point, and then letting other codegen functions write
 * code at that insertion point.
 */
llvm::Value *ASTIfStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  llvm::Value *CondV = getCondition()->codegen();
  if (CondV == nullptr) {
    throw InternalError(
        "failed to generate bitcode for the condition of the if statement");
  }

  // Convert condition to a bool by comparing non-equal to 0.
  CondV = irBuilder.CreateICmpNE(
      CondV, llvm::ConstantInt::get(CondV->getType(), 0), "ifcond");

  llvm::Function *TheFunction = irBuilder.GetInsertBlock()->getParent();

  /*
   * Create blocks for the then and else cases.  The then block is first, so
   * it is inserted in the function in the constructor. The rest of the blocks
   * need to be inserted explicitly into the functions basic block list
   * (via a push_back() call).
   *
   * Blocks don't need to be contiguous or ordered in
   * any particular way because we will explicitly branch between them.
   * This can be optimized to fall through behavior by later passes.
   */
  labelNum++; // create shared labels for these BBs
  llvm::BasicBlock *ThenBB = llvm::BasicBlock::Create(
      llvmContext, "then" + std::to_string(labelNum), TheFunction);
  llvm::BasicBlock *ElseBB =
      llvm::BasicBlock::Create(llvmContext, "else" + std::to_string(labelNum));
  llvm::BasicBlock *MergeBB = llvm::BasicBlock::Create(
      llvmContext, "ifmerge" + std::to_string(labelNum));

  irBuilder.CreateCondBr(CondV, ThenBB, ElseBB);

  // Emit then block.
  {
    irBuilder.SetInsertPoint(ThenBB);

    llvm::Value *ThenV = getThen()->codegen();
    if (ThenV == nullptr) {
      throw InternalError(                                  // LCOV_EXCL_LINE
          "failed to generate bitcode for the then block"); // LCOV_EXCL_LINE
    }

    irBuilder.CreateBr(MergeBB);
  }

  // Emit else block.
  {
    TheFunction->insert(TheFunction->end(), ElseBB);

    irBuilder.SetInsertPoint(ElseBB);

    // if there is no ELSE then exist emit a "nop"
    llvm::Value *ElseV;
    if (getElse() != nullptr) {
      ElseV = getElse()->codegen();
      if (ElseV == nullptr) {
        throw InternalError(                                  // LCOV_EXCL_LINE
            "failed to generate bitcode for the else block"); // LCOV_EXCL_LINE
      }
    } else {
      irBuilder.CreateCall(nop);
    }

    irBuilder.CreateBr(MergeBB);
  }

  // Emit merge block.
  TheFunction->insert(TheFunction->end(), MergeBB);
  irBuilder.SetInsertPoint(MergeBB);
  return irBuilder.CreateCall(nop);
} // LCOV_EXCL_LINE

llvm::Value *ASTOutputStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  if (outputIntrinsic == nullptr) {
    std::vector<llvm::Type *> oneInt(1, llvm::Type::getInt64Ty(llvmContext));
    auto *FT = llvm::FunctionType::get(llvm::Type::getInt64Ty(llvmContext),
                                       oneInt, false);
    outputIntrinsic =
        llvm::Function::Create(FT, llvm::Function::ExternalLinkage,
                               "_tip_output", CurrentModule.get());
  }

  llvm::Value *argVal = getArg()->codegen();
  if (argVal == nullptr) {
    throw InternalError(
        "failed to generate bitcode for the argument of the output statement");
  }

  std::vector<llvm::Value *> ArgsV(1, argVal);

  return irBuilder.CreateCall(outputIntrinsic, ArgsV);
}

llvm::Value *ASTErrorStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  if (errorIntrinsic == nullptr) {
    std::vector<llvm::Type *> oneInt(1, llvm::Type::getInt64Ty(llvmContext));
    auto *FT = llvm::FunctionType::get(llvm::Type::getInt64Ty(llvmContext),
                                       oneInt, false);
    errorIntrinsic = llvm::Function::Create(FT, llvm::Function::ExternalLinkage,
                                            "_tip_error", CurrentModule.get());
  }

  llvm::Value *argVal = getArg()->codegen();
  if (argVal == nullptr) {
    throw InternalError(
        "failed to generate bitcode for the argument of the error statement");
  }

  std::vector<llvm::Value *> ArgsV(1, argVal);

  return irBuilder.CreateCall(errorIntrinsic, ArgsV);
}

llvm::Value *ASTReturnStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  llvm::Value *argVal = getArg()->codegen();
  return irBuilder.CreateRet(argVal);
}

/*
  Generates LLVM code for creating an array
  - It retrieves the elements of the array and determines the size of the array.
  - Allocates memory for the array using 'calloc', with space for the array length plus the elements.
  - The first element of the allocated space is used to store the length of the array.
  - Iterates over the array elements, generating code for
     each element and storing them in the allocated array space.
  - The array elements start from the second position in the allocated space (index 1),
      as the first position (index 0) is reserved for the array length.
  - After storing all elements, it returns the pointer to the allocated array, cast to a 64-bit integer.
*/
llvm::Value *ASTArrayExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  auto elements = getElements();
  int loopSize = elements.size();
  Value* arrLen = ConstantInt::get(Type::getInt64Ty(llvmContext), loopSize);

  //Allocate an int pointer with calloc
  std::vector<Value *> twoArg;
  twoArg.push_back(ConstantInt::get(Type::getInt64Ty(llvmContext), loopSize+1));
  twoArg.push_back(ConstantInt::get(Type::getInt64Ty(llvmContext), 8));
  auto *allocInst = irBuilder.CreateCall(callocFun, twoArg, "allocPtr");
  auto *arrayPtr = irBuilder.CreatePointerCast(allocInst, Type::getInt64PtrTy(llvmContext), "arrayPtr");

  irBuilder.CreateStore(arrLen, arrayPtr);

  for (int i = 0; i < loopSize; i++) {
    Value* counter = ConstantInt::get(Type::getInt64Ty(llvmContext), i+1);
    Value* elementValue = ELEMENTS.at(i)->codegen();
    Value* gep = irBuilder.CreateGEP(Type::getInt64Ty(llvmContext), arrayPtr, counter, "elementPtr");
    irBuilder.CreateStore(elementValue, gep);
  }

  return arrayPtr;
}

/*
  Generates LLVM code for creating boolean expression
  - the following boolean convention is set as: "true" returns 1, "false" returns 0
 */
llvm::Value *ASTBooleanExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;
  if (getValue() == "true") {
    return oneV;
  } else if (getValue() == "false"){
    return zeroV;
  } else {
    throw InternalError("failed to generate bitcode for bool");
  }
}

/*
  Generates LLVM code for creating an ArrayOfExpr.
  - Allocates memory for the array using 'calloc', which is sized based on the size expression plus one.
  - The first element of the array is used to store its size.
  - Loop to initialize each value in array
  - Return a pointer to the array, cast to a 64-bit integer.
*/
llvm::Value *ASTArrayOfExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  // Generate code for the size and the value
  Value* sizeExpr = getFrequency()->codegen();
  if (sizeExpr == nullptr) {
    throw InternalError("Error generating code for array sizeExpr");
  }
  Value* sizeExprValue = irBuilder.CreateAdd(sizeExpr, oneV, "sizePlusOne");
  Value* valueExpr = getElement()->codegen();
  // Allocate memory for the array
  std::vector<llvm::Value*> callocArgs = {
    sizeExprValue, // Number of elements in the array
    llvm::ConstantInt::get(Type::getInt64Ty(llvmContext), 8) // Size of each element (8 bytes for int64)
  };
  auto *allocInst = irBuilder.CreateCall(callocFun, callocArgs, "allocPtr");
  auto *arrayPtr = irBuilder.CreatePointerCast(allocInst, Type::getInt64PtrTy(llvmContext), "arrayPtr");
  irBuilder.CreateStore(sizeExpr, arrayPtr);

  // Create a loop to initialize each element of the array with valueExpr
  Function* TheFunction = irBuilder.GetInsertBlock()->getParent();
  BasicBlock* preheaderBlock = irBuilder.GetInsertBlock();
  BasicBlock* loopBlock = BasicBlock::Create(llvmContext, "loop", TheFunction);
  BasicBlock* afterLoopBlock = BasicBlock::Create(llvmContext, "afterLoop", TheFunction);
  irBuilder.CreateBr(loopBlock);

  // Start insertion in loopBlock
  irBuilder.SetInsertPoint(loopBlock);

  // Create the PHI node for the loop variable, initialize with 1 to skip size storage
  llvm::PHINode* loopVar = irBuilder.CreatePHI(Type::getInt64Ty(llvmContext), 2);
  loopVar->addIncoming(ConstantInt::get(Type::getInt64Ty(llvmContext), 1), preheaderBlock);

  // Calculate the address for the current element in the array
  llvm::Value* elementPtr = irBuilder.CreateGEP(Type::getInt64Ty(llvmContext),arrayPtr, loopVar, "elementPtr");
  irBuilder.CreateStore(valueExpr, elementPtr);

  // Increment the loop variable
  llvm::Value* nextVal = irBuilder.CreateAdd(loopVar, oneV, "nextVal");
  loopVar->addIncoming(nextVal, loopBlock);

  // Create the end condition for the loop
  llvm::Value* endCond = irBuilder.CreateICmpEQ(nextVal, sizeExprValue, "loopcond");
  irBuilder.CreateCondBr(endCond, afterLoopBlock, loopBlock);

  // Insert the after loop block
  irBuilder.SetInsertPoint(afterLoopBlock);

  // The arrayPtr is a pointer to the first element of the array
  return irBuilder.CreatePtrToInt(arrayPtr, Type::getInt64Ty(llvmContext));

}
/*
  Generates the LLVM for accessing an element of an array
  - Generate Value for the array and the index expression.
  - Check for null values for the array and the index, throwing an error if any are null.
  - Convert the array's address to a pointer type for indexing.
  - Load the length of the array and performing bounds checking on the index to ensure it is within the valid range of the array.
      check if the index is negative or greater than or equal to the array length.
  - If out-of-bounds index, the function branches to an error handling block.
  - If the index is within bounds, the function calculates the address of the desired array element and either:
    - Returns a pointer to the array element.
    - Loads and returns the value of the array element.
*/
llvm::Value *ASTArrayRefExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  bool isLValue = lValueGen;

  if (isLValue) {
    // This flag is reset here so that sub-expressions are treated as r-values
    lValueGen = false;
  }
  // Get array
  llvm::Value *array = getArray()->codegen();
  if (array == nullptr) {
    throw InternalError("failed to generate bitcode for the array of the array access expression");
  }
  llvm::Value *arrayPtr = irBuilder.CreateIntToPtr(array, Type::getInt64PtrTy(llvmContext), "arrayPtr");

  // get array index
  llvm::Value *index = getIndex()->codegen();
  if (index == nullptr) {
    throw InternalError("failed to generate bitcode for the index of the array access expression");
  }

  // Array length
  llvm::Value *arrayLength = irBuilder.CreateLoad(Type::getInt64Ty(llvmContext), arrayPtr, "arrayLength");


  // Create Error Intrinsic
  if (errorIntrinsic == nullptr) {
    std::vector<Type *> oneInt(1, Type::getInt64Ty(llvmContext));
    auto *FT = FunctionType::get(Type::getInt64Ty(llvmContext), oneInt, false);
    errorIntrinsic = llvm::Function::Create(FT, llvm::Function::ExternalLinkage,
                                            "_tip_error", CurrentModule.get());
  }

  // Prepare basic blocks for branching
  Function* TheFunction = irBuilder.GetInsertBlock()->getParent();
  BasicBlock* ErrorBB = BasicBlock::Create(llvmContext, "error", TheFunction);
  BasicBlock* AccessBB = BasicBlock::Create(llvmContext, "access", TheFunction); // Corrected to AccessBB

  // Check index bounds
  llvm::Value *isIndexNegative = irBuilder.CreateICmpSLT(index, llvm::ConstantInt::get(llvmContext, llvm::APInt(64, 0)), "isneg");
  llvm::Value *isIndexOutOfBounds = irBuilder.CreateICmpSGE(index, arrayLength, "isoutofbounds");

  // Use logical OR to check if either bound condition is true, then branch to error.
  llvm::Value* indexOutOfBound = irBuilder.CreateOr(isIndexNegative, isIndexOutOfBounds, "indexOutOfBound");
  irBuilder.CreateCondBr(indexOutOfBound, ErrorBB, AccessBB);

  // Emit code for ErrorBB
  irBuilder.SetInsertPoint(ErrorBB);
  llvm::Value *error = irBuilder.CreateCall(errorIntrinsic, {index});
  // After calling the error function, the code will return
  irBuilder.CreateRet(error);

  // Emit code for the AccessBB
  irBuilder.SetInsertPoint(AccessBB);
  llvm::Value *idxPlusOne = irBuilder.CreateAdd(index, oneV, "idxPlusOne");
  llvm::Value *elemPtr = irBuilder.CreateInBoundsGEP(Type::getInt64Ty(llvmContext), arrayPtr, idxPlusOne, "elemPtr");

  lValueGen = isLValue;

  if (lValueGen) {
    // If it's an L-value, return the pointer to the element.
    llvm::Value *elemVal = irBuilder.CreateIntToPtr(elemPtr, Type::getInt64PtrTy(llvmContext), "elemPtr");
    return elemVal;
  } else {
    // If it's an R-value, load and return the element's value.
    return irBuilder.CreateLoad(Type::getInt64Ty(llvmContext), elemPtr, "loadElem");
  }
}

/*
 * The Increment statement will use CreateAdd to add +1 to the
 * expression found in the codegen.
 *
 * (++) -> EXPR + 1
 */
llvm::Value *ASTIncrementStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  lValueGen = true;
  Value *lValue = getExpr()->codegen();
  lValueGen = false;

  Value *rValue = getExpr()->codegen();
  Value *inc;

  inc = irBuilder.CreateAdd(rValue, oneV);

  return irBuilder.CreateStore(inc, lValue);
}

/*
 * The Decrement statement will use CreateSub to subtract 1 to the
 * expression found in the codegen.
 *
 * (--) -> EXPR - 1
 */
llvm::Value *ASTDecrementStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  lValueGen = true;
  Value *lValue = getExpr()->codegen();
  lValueGen = false;

  Value *rValue = getExpr()->codegen();
  Value *inc;

  inc = irBuilder.CreateSub(rValue, oneV);

  return irBuilder.CreateStore(inc, lValue);
}

/*
 * The code generated for an ForStmt looks like this:
 *       <INIT> initializes the array
 *          v
 *       <HEADER>
 *          /  ^  \ out of range
 *         v  /    \
 *      <BODY>     /
 *                /
 *               v
 *              nop        	this is called the "exit" block
 */
llvm::Value *ASTForStmt::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  llvm::Function *parentFunction = irBuilder.GetInsertBlock()->getParent();

  // for( x : arr)
  // Generate the iterator value (ITER)
  llvm::Value *iterVal = ITER->codegen();
  if (!iterVal) {
      throw InternalError("Failed to generate bitcode for iterator in ASTForStmt");
  }

  // Generate the loop element (ELEMENT) which will hold the current value of iteration
  lValueGen = true;
  llvm::Value *elementVar = ELEMENT->codegen();
  lValueGen = false;
  if (!elementVar) {
      throw InternalError("Failed to generate bitcode for loop element in ASTForStmt");
  }

  Value *ArrayPtr = irBuilder.CreateIntToPtr(iterVal, Type::getInt64PtrTy(llvmContext), "ArrayPtr");

  // Define basic blocks for the loop
  llvm::BasicBlock *loopHeader = llvm::BasicBlock::Create(llvmContext, "loopHeader", parentFunction);
  llvm::BasicBlock *loopBody = llvm::BasicBlock::Create(llvmContext, "loopBody", parentFunction);
  llvm::BasicBlock *loopExit = llvm::BasicBlock::Create(llvmContext, "loopExit", parentFunction);


  llvm::Value *currentIndexStack = CreateEntryBlockAlloca(parentFunction, "currentIndexStack");
  irBuilder.CreateStore(oneV, currentIndexStack);

  // Create a branch to the loop header
  irBuilder.CreateBr(loopHeader);
  // Generate the loop header
  irBuilder.SetInsertPoint(loopHeader);

  // Get the array size (stored at the start of the array)
  llvm::Value *arraySize = irBuilder.CreateLoad(llvm::Type::getInt64Ty(llvmContext), iterVal, "arraySize");

  llvm::Value *currentIndex = irBuilder.CreateLoad(Type::getInt64Ty(llvmContext), currentIndexStack, "currentIndex");
  // Compare current index with array size to check if we can continue iterating
  llvm::Value *cond = irBuilder.CreateICmpSLE(currentIndex, arraySize, "loopCond");
  irBuilder.CreateCondBr(cond, loopBody, loopExit);

  // Generate the loop body
  irBuilder.SetInsertPoint(loopBody);

  // Fetch the current element from the array (after the size)
  Value *ElemPtr = irBuilder.CreateGEP(Type::getInt64Ty(llvmContext), ArrayPtr, {currentIndex}, "ElemPtr");
  Value *LoadElement = irBuilder.CreateLoad(Type::getInt64Ty(llvmContext), ElemPtr, "LoadElement");
  irBuilder.CreateStore(LoadElement, elementVar);

  // Codegen the body of the loop
  llvm::Value *bodyVal = BODY->codegen();
  if (!bodyVal) {
      throw InternalError("Failed to generate bitcode for the loop body in ASTForStmt");
  }

  // Increment the current index (move to the next element in the array)
  llvm::Value *nextIndex = irBuilder.CreateAdd(currentIndex, llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvmContext), 1), "nextIndex");
  irBuilder.CreateStore(nextIndex, currentIndexStack);

  // Branch back to the loop header
  irBuilder.CreateBr(loopHeader);

  // Generate the loop exit
  irBuilder.SetInsertPoint(loopExit);

  // Return a nop instruction
  return irBuilder.CreateCall(nop);
}

/*
 * The code generated for an forRangeStmt looks like this:
 *        <INIT>           this is executed only once
 *           v
 *          <TEST>
 *   true   /  ^  \   false
 *         v   |   v
 *      <BODY> /  nop      this is called the "exit" block
 *         v  v
 *      <UPDATE>
 */
llvm::Value *ASTForRangeStmt::codegen() {
    LOG_S(1) << "Generating code for ASTForRangeStmt";

    llvm::Function *parentFunction = irBuilder.GetInsertBlock()->getParent();

    // Generate code for start and end expressions
    llvm::Value *startVal = START->codegen();
    llvm::Value *endVal = END->codegen();
    if (!startVal || !endVal) {
        throw InternalError("Failed to generate bitcode for range start or end in ASTForRangeStmt");
    }

    // Ensure the start and end values are integers
    startVal = irBuilder.CreateIntCast(startVal, llvm::Type::getInt64Ty(llvmContext), false, "startInt");
    endVal = irBuilder.CreateIntCast(endVal, llvm::Type::getInt64Ty(llvmContext), false, "endInt");

    // Generate the increment value if provided, otherwise default to 1
    llvm::Value *incrementVal = nullptr;
    if (INCREMENT) {
        incrementVal = INCREMENT->codegen();
        if (!incrementVal) {
            throw InternalError("Failed to generate bitcode for increment value in ASTForRangeStmt");
        }
        incrementVal = irBuilder.CreateIntCast(incrementVal, llvm::Type::getInt64Ty(llvmContext), false, "incInt");
    } else {
        incrementVal = llvm::ConstantInt::get(llvm::Type::getInt64Ty(llvmContext), 1, "defaultInc");
    }

    lValueGen = true;
    llvm::Value *elementVar = ELEMENT->codegen();
    lValueGen = false;
    if (!elementVar) {
      throw InternalError("Failed to generate bitcode for loop element in ASTForStmt");
    }

    llvm::Value *currentIndexStack = CreateEntryBlockAlloca(parentFunction, "currentIndexStack");
    irBuilder.CreateStore(oneV, currentIndexStack);

    // Create basic blocks for the loop
    llvm::BasicBlock *loopHeader = llvm::BasicBlock::Create(llvmContext, "loopHeader", parentFunction);
    llvm::BasicBlock *loopBody = llvm::BasicBlock::Create(llvmContext, "loopBody", parentFunction);
    llvm::BasicBlock *loopExit = llvm::BasicBlock::Create(llvmContext, "loopExit", parentFunction);

    // Initial branch to the loop header
    irBuilder.CreateBr(loopHeader);

    // Generate the loop header
    irBuilder.SetInsertPoint(loopHeader);
    llvm::Value *currentIndex = irBuilder.CreateLoad(Type::getInt64Ty(llvmContext), currentIndexStack, "currentIndex");
    llvm::Value *cond = irBuilder.CreateICmpSLT(currentIndex, endVal, "loopCond");
    irBuilder.CreateCondBr(cond, loopBody, loopExit);

    // Generate the loop body
    irBuilder.SetInsertPoint(loopBody);

    irBuilder.CreateStore(currentIndex, elementVar);


    llvm::Value *bodyVal = BODY->codegen();
    if (!bodyVal) {
        throw InternalError("Failed to generate bitcode for the loop body in ASTForRangeStmt");
    }

    // Increment the loop variable
    llvm::Value *nextVal = irBuilder.CreateAdd(currentIndex, incrementVal, "nextVal");
    irBuilder.CreateStore(nextVal, currentIndexStack);

    // Branch back to the loop header
    irBuilder.CreateBr(loopHeader);

    // Generate the loop exit
    irBuilder.SetInsertPoint(loopExit);

    // Return a nop instruction
    return irBuilder.CreateCall(nop);
}

llvm::Value *ASTUnaryExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  Value *R = getExpr()->codegen();
  if (R == nullptr) {
    throw InternalError("null unary operand");
  }

  // Arithmetic Negation Operator
  if (getOp() == "-") {
    return irBuilder.CreateNeg(R, "arinegtmp");
    // Logical Negation Operator
  } else if (getOp() == "not") {
    auto *cmp = irBuilder.CreateICmpEQ(R, zeroV);
    return irBuilder.CreateIntCast(cmp, IntegerType::getInt64Ty(llvmContext),
                                 false, "lognegtmp");
    // Array Length Operator
  } else if (getOp() == "#") {
    llvm::Value *array = getExpr()->codegen();
    // Load addr of array from its memory home
    Value *arrayAddr = irBuilder.CreateIntToPtr(array, Type::getInt64PtrTy(llvmContext), "arrayAddr");

    // Load 'arrayAddr' where the first element is the length
    llvm::Value *arrayLength = irBuilder.CreateLoad(Type::getInt64Ty(llvmContext), arrayAddr, "arrayLength");

    return arrayLength;

  } else {
    throw InternalError("Invalid unary operator: " + OP);
  }
}

/*
 * The code generated for ternary expression looks like this:
 *
 *       <COND> == 0
 *   true   /     \   false
 *         v       v
 *       <IF>   <ELSE>  if defined, otherwise use a nop
 *          \     /
 *           v   v
 *            nop        this is called the merge basic block
 */
llvm::Value *ASTTernaryExpr::codegen() {
  LOG_S(1) << "Generating code for " << *this;

  Value *CondV = getCondition()->codegen();
  if (CondV == nullptr) {
    throw InternalError(                                   // LCOV_EXCL_LINE
    "failed to generate bitcode for the conditional expression"); // LCOV_EXCL_LINE
  }

  // Convert condition to a bool by comparing non-equal to 0.
  CondV = irBuilder.CreateICmpNE(CondV, ConstantInt::get(CondV->getType(), 0), "ternarycond");

  Value *ThenV = getThen()->codegen();
  if (ThenV == nullptr) {
    throw InternalError(                                   // LCOV_EXCL_LINE
    "failed to generate bitcode for the then expression"); // LCOV_EXCL_LINE
  }
  Value *ElseV = getElse()->codegen();
  if (ElseV == nullptr) {
    throw InternalError(                                   // LCOV_EXCL_LINE
    "failed to generate bitcode for the else expression"); // LCOV_EXCL_LINE
  }

  return irBuilder.CreateSelect(CondV, ThenV, ElseV);
}