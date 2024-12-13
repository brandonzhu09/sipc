#include "ASTForStmt.h"
#include "ASTVisitor.h"

void ASTForStmt::accept(ASTVisitor *visitor) {
    if (visitor->visit(this)) {
        getElement()->accept(visitor);
        getIter()->accept(visitor);
        getBody()->accept(visitor);
    }
    visitor->endVisit(this);
}

std::ostream &ASTForStmt::print(std::ostream &out) const {
    out << "for (" << *getElement() << " : " << *getIter() << ") " << *getBody();
    return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTForStmt::getChildren() {
    std::vector<std::shared_ptr<ASTNode>> children;
    children.push_back(ELEMENT);
    children.push_back(ITER);
    children.push_back(BODY);
    return children;
}
