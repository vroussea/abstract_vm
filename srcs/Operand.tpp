#include "../includes/IOperand.hpp"

#include <sstream>
#include <iostream>

template<typename T>
class Operand : public IOperand {
public:
/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

    Operand(eOperandType _type, T _value, T _min, T _max)
            : type(_type), precision(static_cast<int>(_type)), value(_value), min(_min), max(_max) {
        std::stringstream sstream;

        sstream << "Operand type : " << std::to_string(static_cast<int>(type)) << "\n";
        sstream << "Operand value : " << std::to_string(value) << "\n";
        sstream << "Operand precision : " << std::to_string(precision) << "\n";
        sstream << "Operand min : " << std::to_string(min) << "\n";
        sstream << "Operand max : " << std::to_string(max) << "\n";
        str = sstream.str();
    }

    Operand(Operand const &src) {
        *this = src;
    }

    ~Operand() {

    }

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

    Operand &operator=(Operand const &rhs) {
        if (this != &rhs) {

        }

        return *this;
    }

/* ******************************* */
/*            Functions            */
/* ******************************* */


    IOperand const *operator+(IOperand const &rhs) const {
        return this;
    }

    IOperand const *operator-(IOperand const &rhs) const {
        return this;
    }

    IOperand const *operator*(IOperand const &rhs) const {
        return this;
    }

    IOperand const *operator/(IOperand const &rhs) const {
        return this;
    }

    IOperand const *operator%(IOperand const &rhs) const {
        return this;
    }

/* ******************************* */
/*            Accessors            */
/* ******************************* */

    int getPrecision(void) const {
        return this->precision;
    }

    eOperandType getType(void) const {
        return this->type;
    }

    std::string const &toString(void) const {
        return this->str;
    }

    const T getValue() const {
        return value;
    }

    const T getMin() const {
        return min;
    }

    const T getMax() const {
        return max;
    }


/* ******************************* */
/*            Exceptions           */
/* ******************************* */

private:
    std::string str;
    int const precision;
    eOperandType const type;
    T const value;
    T const min;
    T const max;
};