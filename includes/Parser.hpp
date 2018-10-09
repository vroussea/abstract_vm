
#ifndef ABSTRACT_VM_PARSER_HPP
#define ABSTRACT_VM_PARSER_HPP


#include <iostream>
#include <vector>
#include "Lexer.hpp"
#include <sstream>
#include "../includes/Stack.hpp"

class Parser {
public:

    typedef void (Parser::*ParserErrorMethodPointer)(std::string);

    typedef void (Parser::*ParserMethodPointer)(std::string, Token commandToken);

    typedef void (Stack::*ParamStackMethodPointer)(double value);

    typedef void (Stack::*SimpleStackMethodPointer)();

    Parser();

    Parser(Parser const &src);

    virtual ~Parser();

    Parser &operator=(Parser const &);

    void setErrorMode();

    const Lexer &getLexer() const;

    void setLexer(const Lexer &lexer);

    class OverflowException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class UnderflowException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class PopOnEmptyStackException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class ForbiddenMathsException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class NoExitInstructionException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class FalseAssertException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class TooFewValuesException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    void parse(std::vector<std::string> list);

    void withErrorMode(std::string);

    void withoutErrorMode(std::string);

    void pushAssertCommand(std::string expression, Token commandToken);

    void littleCommand(std::string expression, Token commandToken);

private:
    size_t lineNumber;
    Parser::ParserErrorMethodPointer errorModeMethods;
    std::vector<Parser::ParserMethodPointer> instructionMethods;
    std::vector<Parser::ParamStackMethodPointer> paramStackMethods;
    std::vector<Parser::SimpleStackMethodPointer> littleStackMethods;
    std::vector<std::string> allErrors;
    Lexer lexer;
};

std::ostream &operator<<(std::ostream &o, Parser const &i);


#endif
