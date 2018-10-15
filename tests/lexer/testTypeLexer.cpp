#include "../catch.hpp"
#include "../../includes/Lexer.hpp"
#include "../../includes/eOperandType.hpp"


TEST_CASE("test type token") {
    Lexer lexer;

    std::string expression = " int8";

    Token token = lexer.findType(expression);

    REQUIRE(token.getTokenType() == Token::TokenType::TYPE);
}

TEST_CASE("test type int8") {
    Lexer lexer;

    std::string expression = " int8";

    Token token = lexer.findType(expression);

    REQUIRE(token.getValueType() == eOperandType::Int8);
}

TEST_CASE("test type int16") {
    Lexer lexer;

    std::string expression = " int16";

    Token token = lexer.findType(expression);

    REQUIRE(token.getValueType() == eOperandType::Int16);
}

TEST_CASE("test type int32") {
    Lexer lexer;

    std::string expression = " int32";

    Token token = lexer.findType(expression);

    REQUIRE(token.getValueType() == eOperandType::Int32);
}

TEST_CASE("test type float") {
    Lexer lexer;

    std::string expression = " float";

    Token token = lexer.findType(expression);

    REQUIRE(token.getValueType() == eOperandType::Float);
}

TEST_CASE("test type double") {
    Lexer lexer;

    std::string expression = " double";

    Token token = lexer.findType(expression);

    REQUIRE(token.getValueType() == eOperandType::Double);
}

TEST_CASE("test wrong type") {
    Lexer lexer;

    std::string expression = " gregexit";

    REQUIRE_THROWS_AS(lexer.findType(expression).getCommandType(), LexerExceptions::LexicalErrorException);
}

TEST_CASE("test type is erased from the line") {
    Lexer lexer;

    std::string expression = " int8(9)";

    lexer.findType(expression);

    REQUIRE(expression == "(9)");
}
