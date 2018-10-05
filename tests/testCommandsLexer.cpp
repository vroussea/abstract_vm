#include "catch.hpp"
#include "../includes/Lexer.hpp"


TEST_CASE("test command token") {
    Lexer lexer;

    std::string expression = "push";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getTokenType() == Token::TokenType::COMMAND);
}

TEST_CASE("test command push") {
    Lexer lexer;

    std::string expression = "push";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::PUSH);
}

TEST_CASE("test command assert") {
    Lexer lexer;

    std::string expression = "assert";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::ASSERT);
}

TEST_CASE("test command pop") {
    Lexer lexer;

    std::string expression = "pop";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::POP);
}

TEST_CASE("test command dump") {
    Lexer lexer;

    std::string expression = "dump";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::DUMP);
}

TEST_CASE("test command add") {
    Lexer lexer;

    std::string expression = "add";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::ADD);
}

TEST_CASE("test command sub") {
    Lexer lexer;

    std::string expression = "sub";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::SUB);
}

TEST_CASE("test command mul") {
    Lexer lexer;

    std::string expression = "mul";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::MUL);
}

TEST_CASE("test command div") {
    Lexer lexer;

    std::string expression = "div";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::DIV);
}

TEST_CASE("test command mod") {
    Lexer lexer;

    std::string expression = "mod";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::MOD);
}

TEST_CASE("test command print") {
    Lexer lexer;

    std::string expression = "print";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::PRINT);
}

TEST_CASE("test command exit") {
    Lexer lexer;

    std::string expression = "exit";

    Token token = lexer.findCommand(expression);

    REQUIRE(token.getCommandType() == Token::CommandType::EXIT);
}

TEST_CASE("test wrong command") {
    Lexer lexer;

    std::string expression = "gregexit";

    REQUIRE_THROWS_AS(lexer.findCommand(expression).getCommandType(), Lexer::UnknownIntructionException);
}

TEST_CASE("test command is erased from the line") {
    Lexer lexer;

    std::string expression = "push int8(9)";

    lexer.findCommand(expression);

    REQUIRE(expression == " int8(9)");
}