#include "ASTHelper.h"

#include <catch2/catch_test_macros.hpp>

#include <iostream>

TEST_CASE("ASTPrinterTest: SIP expression printers", "[ASTNodePrint]") {
    std::stringstream stream;
    stream << R"(
      fun() {
        var x, y, z;
        x = true;
        z = [2 of 3];
        y = z[1];
        y = y % 3;
        y = y + #z;
        x = not x and (y == 2) or false;
        y = y ? x : -y;
        return y;
      }
    )";

    std::vector<std::string> expected{"true",
                                      "[2 of 3]",
                                      "z[1]",
                                      "(y%3)",
                                      "(y+#z)",
                                      "((notxand(y==2))orfalse)",
                                      "y ? x : -y"};

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1; // skip the return
    for (auto s : f->getStmts()) {
        auto a = dynamic_cast<ASTAssignStmt *>(s);
        stream = std::stringstream();
        stream << *a->getRHS();
        auto actual = stream.str();
        REQUIRE(actual == expected.at(i++));
        if (i == numStmts)
            break;
    }
}

TEST_CASE("ASTPrinterTest: SIP statement printers", "[ASTNodePrint]") {
    std::stringstream stream;
    stream << R"(
      fun() {
        var x, /* comment */ y, z;
        x =
            0;
        x++;
        if (x == 1) y=1; else y    =    2;
        y--;
        z = [1, 2, 3];
        for (x : z)
        {
           y = y + x;
        }
        for (x : 1 .. 10 by 2) {
           y = y + x;
        }
        return y;
      }
    )";

    std::vector<std::string> expected{"var x, y, z;",
                                      "x = 0;",
                                      "x++;",
                                      "if ((x==1)) y = 1; else y = 2;",
                                      "y--;",
                                      "z = [1,2,3];",
                                      "for (x : z) { y = (y+x); }",
                                      "for (x : 1 .. 10 by 2) { y = (y+x); }",
                                      "return y;"};

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    for (auto d : f->getDeclarations()) {
        stream = std::stringstream();
        stream << *d;
        auto actual = stream.str();
        REQUIRE(actual == expected.at(i++));
    }

    for (auto s : f->getStmts()) {
        stream = std::stringstream();
        stream << *s;
        auto actual = stream.str();
        REQUIRE(actual == expected.at(i++));
    }
}

TEST_CASE("ASTPrinterTest: SIP conditional expression printers", "[ASTNodePrint]") {
    std::stringstream stream;
    stream << R"(
      fun() {
        var x, y, z;
        if (x >= y) x = 0;
        if (x < y) x = 0;
        if (x <= y) x = 0;
        return 0;
      }
    )";

    std::vector<std::string> expected{"(x>=y)", "(x<y)", "(x<=y)"};

    auto ast = ASTHelper::build_ast(stream);

    auto f = ast->findFunctionByName("fun");

    int i = 0;
    int numStmts = f->getStmts().size() - 1; // skip the return
    for (auto s : f->getStmts()) {
        auto ifstmt = dynamic_cast<ASTIfStmt *>(s);
        stream = std::stringstream();
        stream << *ifstmt->getCondition();
        auto actual = stream.str();
        REQUIRE(actual == expected.at(i++));
        if (i == numStmts)
            break;
    }
}
