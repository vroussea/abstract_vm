#include "catch.hpp"
#include "../includes/Lexer.hpp"

TEST_CASE("test no comment") {
    Lexer lexer;

    std::string expression = "command";
    std::string testExpression = expression;

    lexer.findComment(expression);

    REQUIRE(expression == testExpression);
}

TEST_CASE("test expression is changed") {
    Lexer lexer;

    std::string expression = "command;test";
    std::string testExpression = expression;

    lexer.findComment(expression);

    REQUIRE(expression != testExpression);
}

TEST_CASE("test comment is removed") {
    Lexer lexer;

    std::string expression = "command;test   rgreg";

    lexer.findComment(expression);

    REQUIRE(expression == "command");
}

TEST_CASE("test no comment token type") {
    Lexer lexer;

    std::string expression = "command";

    Token token = lexer.findComment(expression);

    REQUIRE(token.getTokenType() == Token::TokenType::NULLTYPE);
}

TEST_CASE("test comment token type") {
    Lexer lexer;

    std::string expression = "command;test";
    std::string testExpression = expression;

    Token token = lexer.findComment(expression);

    REQUIRE(token.getTokenType() == Token::TokenType::COMMENT);
}