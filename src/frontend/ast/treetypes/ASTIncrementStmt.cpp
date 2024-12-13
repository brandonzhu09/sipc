#include "ASTIncrementStmt.h"
#include "ASTVisitor.h"

void ASTIncrementStmt::accept(ASTVisitor *visitor) {
    if (visitor->visit(this)) {
        getExpr()->accept(visitor);
    }
    visitor->endVisit(this);
}

std::ostream &ASTIncrementStmt::print(std::ostream &out) const {
    out << *getExpr() << "++" << ";";
    return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTIncrementStmt::getChildren() {
    std::vector<std::shared_ptr<ASTNode>> children;
    children.push_back(EXPR);
    return children;
}
