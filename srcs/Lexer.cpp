
#include "../includes/Lexer.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Lexer::Lexer() = default;

Lexer::~Lexer() = default;

Lexer::Lexer(Lexer const &src) {
    *this = src;
}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Lexer &Lexer::operator=(Lexer const &rhs) {
    if (this != &rhs) {

    }

    return *this;
}

//std::ostream &operator<<(std::ostream &o, Lexer const &instance) {
//    o << "The value of  is : ";

//    return o;
//}

/* ******************************* */
/*            Functions            */
/* ******************************* */



/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

