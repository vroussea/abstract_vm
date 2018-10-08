
#ifndef ABSTRACT_VM_PARSER_HPP
#define ABSTRACT_VM_PARSER_HPP


#include <iostream>
#include <vector>
#include "Lexer.hpp"

class Parser {
public:
    Parser();

    Parser(Parser const &src);

    virtual ~Parser();

    Parser &operator=(Parser const &);

    bool isErrorMode() const;

    void setErrorMode(bool errorMode);

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


private:
    bool errorMode;
    Lexer lexer;

};

std::ostream &operator<<(std::ostream &o, Parser const &i);


#endif
