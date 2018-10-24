
#include "../../includes/exceptions/LexerExceptions.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

std::ostream &operator<<(std::ostream &o, LexerExceptions const &) {
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

const char *LexerExceptions::LexicalErrorException::what() const noexcept {
    return "Lexical error in this line";
}

const char *LexerExceptions::UnknownIntructionException::what() const noexcept {
    return "Unknown instruction in this line";
}

const char *LexerExceptions::NoExitInstructionException::what() const noexcept {
    return "No exit instructions in the commands";
}
