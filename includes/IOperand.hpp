#ifndef ABSTRACT_VM_IOPERAND_HPP
#define ABSTRACT_VM_IOPERAND_HPP

#include <string>
#include "eOperandType.hpp"

class IOperand {
public:
    virtual int getPrecision(void) const = 0;

    virtual eOperandType getType(void) const = 0;
    virtual IOperand const *operator+(IOperand const &rhs) const = 0; // Sum
    virtual IOperand const *operator-(IOperand const &rhs) const = 0; // Difference
    virtual IOperand const *operator*(IOperand const &rhs) const = 0; // Product
    virtual IOperand const *operator/(IOperand const &rhs) const = 0; // Quotient
    virtual IOperand const *operator%(IOperand const &rhs) const = 0; // Modulo
    virtual std::string const &toString(void) const = 0;
    virtual ~IOperand(void) {}
};

#endif
