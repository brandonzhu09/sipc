#pragma once

#include "ASTExpr.h"
#include "ASTStmt.h"

/*! \brief Class for a for iterative loop.
 */
class ASTForStmt : public ASTStmt {
    std::shared_ptr<ASTExpr> ELEMENT;
    std::shared_ptr<ASTExpr> ITER;
    std::shared_ptr<ASTStmt> BODY;

public:
    std::vector<std::shared_ptr<ASTNode>> getChildren() override;
    ASTForStmt(std::shared_ptr<ASTExpr> ELEMENT, std::shared_ptr<ASTExpr> ITER, std::shared_ptr<ASTStmt> BODY)
        : ELEMENT(ELEMENT), ITER(ITER), BODY(BODY) {}
    ASTExpr *getElement() const { return ELEMENT.get(); }
    ASTExpr *getIter() const { return ITER.get(); }
    ASTStmt *getBody() const { return BODY.get(); }
    void accept(ASTVisitor *visitor) override;
    llvm::Value *codegen() override;

protected:
    std::ostream &print(std::ostream &out) const override;
};
