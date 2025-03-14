#include "TipBool.h"
#include "TipTypeVisitor.h"

#include <string>

TipBool::TipBool() { }

bool TipBool::operator==(const TipType &other) const {
    auto otherTipBool = dynamic_cast<TipBool const *>(&other);
    if(!otherTipBool) {
        return false;
    }

    return true;
}

bool TipBool::operator!=(const TipType &other) const {
    return !(*this == other);
}

std::ostream &TipBool::print(std::ostream &out) const {
    out << std::string("bool");
    return out;
}  // LCOV_EXCL_LINE

// TipInt is a 0-ary type constructor so it has no arguments to visit
void TipBool::accept(TipTypeVisitor * visitor) {
  visitor->visit(this);
  visitor->endVisit(this);
}