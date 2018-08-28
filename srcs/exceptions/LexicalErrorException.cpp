
#include "../../includes/exceptions/LexicalErrorException.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

LexicalErrorException::LexicalErrorException() {

}

LexicalErrorException::LexicalErrorException(int) {

}

LexicalErrorException::LexicalErrorException(LexicalErrorException const &src) {
    *this = src;
}

LexicalErrorException::~LexicalErrorException() {

}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

LexicalErrorException &LexicalErrorException::operator=(LexicalErrorException const &rhs) {
    if (this != &rhs) {

    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, LexicalErrorException const &instance) {
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

