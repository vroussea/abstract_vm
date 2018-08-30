
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

    class UnknownIntructionException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class OverflowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class UnderflowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class PopOnEmptyStackException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class ForbiddenMathsException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class NoExitInstructionException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FalseAssertException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class TooFewValuesException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

private:
    //Exception exceptions;
    bool errorMode;
};

std::ostream &operator<<(std::ostream &o, Parser const &i);


#endif
