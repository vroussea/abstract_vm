
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

std::ostream &operator<<(std::ostream &o, Parser const &instance) {
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

