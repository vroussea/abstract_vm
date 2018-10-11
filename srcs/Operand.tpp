#include "../includes/IOperand.hpp"

#include <sstream>
#include <iostream>

//#define CHAR_MIN = std::numeric_limits<char>::min();

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

    int getPrecision(void) const {
        return this->precision;
    }

    eOperandType getType(void) const {
        return this->type;
    }

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

    std::string const &toString(void) const {
        return this->str;
    }


/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

private:
    std::string str;
    int precision;
    eOperandType type;
    T value;
    T min;
    T max;
};