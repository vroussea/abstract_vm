
#ifndef ABSTRACT_VM_OPERAND_TPP
#define ABSTRACT_VM_OPERAND_TPP

#include "../includes/IOperand.hpp"
#include "../includes/OperandFactory.hpp"
#include "../includes/exceptions/OperandExceptions.hpp"

#include <sstream>
#include <cmath>

template<typename T>
class Operand : public IOperand {
public:
/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

    Operand(eOperandType _type, std::string _value)
            : type(_type), precision(static_cast<int>(_type)), value(std::move(_value)) {
    }

    Operand(Operand const &src) {
        *this = src;
    }

    ~Operand() = default;

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

    Operand &operator=(Operand const &rhs) {
        if (this != &rhs) {
            this->precision = rhs.getPrecision();
            this->value = rhs.toString();
            this->type = rhs.getType();
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
        if (std::stold(rhs.toString()) == 0 || this->getPrecision() > 2 || rhs.getPrecision() > 2)
            throw OperandExceptions::ForbiddenMathsException();

        long double newValue = std::stol(this->toString()) % std::stol(rhs.toString());

        if (rhs.getPrecision() > this->getPrecision())
            return operandFactory.createOperand(rhs.getType(), std::to_string(newValue));
        else
            return operandFactory.createOperand(getType(), std::to_string(newValue));
    }

/* ******************************* */
/*            Accessors            */
/* ******************************* */

    int getPrecision() const override {
        return this->precision;
    }

    eOperandType getType() const override {
        return this->type;
    }

    std::string const &toString() const override {
        return this->value;
    }

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

private:
    OperandFactory operandFactory;
    eOperandType type;
    int precision;
    std::string value;
};

#endif