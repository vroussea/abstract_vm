
#ifndef ABSTRACT_VM_OPERAND_TPP
#define ABSTRACT_VM_OPERAND_TPP

#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "exceptions/OperandExceptions.hpp"

#include <sstream>
#include <cmath>

template<typename T>
class Operand : public IOperand {
public:
/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

    Operand(eOperandType _type, std::string _value, T _min, T _max)
            : type(_type), precision(static_cast<int>(_type)), value(std::move(_value)), min(_min), max(_max) {
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
            this->precision = rhs.getPrecision();
            this->value = rhs.toString();
            this->type = rhs.getType();
            this->min = getMin();
            this->max = getMax();
        }

        return *this;
    }

/* ******************************* */
/*            Functions            */
/* ******************************* */


    IOperand const *operator+(IOperand const &rhs) const override {
        long double newValue = std::stold(this->toString()) + std::stold(rhs.toString());

        if (rhs.getPrecision() > this->getPrecision())
            return operandFactory.createOperand(rhs.getType(), std::to_string(newValue));
        else
            return operandFactory.createOperand(getType(), std::to_string(newValue));
    }

    IOperand const *operator-(IOperand const &rhs) const override {
        long double newValue = std::stold(this->toString()) - std::stold(rhs.toString());

        if (rhs.getPrecision() > this->getPrecision())
            return operandFactory.createOperand(rhs.getType(), std::to_string(newValue));
        else
            return operandFactory.createOperand(getType(), std::to_string(newValue));
    }

    IOperand const *operator*(IOperand const &rhs) const override {
        long double newValue = std::stold(this->toString()) * std::stold(rhs.toString());

        if (rhs.getPrecision() > this->getPrecision())
            return operandFactory.createOperand(rhs.getType(), std::to_string(newValue));
        else
            return operandFactory.createOperand(getType(), std::to_string(newValue));
    }

    IOperand const *operator/(IOperand const &rhs) const override {
        if (std::stold(rhs.toString()) == 0)
            throw OperandExceptions::ForbiddenMathsException();

        long double newValue = std::stold(this->toString()) / std::stold(rhs.toString());

        if (rhs.getPrecision() > this->getPrecision())
            return operandFactory.createOperand(rhs.getType(), std::to_string(newValue));
        else
            return operandFactory.createOperand(getType(), std::to_string(newValue));
    }

    IOperand const *operator%(IOperand const &rhs) const override {
        if (std::stold(rhs.toString()) == 0)
            throw OperandExceptions::ForbiddenMathsException();

        long double newValue = std::fmod(std::stold(this->toString()), std::stold(rhs.toString()));

        if (rhs.getPrecision() > this->getPrecision())
            return operandFactory.createOperand(rhs.getType(), std::to_string(newValue));
        else
            return operandFactory.createOperand(getType(), std::to_string(newValue));
    }

/* ******************************* */
/*            Accessors            */
/* ******************************* */

    int getPrecision(void) const override {
        return this->precision;
    }

    eOperandType getType(void) const override {
        return this->type;
    }

    std::string const &toString(void) const override {
        return this->value;
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
    OperandFactory operandFactory;
    eOperandType type;
    int precision;
    std::string value;
    T min;
    T max;
};

#endif