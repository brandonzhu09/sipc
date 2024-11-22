
// Generated from TIP.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "TIPVisitor.h"


/**
 * This class provides an empty implementation of TIPVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TIPBaseVisitor : public TIPVisitor {
public:

  virtual std::any visitProgram(TIPParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(TIPParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeclaration(TIPParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNameDeclaration(TIPParser::NameDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayOfConstructor(TIPParser::ArrayOfConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayRefExpr(TIPParser::ArrayRefExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayPrefixLength(TIPParser::ArrayPrefixLengthContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullExpr(TIPParser::NullExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrueExpr(TIPParser::TrueExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAllocExpr(TIPParser::AllocExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditiveExpr(TIPParser::AdditiveExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeRefExpr(TIPParser::DeRefExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenExpr(TIPParser::ParenExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTernaryExpr(TIPParser::TernaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFalseExpr(TIPParser::FalseExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunAppExpr(TIPParser::FunAppExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAccessExpr(TIPParser::AccessExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordRule(TIPParser::RecordRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNegNumber(TIPParser::NegNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInputExpr(TIPParser::InputExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationalExpr(TIPParser::RelationalExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumExpr(TIPParser::NumExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarExpr(TIPParser::VarExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpr(TIPParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayConstructor(TIPParser::ArrayConstructorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNegExpr(TIPParser::NegExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRefExpr(TIPParser::RefExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndOrExpr(TIPParser::AndOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicativeExpr(TIPParser::MultiplicativeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualityExpr(TIPParser::EqualityExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRecordExpr(TIPParser::RecordExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFieldExpr(TIPParser::FieldExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(TIPParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignStmt(TIPParser::AssignStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockStmt(TIPParser::BlockStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(TIPParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(TIPParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOutputStmt(TIPParser::OutputStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitErrorStmt(TIPParser::ErrorStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStmt(TIPParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStmt(TIPParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForRangeStmt(TIPParser::ForRangeStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIncrementStmt(TIPParser::IncrementStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecrementStmt(TIPParser::DecrementStmtContext *ctx) override {
    return visitChildren(ctx);
  }


};

