#include "../../includes/exceptions/Exception.hpp"


/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */

/* ******************************* */

const char *Exception::what() const throw() {
    return "Grade would be superior to 1.";
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

/*
const char *Exceptions::LexicalErrorException::what() const throw() {
    return "";
}

const char *Exceptions::UnknownInstructionException::what() const throw() {
    return "";
}

const char *Exceptions::OverflowException::what() const throw() {
    return "";
}

const char *Exceptions::PopEmptyStackException::what() const throw() {
    return "";
}

const char *Exceptions::ForbiddenOperationException::what() const throw() {
    return "";
}

const char *Exceptions::NoExitException::what() const throw() {
    return "";
}

const char *Exceptions::FalseAssertException::what() const throw() {
    return "";
}

const char *Exceptions::NotEnoughValuesException::what() const throw() {
    return "";
}*/
