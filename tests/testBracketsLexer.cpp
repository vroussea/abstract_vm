#include "catch.hpp"
#include "../includes/Lexer.hpp"


TEST_CASE("test bracket_opener token") {
    Lexer lexer;

    std::string expression = "(";

    Token token = lexer.findBracket(expression);

    REQUIRE(token.getTokenType() == Token::TokenType::BRACKET_OPENER);
}

TEST_CASE("test bracket_closer token") {
    Lexer lexer;

    std::string expression = ")";

    Token token = lexer.findBracket(expression);

    REQUIRE(token.getTokenType() == Token::TokenType::BRACKET_CLOSER);
}