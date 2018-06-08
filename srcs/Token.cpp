
#include "../includes/Token.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Token::Token() = default;

Token::Token(Token const &src) {
    *this = src;
}

Token::~Token() = default;

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Token &Token::operator=(Token const &rhs) {
    if (this != &rhs) {
        this->setType(rhs.getType());
        this->setValue(rhs.getValue());
    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, Token const &instance) {
    o << "Token type : ";
    o << instance.getType() << std::endl;
    o << "Token value : ";
    o << instance.getValue() << std::endl;

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */



/* ******************************* */
/*            Accessors            */
/* ******************************* */

std::string Token::getType() const {
    return this->type;
}

double Token::getValue() const {
    return this->value;
}

void Token::setType(std::string _type) {
    this->type = _type;
}

void Token::setValue(double _value) {
    this->value = _value;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

