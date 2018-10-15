
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

const char *OperandExceptions::OverflowException::what() const noexcept {
    return "Overflow in this line";
}

const char *OperandExceptions::UnderflowException::what() const noexcept {
    return "Underflow in this line";
}

const char *OperandExceptions::ForbiddenMathsException::what() const noexcept {
    return "Division/modulo by 0 in this line";
}