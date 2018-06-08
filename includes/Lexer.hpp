
#ifndef ABSTRACT_VM_LEXER_HPP
#define ABSTRACT_VM_LEXER_HPP


#include <iostream>

class Lexer {
public:
    Lexer(void);

    Lexer(int);

    Lexer(Lexer const &src);

    virtual ~Lexer(void);

    Lexer &operator=(Lexer const &);

private:
};

std::ostream &operator<<(std::ostream &o, Lexer const &i);


#endif
