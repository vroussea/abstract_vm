
#ifndef ABSTRACT_VM_LEXEREXCEPTIONS_HPP
#define ABSTRACT_VM_LEXEREXCEPTIONS_HPP


#include <iostream>

class LexerExceptions {
public:
    LexerExceptions() = default;

    LexerExceptions(LexerExceptions const &src) = default;

    virtual ~LexerExceptions() = default;

    LexerExceptions &operator=(LexerExceptions const &) = default;

    class LexicalErrorException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class UnknownIntructionException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

private:
};

std::ostream &operator<<(std::ostream &o, LexerExceptions const &i);


#endif
