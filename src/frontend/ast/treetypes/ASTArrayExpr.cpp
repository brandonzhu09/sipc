#include "ASTArrayExpr.h"
#include "ASTVisitor.h"
#include "ASTinternal.h"

ASTArrayExpr::ASTArrayExpr(
    std::vector<std::shared_ptr<ASTExpr>> ELEMENTS) {
    for (auto &element : ELEMENTS) {
        std::shared_ptr<ASTExpr> e = element;
        this->ELEMENTS.push_back(e);
    }
}

std::vector<ASTExpr *> ASTArrayExpr::getElements() const {
    return rawRefs(ELEMENTS);
}

void ASTArrayExpr::accept(ASTVisitor *visitor) {
    if (visitor->visit(this)) {
        for (auto e : getElements()) {
            e->accept(visitor);
        }
    }
    visitor->endVisit(this);
}

std::ostream &ASTArrayExpr::print(std::ostream &out) const {
    out << "[";
    bool skip = true;
    for (auto &e : getElements()) {
        if (skip) {
            skip = false;
            out << *e;
            continue;
        }
        out << "," << *e;
    }
    out << "]";
    return out;
} // LCOV_EXCL_LINE

std::vector<std::shared_ptr<ASTNode>> ASTArrayExpr::getChildren() {
    std::vector<std::shared_ptr<ASTNode>> children;
    for (auto &element : ELEMENTS) {
        children.push_back(element);
    }
    return children;
}