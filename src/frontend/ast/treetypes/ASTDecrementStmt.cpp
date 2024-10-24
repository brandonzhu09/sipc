#include "ASTDecrementStmt.h"
#include "ASTVisitor.h"

void ASTDecrementStmt::accept(ASTVisitor *visitor) {
    if (visitor->visit(this)) {
        getExpr()->accept(visitor);
    }
    visitor->endVisit(this);
}

std::ostream &ASTDecrementStmt::print(std::ostream &out) const {
    out << *getExpr() << "--" << ";";
    return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTDecrementStmt::getChildren() {
    std::vector<std::shared_ptr<ASTNode>> children;
    children.push_back(EXPR);
    return children;
}
