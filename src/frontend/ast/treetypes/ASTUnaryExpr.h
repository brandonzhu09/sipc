#pragma once

#include "ASTExpr.h"

/*! \brief Class for applying unary not operator on an expression
 */
class ASTUnaryExpr : public ASTExpr {
    std::string OP;
    std::shared_ptr<ASTExpr> EXPR;

public:
    std::vector<std::shared_ptr<ASTNode>> getChildren() override;
    ASTUnaryExpr(std::string OP, std::shared_ptr<ASTExpr> EXPR) : OP(OP), EXPR(EXPR) {}
    std::string getOp() const { return OP; }
    ASTExpr *getExpr() const { return EXPR.get(); }
    void accept(ASTVisitor *visitor) override;
    llvm::Value *codegen() override;

protected:
    std::ostream &print(std::ostream &out) const override;
};
