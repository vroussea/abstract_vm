
#include "../includes/Stack.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Stack::Stack() {

}

Stack::Stack(int) {

}

Stack::Stack(Stack const &src) {
    *this = src;
}

Stack::~Stack() {

}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Stack &Stack::operator=(Stack const &rhs) {
    if (this != &rhs) {

    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, Stack const &instance) {
    o << "The value of  is : ";

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */

void Stack::push(double value) {

}

void Stack::assert(double value) {

}

void Stack::pop() {

}

void Stack::dump() {

}

void Stack::add() {

}

void Stack::sub() {

}

void Stack::mul() {

}

void Stack::div() {

}

void Stack::mod() {

}

void Stack::print() {

}

void Stack::exit() {

}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

