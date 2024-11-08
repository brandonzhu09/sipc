#include "ASTVisualizer.h"
#include "ASTHelper.h"
#include "GeneralHelper.h"
#include "Iterator.h"
#include "SyntaxTree.h"

#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("ASTVisualizer: Generate dot graph", "[ASTVisualizer]") {
  std::stringstream stream;
  stream << R"(
      short() {
        var x, y, z;
        x = input;
        y = alloc x;
        *y = x;
        z = *y;
        while (true) output 1;
        return z;
      }
    )";

  std::shared_ptr<ASTProgram> ast = std::move(ASTHelper::build_ast(stream));
  SyntaxTree syntaxTree(ast);

  std::stringstream graph;
  ASTVisualizer visualizer(graph);
  visualizer.buildGraph(syntaxTree);

  int expectedNodeCount = 28;
  int expectedEdgeCount = 27;
  REQUIRE(expectedNodeCount ==
          GeneralHelper::countSubstrings(graph.str(), "label"));
  REQUIRE(expectedEdgeCount ==
          GeneralHelper::countSubstrings(graph.str(), "->"));
}
