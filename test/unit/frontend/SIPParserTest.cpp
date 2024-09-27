#include "ExceptionContainsWhat.h"
#include "FrontEnd.h"
#include "ParseError.h"
#include "ParserHelper.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("SIP Parser: boolean constants", "[TIP Parser]") {
    std::stringstream stream;
    stream << R"(
      constants() {
        var x, y;
        x = true;
        y = false;
        return 0;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: array", "[TIP Parser]") {
    std::stringstream stream;
    stream << R"(
      operators() {
        var x, y;
        x = true;
        y = false;
        return 0;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}
