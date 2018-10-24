
#ifndef ABSTRACT_VM_StackExceptions_HPP
#define ABSTRACT_VM_StackExceptions_HPP


#include <iostream>

class StackExceptions {
public:
    StackExceptions() = default;

    StackExceptions(StackExceptions const &src) = default;

    virtual ~StackExceptions() = default;

    StackExceptions &operator=(StackExceptions const &) = default;

    class PopOnEmptyStackException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class NoExitInstructionException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class FalseAssertException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class TooFewValuesException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

private:
};

std::ostream &operator<<(std::ostream &o, StackExceptions const &i);


#endif
