#include "../includes/Token.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Token::Token() = default;

Token::Token(std::string const &_data) {
    setData(_data);
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
        this->setData(rhs.getData());
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, Token const &instance) {
    o << "Token : ";
    o << instance.getData() << std::endl;

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */



/* ******************************* */
/*            Accessors            */
/* ******************************* */

std::string const Token::getData() const {
    return this->data;
}

void Token::setData(std::string const &_data) {
    this->data = _data;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

