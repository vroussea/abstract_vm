
#include <limits>
#include "../includes/OperandFactory.hpp"
#include "../includes/exceptions/OperandExceptions.hpp"
#include "../includes/Operand.hpp"

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
    char min = std::numeric_limits<char>::min();
    char max = std::numeric_limits<char>::max();

    if (newValue < min)
        throw OperandExceptions::UnderflowException();
    if (newValue > max)
        throw OperandExceptions::OverflowException();

    return new Operand<char>(eOperandType::Int8, std::to_string(newValue), min, max);
}

IOperand const *OperandFactory::createInt16(std::string const &value) const {
    long long newValue = std::stoll(value);
    short min = std::numeric_limits<short>::min();
    short max = std::numeric_limits<short>::max();

    if (newValue < min)
        throw OperandExceptions::UnderflowException();
    if (newValue > max)
        throw OperandExceptions::OverflowException();

    return new Operand<short>(eOperandType::Int16, std::to_string(newValue), min, max);
}

IOperand const *OperandFactory::createInt32(std::string const &value) const {
    long long newValue = std::stoll(value);
    int min = std::numeric_limits<int>::min();
    int max = std::numeric_limits<int>::max();

    if (newValue < min)
        throw OperandExceptions::UnderflowException();
    if (newValue > max)
        throw OperandExceptions::OverflowException();

    return new Operand<int>(eOperandType::Int32, std::to_string(newValue), min, max);
}

IOperand const *OperandFactory::createFloat(std::string const &value) const {
    long double newValue = std::stold(value);
    long double min = std::numeric_limits<float>::min();
    long double max = std::numeric_limits<float>::max();

    if (newValue < min)
        throw OperandExceptions::UnderflowException();
    if (newValue > max)
        throw OperandExceptions::OverflowException();

    return new Operand<float>(eOperandType::Float, std::to_string(newValue), static_cast<float>(min),
                              static_cast<float>(max));
}

IOperand const *OperandFactory::createDouble(std::string const &value) const {
    long double newValue = std::stold(value);
    long double min = std::numeric_limits<double>::min();
    long double max = std::numeric_limits<double>::max();

    if (newValue < min)
        throw OperandExceptions::UnderflowException();
    if (newValue > max)
        throw OperandExceptions::OverflowException();

    return new Operand<double>(eOperandType::Double, std::to_string(newValue), static_cast<double>(min),
                               static_cast<double>(max));
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

