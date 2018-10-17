
#ifndef ABSTRACT_VM_OPERAND_TPP
#define ABSTRACT_VM_OPERAND_TPP

#include "IOperand.hpp"
#include "OperandFactory.hpp"
#include "exceptions/OperandExceptions.hpp"

#include <sstream>

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
        //TODO replace this with if and else
        if (rhs.getPrecision() > this->getPrecision()) {
            IOperand const *newThis = operandFactory.createOperand(rhs.getType(), this->toString());
            IOperand const *newRhs = operandFactory.createOperand(this->getType(), rhs.toString());

            return *newThis + *newRhs;
        }

        long double newValue = std::stold(this->toString()) + std::stold(rhs.toString());

        if (newValue > this->getMax())
            throw OperandExceptions::OverflowException();
        if (newValue < this->getMin())
            throw OperandExceptions::UnderflowException();

        return operandFactory.createOperand(getType(), std::to_string(newValue));
    }

    IOperand const *operator-(IOperand const &rhs) const override {
        //TODO replace this with if and else
        if (rhs.getPrecision() > this->getPrecision()) {
            IOperand const *newThis = operandFactory.createOperand(rhs.getType(), this->toString());
            IOperand const *newRhs = operandFactory.createOperand(this->getType(), rhs.toString());

            return *newThis - *newRhs;
        }

        long double newValue = std::stold(this->toString()) - std::stold(rhs.toString());

        if (newValue > this->getMax())
            throw OperandExceptions::OverflowException();
        if (newValue < this->getMin())
            throw OperandExceptions::UnderflowException();

        return operandFactory.createOperand(getType(), std::to_string(newValue));
    }

    IOperand const *operator*(IOperand const &rhs) const override {
        return &rhs;
    }

    IOperand const *operator/(IOperand const &rhs) const override {
        return &rhs;
    }

    IOperand const *operator%(IOperand const &rhs) const override {
        return &rhs;
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