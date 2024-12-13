#include "ASTForRangeStmt.h"
#include "ASTVisitor.h"

void ASTForRangeStmt::accept(ASTVisitor *visitor) {
    if (visitor->visit(this)) {
        getElement()->accept(visitor);
        getStart()->accept(visitor);
        getEnd()->accept(visitor);
        if (getIncrement() != nullptr) {
            getIncrement()->accept(visitor);
        }
        getBody()->accept(visitor);
    }
    visitor->endVisit(this);
}

std::ostream &ASTForRangeStmt::print(std::ostream &out) const {
    out << "for (" << *getElement() << " : " << *getStart() << " .. " << *getEnd();
    if (getIncrement() != nullptr) {
        out << " by " << *getIncrement();
    }
    out << ") " << *getBody();
    return out;
}

std::vector<std::shared_ptr<ASTNode>> ASTForRangeStmt::getChildren() {
    std::vector<std::shared_ptr<ASTNode>> children;
    children.push_back(ELEMENT);
    children.push_back(START);
    children.push_back(END);
    if (getIncrement() != nullptr) {
        children.push_back(INCREMENT);
    }
    children.push_back(BODY);
    return children;
}
