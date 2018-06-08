
#ifndef ABSTRACT_VM_TOKEN_HPP
#define ABSTRACT_VM_TOKEN_HPP


#include <iostream>

/*enum type {
    input,
    div,
    add,
    mul,
    sub,
    dump
};*/

class Token {
public:
    Token();

    Token(Token const &src);

    virtual ~Token();

    Token &operator=(Token const &);

private:
    //std::string value;
    //int type;

};

std::ostream &operator<<(std::ostream &o, Token const &i);


#endif
