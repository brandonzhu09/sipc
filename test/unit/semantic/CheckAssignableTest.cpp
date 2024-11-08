#include "CheckAssignable.h"
#include "ASTHelper.h"
#include "ExceptionContainsWhat.h"
#include "SemanticError.h"

#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("Check Assignable: variable lhs", "[Symbol]") {
  std::stringstream stream;
  stream << R"(varlhs() { var x; x = 1; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_NOTHROW(CheckAssignable::check(ast.get()));
}

TEST_CASE("Check Assignable: pointer lhs", "[Symbol]") {
  std::stringstream stream;
  stream << R"(ptrlhs() { var x; *x = 1; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_NOTHROW(CheckAssignable::check(ast.get()));
}

TEST_CASE("Check Assignable: field lhs", "[Symbol]") {
  std::stringstream stream;
  stream << R"(fieldlhs() { var x; x = {f:0, g:1}; x.f = 1; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_NOTHROW(CheckAssignable::check(ast.get()));
}

TEST_CASE("Check Assignable: complex field lhs", "[Symbol]") {
  std::stringstream stream;
  stream << R"(recordlhs() { var x; {f:0, g:1}.f = x; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("{f:0,g:1} is an expression, and not a "
                                      "variable corresponding to a record"));
}

TEST_CASE("Check Assignable: complex pointer lhs", "[Symbol]") {
  std::stringstream stream;
  stream
      << R"(foo(x) { return &x; } ptrlhs() { var x; *foo(&x) = 1; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_NOTHROW(CheckAssignable::check(ast.get()));
}

TEST_CASE("Check Assignable: address of var", "[Symbol]") {
  std::stringstream stream;
  stream << R"(recordlhs() { var x, y; x = &y; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_NOTHROW(CheckAssignable::check(ast.get()));
}

TEST_CASE("Check Assignable: address of field", "[Symbol]") {
  std::stringstream stream;
  stream
      << R"(recordlhs() { var x, y; y = {f:0, g:1}; x = &(y.g); return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_NOTHROW(CheckAssignable::check(ast.get()));
}

/************** the following are expected to fail the check ************/

TEST_CASE("Check Assignable: constant lhs", "[Symbol]") {
  std::stringstream stream;
  stream << R"(constlhs() { var x; 7 = x; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("7 not an l-value"));
}

TEST_CASE("Check Assignable: binary lhs", "[Symbol]") {
  std::stringstream stream;
  stream << R"(binlhs() { var x; x+1 = x; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("(x+1) not an l-value"));
}

TEST_CASE("Check Assignable: function lhs", "[Symbol]") {
  std::stringstream stream;
  stream << R"(foo() { return 0; } funlhs() { var x; foo() = x; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("foo() not an l-value"));
}

TEST_CASE("Check Assignable: alloc lhs", "[Symbol]") {
  std::stringstream stream;
  stream << R"(alloclhs() { var x; alloc 1 = x; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("alloc 1 not an l-value"));
}

TEST_CASE("Check Assignable: record lhs", "[Symbol]") {
  std::stringstream stream;
  stream << R"(recordlhs() { var x; {f:0, g:1} = x; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("{f:0,g:1} not an l-value"));
}

TEST_CASE("Check Assignable: address of pointer", "[Symbol]") {
  std::stringstream stream;
  stream << R"(recordlhs(p) { var x; x = &(*p); return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("(*p) not an l-value"));
}

TEST_CASE("Check Assignable: address of expr", "[Symbol]") {
  std::stringstream stream;
  stream << R"(recordlhs(p) { var x, y; x = &(y*y); return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("(y*y) not an l-value"));
}

// SIP Testing
TEST_CASE("Check Assignable: array index lhs", "[Symbol]") {
  std::stringstream stream;
  stream << R"(arrlhs() { var x; x = [1]; x[0] = 2; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_NOTHROW(CheckAssignable::check(ast.get()));
}

TEST_CASE("Check Assignable: increment and decrement stmt", "[Symbol]") {
  std::stringstream stream;
  stream << R"(increment() { var x; x = 0; x++; x--; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_NOTHROW(CheckAssignable::check(ast.get()));
}

TEST_CASE("Check Assignable: for stmt and for range stmt, element assignable", "[Symbol]") {
  std::stringstream stream;
  stream << R"(main() { for (x : a) { } for (x : 1 .. 5 by 2) { } return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_NOTHROW(CheckAssignable::check(ast.get()));
}

// Tests expected to fail check
TEST_CASE("Check Assignable: constant increment", "[Symbol]") {
  std::stringstream stream;
  stream << R"(main() { 7++; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("7 not an l-value"));
}

TEST_CASE("Check Assignable: constant decrement", "[Symbol]") {
  std::stringstream stream;
  stream << R"(main() { 7--; return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("7 not an l-value"));
}

TEST_CASE("Check Assignable: constant element for stmt", "[Symbol]") {
  std::stringstream stream;
  stream << R"(main() { for (1 : a) { } return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("1 not an l-value"));
}

TEST_CASE("Check Assignable: constant element for range stmt", "[Symbol]") {
  std::stringstream stream;
  stream << R"(main() { for (1 : 1 .. 5 by 2) { } return 0; })";
  auto ast = ASTHelper::build_ast(stream);
  REQUIRE_THROWS_MATCHES(CheckAssignable::check(ast.get()), SemanticError,
                         ContainsWhat("1 not an l-value"));
}
