
#include "../includes/Operand.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Operand::Operand() {

}

Operand::Operand(Operand const &src) {
    *this = src;
}

Operand::~Operand() {

}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Operand &Operand::operator=(Operand const &rhs) {
    if (this != &rhs) {

    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, Operand const &instance) {
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

