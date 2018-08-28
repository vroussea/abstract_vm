
#ifndef ABSTRACT_VM_EXCEPTION_HPP
#define ABSTRACT_VM_EXCEPTION_HPP


#include <iostream>

class Exception : public std::exception {
public:
    virtual const char *what() const throw();
};

#endif
