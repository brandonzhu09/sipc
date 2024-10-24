#pragma once

#include "ASTExpr.h"
#include "ASTStmt.h"

/*! \brief Class for an increment statement.
 */
class ASTDecrementStmt : public ASTStmt {
    std::shared_ptr<ASTExpr> EXPR;

public:
    std::vector<std::shared_ptr<ASTNode>> getChildren() override;
    ASTDecrementStmt(std::shared_ptr<ASTExpr> EXPR) : EXPR(EXPR) {}
    ASTExpr *getExpr() const { return EXPR.get(); }
    void accept(ASTVisitor *visitor) override;
    llvm::Value *codegen() override;

protected:
    std::ostream &print(std::ostream &out) const override;
};

