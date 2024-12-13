#include "TipInt.h"
#include "TipArr.h"
#include "TipAlpha.h"
#include "TipBool.h"

#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <sstream>

TEST_CASE("TipArr: Test getters"
          "[TipArr]") {

    std::shared_ptr<TipInt> intType = std::make_shared<TipInt>();
    TipArr tipArr(intType);

    REQUIRE(tipArr.getElements().size() == 1);
}

TEST_CASE("TipArr: Test equality" "[TipArr]") {
    std::shared_ptr<TipInt> intType = std::make_shared<TipInt>();
    TipArr tipArrA(intType);
    auto elemsA = tipArrA.getElements();

    SECTION("Equal when fields are of same type and length") {
        std::shared_ptr<TipInt> intType = std::make_shared<TipInt>();
        TipArr tipArrB(intType);
        auto elemsB = tipArrB.getElements();

        REQUIRE(tipArrA == tipArrB);
        REQUIRE(elemsA.size() == elemsB.size());
    }

    SECTION("Not equal when arguments differ by type") {
        std::shared_ptr<TipBool> boolType = std::make_shared<TipBool>();
        TipArr tipArrB(boolType);
        auto elemsB = tipArrB.getElements();

        REQUIRE(tipArrA != tipArrB);
    }

    SECTION("Not equal when argument types differ") {
        TipInt tipInt;

        REQUIRE(tipArrA != tipInt);
    }
}

TEST_CASE("TipArr: Test output stream" "[TipArr]") {
    std::shared_ptr<TipInt> intType = std::make_shared<TipInt>();
    TipArr tipArr(intType);

    auto expectedValue = "arr::int";
    std::stringstream stream;
    stream << tipArr;
    std::string actualValue = stream.str();

    REQUIRE(expectedValue == actualValue);
}