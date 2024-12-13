#include "TipArr.h"
#include "TipTypeVisitor.h"

#include <sstream>

TipArr::TipArr(std::shared_ptr<TipType> type): 
TipCons(std::move(std::vector<std::shared_ptr<TipType>>(1, type))) { }

std::vector<std::shared_ptr<TipType>> TipArr::getElements() const {
    std::vector<std::shared_ptr<TipType>> elements(arguments.begin(), arguments.end());
    return elements;
}

std::ostream &TipArr::print(std::ostream &out) const {   
    out << "arr::" << *arguments.front();
    return out;
}

bool TipArr::operator==(const TipType &other) const {
    auto otherTipArr = dynamic_cast<const TipArr *>(&other);
    if(!otherTipArr) {
        return false;
    }

    if(*(arguments.at(0)) != *(otherTipArr->arguments.at(0))) {
        return false;
    }

    return true;
}

bool TipArr::operator!=(const TipType &other) const {
    return !(*this == other);
}

void TipArr::accept(TipTypeVisitor * visitor) {
  if (visitor->visit(this)) {
    for (auto a : arguments) {
       a->accept(visitor);
    }
  }
  visitor->endVisit(this);
}