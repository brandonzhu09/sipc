#pragma once

#include "ASTExpr.h"

/*! \brief Class for defining an array.
 */
class ASTArrayOfExpr : public ASTExpr {
    std::shared_ptr<ASTExpr> FREQUENCY, ELEMENT;

public:
    std::vector<std::shared_ptr<ASTNode>> getChildren() override;
    ASTArrayOfExpr(std::shared_ptr<ASTExpr> FREQUENCY, std::shared_ptr<ASTExpr> ELEMENT)
        : FREQUENCY(FREQUENCY), ELEMENT(ELEMENT) {}
    ASTExpr *getFrequency() const { return FREQUENCY.get(); }
    ASTExpr *getElement() const { return ELEMENT.get(); }
    void accept(ASTVisitor *visitor) override;
    llvm::Value *codegen() override;

protected:
    std::ostream &print(std::ostream &out) const override;
};

