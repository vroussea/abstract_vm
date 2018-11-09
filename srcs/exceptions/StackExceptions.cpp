
#include "../../includes/exceptions/StackExceptions.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

std::ostream &operator<<(std::ostream &o, StackExceptions const &) {
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

const char *StackExceptions::PopOnEmptyStackException::what() const noexcept {
    return "Pop on empty stack in this line";
}

const char *StackExceptions::FalseAssertException::what() const noexcept {
    return "False assertion in this line";
}

const char *StackExceptions::TooFewValuesException::what() const noexcept {
    return "Not enough values to do the operation in this line";
}