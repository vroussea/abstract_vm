
#include "../includes/Token.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Token::Token() {

}

Token::Token(TokenType _tokkenType, double _value) : tokenType(_tokkenType), tokenValue(_value) {

}

Token::Token(Token const &src) {
    *this = src;
}

Token::~Token() {

}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Token &Token::operator=(Token const &rhs) {
    if (this != &rhs) {
        this->setTokenType(rhs.getTokenType());
        this->setTokenValue(rhs.getTokenValue());
    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, Token const &instance) {
    o << "Token type : ";
    o << instance.getTokenType();
    o << "Token value : ";
    o << instance.getTokenValue();
    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */



/* ******************************* */
/*            Accessors            */
/* ******************************* */

Token::TokenType Token::getTokenType() const {
    return tokenType;
}

void Token::setTokenType(Token::TokenType tokkenType) {
    Token::tokenType = tokkenType;
}

double Token::getTokenValue() const {
    return tokenValue;
}

void Token::setTokenValue(double tokkenValue) {
    Token::tokenValue = tokkenValue;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

