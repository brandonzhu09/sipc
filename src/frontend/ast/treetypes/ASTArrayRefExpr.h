#pragma once

#include "ASTExpr.h"

/*! \brief Class for referencing the address of an expression.
 */
class ASTArrayRefExpr : public ASTExpr {
    std::shared_ptr<ASTExpr> ARRAY;
    std::shared_ptr<ASTExpr> INDEX;

public:
    std::vector<std::shared_ptr<ASTNode>> getChildren() override;
    ASTArrayRefExpr(std::shared_ptr<ASTExpr> ARRAY) : ARRAY(ARRAY) {}
    ASTArrayRefExpr(std::shared_ptr<ASTExpr> INDEX) : INDEX(INDEX) {}
    ASTExpr *getArray() const { return ARRAY.get(); }
    ASTExpr *getIndex() const { return INDEX.get(); }
    void accept(ASTVisitor *visitor) override;
    llvm::Value *codegen() override;

protected:
    std::ostream &print(std::ostream &out) const override;
};
