#include "../catch.hpp"
#include "../../includes/Lexer.hpp"
#include "../../includes/Parser.hpp"

TEST_CASE("test push ok") {
    Parser parser;

    std::string expression = " int8(9)";

    Token token(Token::COMMAND);

    token.setCommandType(Token::CommandType::PUSH);

    REQUIRE_NOTHROW(parser.pushAssertCommand(expression, token));
}

/*
TEST_CASE("test push with wrong type") {
    Parser parser;

    std::string expression = " int9(9)";

    Token token(Token::COMMAND);

    token.setCommandType(Token::CommandType::PUSH);

    REQUIRE_THROWS_AS(parser.pushAssertCommand(expression, token), LexerExceptions::LexicalErrorException);
}

TEST_CASE("test push without opening bracket") {
    Parser parser;

    std::string expression = " int89)";

    Token token(Token::COMMAND);

    token.setCommandType(Token::CommandType::PUSH);

    REQUIRE_THROWS_AS(parser.pushAssertCommand(expression, token), LexerExceptions::LexicalErrorException);
}

TEST_CASE("test push with wrong opening bracket") {
    Parser parser;

    std::string expression = " int8)9)";

    Token token(Token::COMMAND);

    token.setCommandType(Token::CommandType::PUSH);

    REQUIRE_THROWS_AS(parser.pushAssertCommand(expression, token), LexerExceptions::LexicalErrorException);
}

TEST_CASE("test push without closing bracket") {
    Parser parser;

    std::string expression = " int8(9";

    Token token(Token::COMMAND);

    token.setCommandType(Token::CommandType::PUSH);

    REQUIRE_THROWS_AS(parser.pushAssertCommand(expression, token), LexerExceptions::LexicalErrorException);
}

TEST_CASE("test push with wrong closing bracket") {
    Parser parser;

    std::string expression = " int8(9(";

    Token token(Token::COMMAND);

    token.setCommandType(Token::CommandType::PUSH);

    REQUIRE_THROWS_AS(parser.pushAssertCommand(expression, token), LexerExceptions::LexicalErrorException);
}

TEST_CASE("test push without value") {
    Parser parser;

    std::string expression = " int8()";

    Token token(Token::COMMAND);

    token.setCommandType(Token::CommandType::PUSH);

    REQUIRE_THROWS_AS(parser.pushAssertCommand(expression, token), LexerExceptions::LexicalErrorException);
}

TEST_CASE("test push with wrong value") {
    Parser parser;

    std::string expression = " int8(a)";

    Token token(Token::COMMAND);

    token.setCommandType(Token::CommandType::PUSH);

    REQUIRE_THROWS_AS(parser.pushAssertCommand(expression, token), LexerExceptions::LexicalErrorException);
}

TEST_CASE("test push with something at the end") {
    Parser parser;

    std::string expression = " int8(9);comment";

    Token token(Token::COMMAND);

    token.setCommandType(Token::CommandType::PUSH);

    REQUIRE_THROWS_AS(parser.pushAssertCommand(expression, token), LexerExceptions::LexicalErrorException);
}*/
