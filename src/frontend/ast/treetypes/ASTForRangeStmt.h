#pragma once

#include "ASTExpr.h"
#include "ASTStmt.h"

/*! \brief Class for a for iterative loop.
 */
class ASTForRangeStmt : public ASTStmt {
    std::shared_ptr<ASTExpr> ELEMENT;
    std::shared_ptr<ASTExpr> START;
    std::shared_ptr<ASTExpr> END;
    std::shared_ptr<ASTExpr> INCREMENT = std::make_shared<ASTExpr>(1);
    std::shared_ptr<ASTStmt> BODY;

public:
    std::vector<std::shared_ptr<ASTNode>> getChildren() override;
    ASTForStmt(std::shared_ptr<ASTExpr> ELEMENT, std::shared_ptr<ASTExpr> START, std::shared_ptr<ASTExpr> END, std::shared_ptr<ASTExpr> INCREMENT, std::shared_ptr<ASTStmt> BODY)
        : ELEMENT(ELEMENT), START(START), END(END), INCREMENT(INCREMENT), BODY(BODY) {}
    ASTExpr *getElement() const { return ELEMENT.get(); }
    ASTExpr *getStart() const { return START.get(); }
    ASTExpr *getEnd() const { return END.get(); }
    ASTExpr *getIncrement() const { return INCREMENT.get(); }
    ASTStmt *getBody() const { return BODY.get(); }
    void accept(ASTVisitor *visitor) override;
    llvm::Value *codegen() override;

protected:
    std::ostream &print(std::ostream &out) const override;
};
