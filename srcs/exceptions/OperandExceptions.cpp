
#include "../../includes/exceptions/OperandExceptions.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

std::ostream &operator<<(std::ostream &o, OperandExceptions const &) {
    o << "Nothing";

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

const char *OperandExceptions::NotAnIntegerException::what() const noexcept {
    return "Trying to push floating value in integer variable";
}

const char *OperandExceptions::OverflowException::what() const noexcept {
    return "Overflow in this line";
}

const char *OperandExceptions::UnderflowException::what() const noexcept {
    return "Underflow in this line";
}

const char *OperandExceptions::ForbiddenMathsException::what() const noexcept {
    return "Forbidden math exception in this line";
}