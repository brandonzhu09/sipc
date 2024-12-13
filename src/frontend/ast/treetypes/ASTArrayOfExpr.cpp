#include "ASTArrayOfExpr.h"
#include "ASTVisitor.h"

void ASTArrayOfExpr::accept(ASTVisitor *visitor) {
    if (visitor->visit(this)) {
        getFrequency()->accept(visitor);
        getElement()->accept(visitor);
    }
    visitor->endVisit(this);
}

std::ostream &ASTArrayOfExpr::print(std::ostream &out) const {
    out << "[" << *getFrequency() << " of " << *getElement() << "]";
    return out;
} // LCOV_EXCL_LINE

std::vector<std::shared_ptr<ASTNode>> ASTArrayOfExpr::getChildren() {
    std::vector<std::shared_ptr<ASTNode>> children;
    children.push_back(FREQUENCY);
    children.push_back(ELEMENT);
    return children;
}
