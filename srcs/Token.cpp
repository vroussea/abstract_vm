
#include "../includes/Token.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Token::Token() = default;

Token::Token(TokenType _tokkenType) : tokenType(_tokkenType) {

}

Token::Token(int _tokkenType, std::string const &_value) : tokenType(_tokkenType), tokenValue(_value) {

}

Token::Token(Token const &src) {
    *this = src;
}

Token::~Token() = default;

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Token &Token::operator=(Token const &rhs) {
    if (this != &rhs) {
        this->setTokenType(rhs.getTokenType());
        this->setCommandType(rhs.getCommandType());
        this->setValueType(rhs.getValueType());
        this->setTokenValue(rhs.getTokenValue());
    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, Token const &instance) {
    o << "Token type : ";
    o << instance.getTokenType() << std::endl;
    o << "Command type : ";
    o << instance.getCommandType() << std::endl;
    o << "Value type : ";
    o << instance.getValueType() << std::endl;
    o << "Token value : ";
    o << instance.getTokenValue() << std::endl;
    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */



/* ******************************* */
/*            Accessors            */
/* ******************************* */

int Token::getTokenType() const {
    return tokenType;
}

void Token::setTokenType(int tokkenType) {
    this->tokenType = tokkenType;
}

int Token::getCommandType() const {
    return commandType;
}

void Token::setCommandType(int commandType) {
    this->commandType = commandType;
}

int Token::getValueType() const {
    return valueType;
}

void Token::setValueType(int valueType) {
    this->valueType = valueType;
}

std::string const &Token::getTokenValue() const {
    return tokenValue;
}

void Token::setTokenValue(std::string const &tokenValue) {
    this->tokenValue = tokenValue;
}

/* ******************************* */

/*            Exceptions           */
/* ******************************* */

