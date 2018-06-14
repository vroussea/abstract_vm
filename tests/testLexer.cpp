#include "catch.hpp"
#include "../includes/Lexer.hpp"

TEST_CASE("test Lexer", "") {
    std::vector<std::string> lines;
    lines.emplace_back("; test");
    lines.emplace_back(";; mdr");
    lines.emplace_back("input int32(69)");
    lines.emplace_back("mul ; yes");
    lines.emplace_back("ok");
    lines.emplace_back("mdr ?");

    std::vector<std::string> tokens;

    tokens = Lexer::getTokens(lines);

    std::vector<std::string> testTokens;
    testTokens.emplace_back("input int32(69)");
    testTokens.emplace_back("mul ");
    testTokens.emplace_back("ok");
    testTokens.emplace_back("mdr ");

    REQUIRE(testTokens == tokens);
}