#include "../catch.hpp"
#include "../../includes/Lexer.hpp"


TEST_CASE("test value token") {
    Lexer lexer;

    std::string expression = "5";

    Token token = lexer.findValue(expression);

    REQUIRE(token.getTokenType() == Token::TokenType::VALUE);
}

TEST_CASE("test int value") {
    Lexer lexer;

    std::string expression = "5";

    Token token = lexer.findValue(expression);

    REQUIRE(token.getTokenValue() == "5");
}

TEST_CASE("test float value") {
    Lexer lexer;

    std::string expression = "5.5";

    Token token = lexer.findValue(expression);

    REQUIRE(token.getTokenValue() == "5.5");
}

TEST_CASE("test start with . exception") {
    Lexer lexer;

    std::string expression = ".5";

    REQUIRE_THROWS_AS(lexer.findValue(expression).getCommandType(), LexerExceptions::LexicalErrorException);
}

TEST_CASE("test 2 points exception") {
    Lexer lexer;

    std::string expression = "0..5";

    Token token = lexer.findValue(expression);

    REQUIRE(token.getTokenValue() == "0");
}

TEST_CASE("test not a value exception") {
    Lexer lexer;

    std::string expression = ".5";

    REQUIRE_THROWS_AS(lexer.findValue(expression).getCommandType(), LexerExceptions::LexicalErrorException);
}

TEST_CASE("test expression is cleaned of its value") {
    Lexer lexer;

    std::string expression = "9)";
    lexer.findValue(expression);

    REQUIRE(expression == ")");
}