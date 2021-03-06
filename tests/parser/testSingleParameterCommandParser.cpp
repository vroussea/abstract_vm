#include "../catch.hpp"
#include "../../includes/Lexer.hpp"
#include "../../includes/Parser.hpp"

TEST_CASE("test pop ok") {
    Parser parser;

    Token token(Token::ADD);

    REQUIRE_NOTHROW(parser.littleCommand("", token));
}

TEST_CASE("test pop with something at the end") {
    Parser parser;

    std::string expression = ";comment";

    Token token(Token::ADD);

    REQUIRE_THROWS_AS(parser.littleCommand(expression, token), Lexer::LexicalErrorException);
}