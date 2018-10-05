
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

/*const Exception &Parser::getExceptions() {
    return this->exceptions;
}*/

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

const char *Parser::OverflowException::what() const noexcept {
    return "Overflow in this line";
}

const char *Parser::UnderflowException::what() const noexcept {
    return "Underflow in this line";
}

const char *Parser::PopOnEmptyStackException::what() const noexcept {
    return "Pop on empty stack in this line";
}

const char *Parser::ForbiddenMathsException::what() const noexcept {
    return "Division/modulo by 0 in this line";
}

const char *Parser::NoExitInstructionException::what() const noexcept {
    return "No exit instructions in the commands";
}

const char *Parser::FalseAssertException::what() const noexcept {
    return "False assertion in this line";
}

const char *Parser::TooFewValuesException::what() const noexcept {
    return "Not enough values do to the operation in this line";
}