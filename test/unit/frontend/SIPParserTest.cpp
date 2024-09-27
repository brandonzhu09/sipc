#include "ExceptionContainsWhat.h"
#include "FrontEnd.h"
#include "ParseError.h"
#include "ParserHelper.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("SIP Parser: boolean constants and binary operators", "[TIP Parser]") {
    std::stringstream stream;
    stream << R"(
      main() {
        var x, y;
        x = true;
        y = false;
        output x and y;
        output x or y;
        return 0;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: array construction, length and element reference", "[TIP Parser]") {
    std::stringstream stream;
    stream << R"(
      arrays() {
        var x,y;
        x = [1 of 2];
        y = [1, 2, 3];
        output #x;
        output y[0];
        return 0;
      }
    )";

    REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: arithmetic operators", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(
      main() {
        var x,y;
        x = 1;
        y = 2;
        output x % y;
        output -y;
        return 0;
      }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: relational operators", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(
      main() {
        var x,y;
        x = 1;
        y = 2;
        output x >= y;
        output x < y;
        output x <= y;
        return 0;
      }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

// TODO:
TEST_CASE("SIP Parser: ternary condition expression", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(
      main() {
        var x;
         return 0;
      }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: increment decrement statements", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(
      main() {
        var x;
        x = 0;
        x++;
        x--;
        return 0;
      }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: for iterator loop", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(
      main() {
        var x;
        x = [1, 2, 3];
        for (i : x) {
            output i;
        }
        return 0;
      }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: for range loop with optional increment", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(
      main() {
        for (i : 1 .. 3) {
            output i;
        }
        for (j : 1 .. 10 by 2) {
            output j;
        }
        return 0;
      }
    )";

  REQUIRE(ParserHelper::is_parsable(stream));
}

/* These tests checks for operator precedence.
 * They access the parse tree and ensure that the higher precedence
 * operator is nested more deeply than the lower precedence operator.
 */
TEST_CASE("SIP Parser: mod higher precedence than add", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { return 1 + 2 % 3; })";
  std::string expected = "(expr (expr 1) + (expr (expr 2) % (expr 3)))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

TEST_CASE("SIP Parser: not higher precedence than and/or", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(main() { return not true or false; })";
  std::string expected = "(expr (expr not (expr true)) or (expr false))";
  std::string tree = ParserHelper::parsetree(stream);
  REQUIRE(tree.find(expected) != std::string::npos);
}

/************ The following are expected to fail parsing ************/
TEST_CASE("SIP Parser: incorrect increment statement", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(
      main() { var x; x+++; return 0; }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: missing bracket in list", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(
      main() { var x; x = [1, 2, 3; return 0; }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: bad field separator in list", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(
      operators() { var x; x = [1 2 3]; return 0; }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}

TEST_CASE("SIP Parser: missing colon in for loop", "[TIP Parser]") {
  std::stringstream stream;
  stream << R"(
      main() {
        var x;
        x = [1, 2, 3];
        for (i x) output i;
        return 0;
      }
    )";

  REQUIRE_FALSE(ParserHelper::is_parsable(stream));
}
