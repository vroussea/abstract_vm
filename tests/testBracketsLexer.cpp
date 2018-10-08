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

TEST_CASE("test not a bracket exception") {
    Lexer lexer;

    std::string expression = " gregexit";

    REQUIRE_THROWS_AS(lexer.findBracket(expression).getCommandType(), Lexer::LexicalErrorException);
}

TEST_CASE("test expression is cleaned of first bracket") {
    Lexer lexer;

    std::string expression = "(9)";
    lexer.findBracket(expression);

    REQUIRE(expression == "9)");
}