
#ifndef ABSTRACT_VM_PARSER_HPP
#define ABSTRACT_VM_PARSER_HPP


#include <iostream>
#include <vector>

class Parser {
public:
    Parser();

    Parser(Parser const &src);

    virtual ~Parser();

    Parser &operator=(Parser const &);

    //const Exception &getExceptions();

    bool isErrorMode();

    void setErrorMode(bool errorMode);


    class OverflowException : public std::exception {
    public:
        virtual const char *what() const noexcept;
    };

    class UnderflowException : public std::exception {
    public:
        virtual const char *what() const noexcept;
    };

    class PopOnEmptyStackException : public std::exception {
    public:
        virtual const char *what() const noexcept;
    };

    class ForbiddenMathsException : public std::exception {
    public:
        virtual const char *what() const noexcept;
    };

    class NoExitInstructionException : public std::exception {
    public:
        virtual const char *what() const noexcept;
    };

    class FalseAssertException : public std::exception {
    public:
        virtual const char *what() const noexcept;
    };

    class TooFewValuesException : public std::exception {
    public:
        virtual const char *what() const noexcept;
    };

private:
    //Exception exceptions;
    bool errorMode;
};

std::ostream &operator<<(std::ostream &o, Parser const &i);


#endif
