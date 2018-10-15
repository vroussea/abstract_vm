
#ifndef ABSTRACT_VM_OPERANDEXCEPTIONS_HPP
#define ABSTRACT_VM_OPERANDEXCEPTIONS_HPP


#include <iostream>

class OperandExceptions {
public:
    OperandExceptions() = default;

    OperandExceptions(OperandExceptions const &src) = default;

    virtual ~OperandExceptions() = default;

    OperandExceptions &operator=(OperandExceptions const &) = default;

    class OverflowException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class UnderflowException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class ForbiddenMathsException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

private:
};

std::ostream &operator<<(std::ostream &o, OperandExceptions const &i);


#endif
