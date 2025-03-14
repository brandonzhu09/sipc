#include "Optimizer.h"

#include "llvm/Passes/PassBuilder.h"

#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Transforms/Scalar/Reassociate.h"
#include "llvm/Transforms/Scalar/SimplifyCFG.h"
#include "llvm/Transforms/Scalar/Sink.h"

#include "llvm/Transforms/Utils/Mem2Reg.h"

#include "loguru.hpp"

#include <iostream>

// P5 passes
#include "llvm/Transforms/Scalar/LICM.h"

// New optimizations
#include "llvm/Transforms/Scalar/SimpleLoopUnswitch.h"
#include "llvm/Transforms/Utils/LoopSimplify.h"
#include "llvm/Transforms/Scalar/LoopUnrollPass.h"
#include "llvm/Transforms/Scalar/TailRecursionElimination.h"

#include "llvm/Transforms/IPO/MergeFunctions.h"
#include "llvm/Transforms/Scalar/ADCE.h"
#include "llvm/Transforms/Scalar/EarlyCSE.h"
#include "llvm/Transforms/IPO/Inliner.h"
#include "llvm/Transforms/IPO/SCCP.h"
#include "llvm/Transforms/Scalar/IndVarSimplify.h"

#include "llvm/Transforms/Scalar/DeadStoreElimination.h"
#include "llvm/Transforms/IPO/GlobalDCE.h"

#include "llvm/Transforms/IPO/DeadArgumentElimination.h"
#include "llvm/Transforms/Scalar/LICM.h"

namespace { // Anonymous namespace for local function

bool contains(Optimization o, llvm::cl::list<Optimization> &l) {
  for (unsigned i = 0; i != l.size(); ++i) {
    if (o == l[i]) return true;
  }
  return false;
}

}

//  Minimal optimization pass using LLVM pass managers
void Optimizer::optimize(llvm::Module *theModule, llvm::cl::list<Optimization> &enabledOpts) {
  LOG_S(1) << "Optimizing program " << theModule->getName().str();

  // New pass builder
  llvm::PassBuilder passBuilder;

  // Setting-up Analysis Managers for different granularities of optimizations
  llvm::FunctionAnalysisManager functionAnalysisManager;
  llvm::ModuleAnalysisManager moduleAnalysisManager;
  llvm::LoopAnalysisManager loopAnalysisManager;
  llvm::CGSCCAnalysisManager cgsccAnalysisManager;

  // Registering the analysis managers with the pass builder
  passBuilder.registerModuleAnalyses(moduleAnalysisManager);
  passBuilder.registerCGSCCAnalyses(cgsccAnalysisManager);
  passBuilder.registerFunctionAnalyses(functionAnalysisManager);
  passBuilder.registerLoopAnalyses(loopAnalysisManager);

  // Cross Register Proxies so that analysis results can be reused as needed.
  passBuilder.crossRegisterProxies(loopAnalysisManager, functionAnalysisManager,
                                   cgsccAnalysisManager, moduleAnalysisManager);

  // Initiating Function and Module level PassManagers
  llvm::ModulePassManager modulePassManager;
  llvm::FunctionPassManager functionPassManager;
  llvm::LoopPassManager loopPassManager;

  llvm::LICMOptions options;

  // Adding passes to the pipeline

  // Constructs SSA and is a pre-requisite for many other passes
  functionPassManager.addPass(llvm::PromotePass());

  functionPassManager.addPass(llvm::InstCombinePass());

  // Reassociate expressions.
  functionPassManager.addPass(llvm::ReassociatePass());

  // Eliminate Common SubExpressions using the Global Value Numbering (GVN) algorithm.
  functionPassManager.addPass(llvm::GVNPass());

  // Simplify the control flow graph (deleting unreachable blocks, etc).
  functionPassManager.addPass(llvm::SimplifyCFGPass());

  // (Aggressive) Dead Code Elimination (ADCE): Removes code that does not affect the program's observable behavior.
  if (contains(dce, enabledOpts)) {
    functionPassManager.addPass(llvm::ADCEPass());
  }

  // Sparse Conditional Constant Propagation
  if (contains(sccp, enabledOpts)) {
    modulePassManager.addPass(llvm::IPSCCPPass());
  }

  // Loop Unrolling: Expands the loop body multiple times,
  // reducing the loop overhead and increasing parallelism.
  if (contains(lu, enabledOpts)) {
    loopPassManager.addPass(llvm::LICMPass(options));
    functionPassManager.addPass(llvm::LoopUnrollPass());
//    functionPassManager.addPass(llvm::GVNSinkPass());
//
//    functionPassManager.addPass(llvm::SinkingPass());
  }

  // Tail Call Elimination Pass
  if (contains(tce, enabledOpts)) {
    loopPassManager.addPass(llvm::LICMPass(options));
    functionPassManager.addPass(llvm::TailCallElimPass());
  }

  // Inline pass
  if (contains(ilp, enabledOpts)) {
    modulePassManager.addPass(llvm::ModuleInlinerPass());
  }

  // Passing the function pass manager to the modulePassManager using a function
  // adaptor, then passing theModule to the ModulePassManager along with
  // ModuleAnalysisManager.
  modulePassManager.addPass(
      createModuleToFunctionPassAdaptor(std::move(functionPassManager)));
  modulePassManager.run(*theModule, moduleAnalysisManager);
}
