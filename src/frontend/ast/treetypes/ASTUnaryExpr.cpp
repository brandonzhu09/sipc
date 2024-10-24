#include "ASTUnaryExpr.h"
#include "ASTVisitor.h"

void ASTUnaryExpr::accept(ASTVisitor *visitor) {
    if (visitor->visit(this)) {
        getExpr()->accept(visitor);
    }
    visitor->endVisit(this);
}

std::ostream &ASTUnaryExpr::print(std::ostream &out) const {
    out << "not " << *getExpr();
    return out;
}

std::vector<std::shared_ptr<ASTNode> > ASTUnaryExpr::getChildren() {
    std::vector<std::shared_ptr<ASTNode> > children;
    children.push_back(EXPR);
    return children;
}
