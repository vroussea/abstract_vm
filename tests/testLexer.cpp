#include "catch.hpp"
#include "../includes/Lexer.hpp"

TEST_CASE("unrecognized character") {
    Lexer lexer;
    std::string expression = "dump e";

    REQUIRE(!lexer.doesExist(expression));
}

TEST_CASE("error in type") {
    Lexer lexer;
    std::string expression = "push int9(9)";

    REQUIRE(!lexer.doesExist(expression));
}

TEST_CASE("one space in expression") {
    Lexer lexer;
    std::string expression = "push int8(9) ";

    REQUIRE(!lexer.doesExist(expression));
}

TEST_CASE("expression empty") {
    Lexer lexer;

    REQUIRE(!lexer.doesExist(""));
}

TEST_CASE("only whitespaces") {
    Lexer lexer;
    std::string expression = "    ";

    REQUIRE(!lexer.doesExist(expression));
}

TEST_CASE("only comment") {
    Lexer lexer;
    std::string expression = ";dump e";

    REQUIRE(lexer.doesExist(expression));
}

TEST_CASE("expression is ok") {
    Lexer lexer;
    std::string expression = "push int8(5);4555 e";

    REQUIRE(lexer.doesExist(expression));
}

