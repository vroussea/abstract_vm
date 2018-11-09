
#include <limits>
#include "../includes/OperandFactory.hpp"
#include "../includes/exceptions/OperandExceptions.hpp"
#include "Operand.cpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

OperandFactory::OperandFactory() {
    createOperandFunctions[eOperandType::Int8] = &OperandFactory::createInt8;
    createOperandFunctions[eOperandType::Int16] = &OperandFactory::createInt16;
    createOperandFunctions[eOperandType::Int32] = &OperandFactory::createInt32;
    createOperandFunctions[eOperandType::Float] = &OperandFactory::createFloat;
    createOperandFunctions[eOperandType::Double] = &OperandFactory::createDouble;
}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

std::ostream &operator<<(std::ostream &o, OperandFactory const &) {
    o << "Nothing";

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */

IOperand const *OperandFactory::createOperand(eOperandType type, std::string const &value) const {
    return dynamic_cast<const IOperand *>((this->*createOperandFunctions[type])(value));
}

IOperand const *OperandFactory::createInt8(std::string const &value) const {
    long long newValue = std::stoll(value);

    if (std::stold(value) - newValue != 0)
        throw OperandExceptions::NotAnIntegerException();

    if (newValue < std::numeric_limits<char>::min())
        throw OperandExceptions::UnderflowException();
    if (newValue > std::numeric_limits<char>::max())
        throw OperandExceptions::OverflowException();

    return new Operand<char>(eOperandType::Int8, std::to_string(static_cast<char>(newValue)));
}

IOperand const *OperandFactory::createInt16(std::string const &value) const {
    long long newValue = std::stoll(value);

    if (std::stold(value) - newValue != 0)
        throw OperandExceptions::NotAnIntegerException();

    if (newValue < std::numeric_limits<short>::min())
        throw OperandExceptions::UnderflowException();
    if (newValue > std::numeric_limits<short>::max())
        throw OperandExceptions::OverflowException();

    return new Operand<short>(eOperandType::Int16, std::to_string(static_cast<short>(newValue)));
}

IOperand const *OperandFactory::createInt32(std::string const &value) const {
    try {
        int newValue = std::stoi(value);
        if (std::stold(value) - newValue != 0)
            throw OperandExceptions::NotAnIntegerException();
    } catch (std::out_of_range const &e) {
        if (value.at(0) == '-')
            throw OperandExceptions::UnderflowException();
        else
            throw OperandExceptions::OverflowException();
    }

    return new Operand<int>(eOperandType::Int32, value);
}

IOperand const *OperandFactory::createFloat(std::string const &value) const {
    try {
        std::stof(value);
    } catch (std::out_of_range const &e) {
        if (value.at(0) == '-')
            throw OperandExceptions::UnderflowException();
        else
            throw OperandExceptions::OverflowException();
    }

    return new Operand<float>(eOperandType::Float, value);
}

IOperand const *OperandFactory::createDouble(std::string const &value) const {
    try {
        std::stod(value);
    } catch (std::out_of_range const &e) {
        if (value.at(0) == '-')
            throw OperandExceptions::UnderflowException();
        else
            throw OperandExceptions::OverflowException();
    }

    return new Operand<double>(eOperandType::Double, value);
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

