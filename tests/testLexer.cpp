#include "catch.hpp"
#include "../includes/Token.hpp"

TEST_CASE("", "") {
    std::vector<std::string> lines;
    lines.push_back("; test");
    lines.push_back(";; mdr");
    lines.push_back("input int32(69)");
    lines.push_back("mul ; yes");
    lines.push_back("ok");
    lines.push_back("mdr ?");

    std::vector<Token> tokens;

    tokens = Lexer.
}