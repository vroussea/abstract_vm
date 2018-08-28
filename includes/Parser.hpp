
#ifndef ABSTRACT_VM_PARSER_HPP
#define ABSTRACT_VM_PARSER_HPP


#include <iostream>
#include <vector>
#include "exceptions/Exception.hpp"

class Parser {
public:
    Parser();

    Parser(Parser const &src);

    virtual ~Parser();

    Parser &operator=(Parser const &);

    const Exception &getExceptions();

    bool isErrorMode();

    void setErrorMode(bool errorMode);

private:
    Exception exceptions;
    bool errorMode;
};

std::ostream &operator<<(std::ostream &o, Parser const &i);


#endif
