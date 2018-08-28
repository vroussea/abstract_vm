
#include "../includes/Parser.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Parser::Parser() = default;

Parser::Parser(Parser const &src) {
    *this = src;
}

Parser::~Parser() = default;

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Parser &Parser::operator=(Parser const &rhs) {
    if (this != &rhs) {

    }

    return *this;
}

const Exception &Parser::getExceptions() {
    return this->exceptions;
}

bool Parser::isErrorMode() {
    return this->errorMode;
}

void Parser::setErrorMode(bool errorMode) {
    this->errorMode = errorMode;
}


std::ostream &operator<<(std::ostream &o, Parser const &) {
    o << "The value of  is : ";

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */



/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */
