
#ifndef ABSTRACT_VM_OPERANDFACTORY_HPP
#define ABSTRACT_VM_OPERANDFACTORY_HPP


#include <iostream>
#include <array>
#include "IOperand.hpp"

class OperandFactory {
public:
    typedef IOperand const *(OperandFactory::*OperandFactoryFunctionPointer)(std::string const &value) const;

    OperandFactory();

    OperandFactory(OperandFactory const &src) = default;

    virtual ~OperandFactory() = default;

    OperandFactory &operator=(OperandFactory const &) = default;

    IOperand const *createOperand(eOperandType type, std::string const &value) const;

private:
    std::array<OperandFactoryFunctionPointer, 5> createOperandFunctions;

    IOperand const *createInt8(std::string const &value) const;

    IOperand const *createInt16(std::string const &value) const;

    IOperand const *createInt32(std::string const &value) const;

    IOperand const *createFloat(std::string const &value) const;

    IOperand const *createDouble(std::string const &value) const;
};

std::ostream &operator<<(std::ostream &o, OperandFactory const &i);


#endif
