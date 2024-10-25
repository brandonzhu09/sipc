#include "ASTForRangeStmt.h"
#include "ASTVisitor.h"

void ASTForRangeStmt::accept(ASTVisitor *visitor) {
    if (visitor->visit(this)) {
        getElement()->accept(visitor);
        getStart()->accept(visitor);
        getEnd()->accept(visitor);
        getIncrement()->accept(visitor);
        getBody()->accept(visitor);
    }
    visitor->endVisit(this);
}

std::ostream &ASTForRangeStmt::print(std::ostream &out) const {
    out << "for (" << *getElement() << " : " << *getStart() << " .. " << *getEnd() << " by " << *getIncrement() << ") " << *getBody();
    return out;
} // LCOV_EXCL_LINE

std::vector<std::shared_ptr<ASTNode>> ASTForRangeStmt::getChildren() {
    std::vector<std::shared_ptr<ASTNode>> children;
    children.push_back(ELEMENT);
    children.push_back(START);
    children.push_back(END);
    children.push_back(INCREMENT);
    children.push_back(BODY);
    return children;
}
