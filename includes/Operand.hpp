
#ifndef ABSTRACT_VM_OPERAND_HPP
#define ABSTRACT_VM_OPERAND_HPP


#include <iostream>

class Operand {
public:
    Operand();

    Operand(Operand const &src);

    virtual ~Operand();

    Operand &operator=(Operand const &);

private:
};

std::ostream &operator<<(std::ostream &o, Operand const &i);


#endif
