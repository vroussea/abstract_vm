
#ifndef ABSTRACT_VM_LEXICALERROREXCEPTION_HPP
#define ABSTRACT_VM_LEXICALERROREXCEPTION_HPP


#include <iostream>

class LexicalErrorException {
public:
    LexicalErrorException();

    LexicalErrorException(int);

    LexicalErrorException(LexicalErrorException const &src);

    virtual ~LexicalErrorException();

    LexicalErrorException &operator=(LexicalErrorException const &);

private:
};

std::ostream &operator<<(std::ostream &o, LexicalErrorException const &i);


#endif
