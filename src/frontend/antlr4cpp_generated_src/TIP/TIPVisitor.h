
// Generated from TIP.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "TIPParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by TIPParser.
 */
class  TIPVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TIPParser.
   */
    virtual std::any visitProgram(TIPParser::ProgramContext *context) = 0;

    virtual std::any visitFunction(TIPParser::FunctionContext *context) = 0;

    virtual std::any visitDeclaration(TIPParser::DeclarationContext *context) = 0;

    virtual std::any visitNameDeclaration(TIPParser::NameDeclarationContext *context) = 0;

    virtual std::any visitArrayOfConstructor(TIPParser::ArrayOfConstructorContext *context) = 0;

    virtual std::any visitArrayRefExpr(TIPParser::ArrayRefExprContext *context) = 0;

    virtual std::any visitArrayPrefixLength(TIPParser::ArrayPrefixLengthContext *context) = 0;

    virtual std::any visitNullExpr(TIPParser::NullExprContext *context) = 0;

    virtual std::any visitTrueExpr(TIPParser::TrueExprContext *context) = 0;

    virtual std::any visitAllocExpr(TIPParser::AllocExprContext *context) = 0;

    virtual std::any visitAdditiveExpr(TIPParser::AdditiveExprContext *context) = 0;

    virtual std::any visitDeRefExpr(TIPParser::DeRefExprContext *context) = 0;

    virtual std::any visitParenExpr(TIPParser::ParenExprContext *context) = 0;

    virtual std::any visitTernaryExpr(TIPParser::TernaryExprContext *context) = 0;

    virtual std::any visitFalseExpr(TIPParser::FalseExprContext *context) = 0;

    virtual std::any visitFunAppExpr(TIPParser::FunAppExprContext *context) = 0;

    virtual std::any visitAccessExpr(TIPParser::AccessExprContext *context) = 0;

    virtual std::any visitRecordRule(TIPParser::RecordRuleContext *context) = 0;

    virtual std::any visitNegNumber(TIPParser::NegNumberContext *context) = 0;

    virtual std::any visitInputExpr(TIPParser::InputExprContext *context) = 0;

    virtual std::any visitRelationalExpr(TIPParser::RelationalExprContext *context) = 0;

    virtual std::any visitNumExpr(TIPParser::NumExprContext *context) = 0;

    virtual std::any visitVarExpr(TIPParser::VarExprContext *context) = 0;

    virtual std::any visitNotExpr(TIPParser::NotExprContext *context) = 0;

    virtual std::any visitArrayConstructor(TIPParser::ArrayConstructorContext *context) = 0;

    virtual std::any visitNegExpr(TIPParser::NegExprContext *context) = 0;

    virtual std::any visitRefExpr(TIPParser::RefExprContext *context) = 0;

    virtual std::any visitAndOrExpr(TIPParser::AndOrExprContext *context) = 0;

    virtual std::any visitMultiplicativeExpr(TIPParser::MultiplicativeExprContext *context) = 0;

    virtual std::any visitEqualityExpr(TIPParser::EqualityExprContext *context) = 0;

    virtual std::any visitRecordExpr(TIPParser::RecordExprContext *context) = 0;

    virtual std::any visitFieldExpr(TIPParser::FieldExprContext *context) = 0;

    virtual std::any visitStatement(TIPParser::StatementContext *context) = 0;

    virtual std::any visitAssignStmt(TIPParser::AssignStmtContext *context) = 0;

    virtual std::any visitBlockStmt(TIPParser::BlockStmtContext *context) = 0;

    virtual std::any visitWhileStmt(TIPParser::WhileStmtContext *context) = 0;

    virtual std::any visitIfStmt(TIPParser::IfStmtContext *context) = 0;

    virtual std::any visitOutputStmt(TIPParser::OutputStmtContext *context) = 0;

    virtual std::any visitErrorStmt(TIPParser::ErrorStmtContext *context) = 0;

    virtual std::any visitReturnStmt(TIPParser::ReturnStmtContext *context) = 0;

    virtual std::any visitForStmt(TIPParser::ForStmtContext *context) = 0;

    virtual std::any visitForRangeStmt(TIPParser::ForRangeStmtContext *context) = 0;

    virtual std::any visitIncrementStmt(TIPParser::IncrementStmtContext *context) = 0;

    virtual std::any visitDecrementStmt(TIPParser::DecrementStmtContext *context) = 0;


};

