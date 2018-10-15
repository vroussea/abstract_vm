
#include "../includes/OperandFactory.hpp"
#include "../includes/exceptions/OperandExceptions.hpp"

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
    return (this->*createOperandFunctions[type])(value);
}

IOperand const *OperandFactory::createInt8(std::string const &value) const {
    long long newValue = std::stoll(value);
    char min = std::numeric_limits<char>::min();
    char max = std::numeric_limits<char>::max();

    if (newValue < min)
        throw OperandExceptions::UnderflowException();
    if (newValue > max)
        throw OperandExceptions::OverflowException();

    return new Operand<char>(eOperandType::Int8, static_cast<char>(newValue), min, max);
}

IOperand const *OperandFactory::createInt16(std::string const &value) const {
    return nullptr;
}

IOperand const *OperandFactory::createInt32(std::string const &value) const {
    return nullptr;
}

IOperand const *OperandFactory::createFloat(std::string const &value) const {
    return nullptr;
}

IOperand const *OperandFactory::createDouble(std::string const &value) const {
    return nullptr;
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

