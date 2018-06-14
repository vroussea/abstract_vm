
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

private:
    std::vector<std::exception> exceptions;
    bool static isErrorMode;

};

std::ostream &operator<<(std::ostream &o, Parser const &i);


#endif
