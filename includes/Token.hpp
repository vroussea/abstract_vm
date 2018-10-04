
#ifndef ABSTRACT_VM_TOKKEN_HPP
#define ABSTRACT_VM_TOKKEN_HPP


#include <iostream>

class Token {
public:

    typedef enum {
        push,
        assert,
        pop,
        dump,
        add,
        sub,
        mul,
        div,
        mod,
        print,
        exit
        /*int8|int16|int32|float|double*/
    } TokenType;

    Token();

    Token(TokenType _tokkenType, double _value);

    Token(Token const &src);

    virtual ~Token();

    Token &operator=(Token const &);

    TokenType getTokenType() const;

    void setTokenType(TokenType tokkenType);

    double getTokenValue() const;

    void setTokenValue(double tokkenValue);


private:

    TokenType tokenType;
    double tokenValue;
};

std::ostream &operator<<(std::ostream &o, Token const &i);


#endif
