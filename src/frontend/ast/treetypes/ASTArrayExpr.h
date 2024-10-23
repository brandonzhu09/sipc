#pragma once

#include "ASTExpr.h"

/*! \brief Class for defining an array.
 */
class ASTArrayExpr : public ASTExpr {
    std::vector<std::shared_ptr<ASTExpr>> ELEMENTS;

public:
    std::vector<std::shared_ptr<ASTNode>> getChildren() override;
    ASTArrayExpr(std::vector<std::shared_ptr<ASTExpr>> ELEMENTS);
    std::vector<ASTExpr *> getElements() const;
    void accept(ASTVisitor *visitor) override;
    llvm::Value *codegen() override;

protected:
    std::ostream &print(std::ostream &out) const override;
};

