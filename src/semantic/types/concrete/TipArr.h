#pragma once

#include "TipType.h"
#include "TipCons.h"
#include <string>
#include <vector>
#include <memory>

/*!
 * \class TipArr 
 *
 * \brief A proper type representing an array 
 */
class TipArr: public TipCons {
public:
    //TipArr() = delete;
    TipArr(std::shared_ptr<TipType> type);

    std::vector<std::shared_ptr<TipType>> getElements() const;

    bool operator==(const TipType& other) const override;
    bool operator!=(const TipType& other) const override;

    void accept(TipTypeVisitor *visitor) override;

protected:
    std::ostream& print(std::ostream &out) const override;
};