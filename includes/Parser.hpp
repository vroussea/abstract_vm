
#ifndef ABSTRACT_VM_PARSER_HPP
#define ABSTRACT_VM_PARSER_HPP


#include <iostream>
#include <vector>
#include "Lexer.hpp"
#include <sstream>
#include <array>
#include "../includes/Stack.hpp"

class Parser {
public:

    typedef void (Parser::*ParserErrorMethodPointer)(std::string);

    typedef bool (Parser::*ParserMethodPointer)(std::string, Token commandToken);

    typedef bool (Stack::*ParamStackMethodPointer)(std::string const &value, eOperandType const &operandType);

    typedef bool (Stack::*SimpleStackMethodPointer)();

    Parser();

    Parser(Parser const &src);

    virtual ~Parser();

    Parser &operator=(Parser const &);

    void setErrorMode();

    void parse(std::vector<std::string> list);

    void withErrorMode(std::string);

    void withoutErrorMode(std::string);

    bool pushAssertCommand(std::string expression, Token commandToken);

    bool littleCommand(std::string expression, Token commandToken);

private:
    Stack *stack;
    size_t lineNumber;
    Parser::ParserErrorMethodPointer errorModeMethods;
    std::array<Parser::ParserMethodPointer, 2> instructionMethods;
    std::array<Parser::ParamStackMethodPointer, 2> paramStackMethods;
    std::array<Parser::SimpleStackMethodPointer, 11> littleStackMethods;
    std::vector<std::string> allErrors;
    Lexer lexer;
};

std::ostream &operator<<(std::ostream &o, Parser const &i);


#endif
