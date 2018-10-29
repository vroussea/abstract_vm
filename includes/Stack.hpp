
#ifndef ABSTRACT_VM_STACK_HPP
#define ABSTRACT_VM_STACK_HPP

#include <iostream>
#include <stack>
#include <memory>
#include "IOperand.hpp"

class Stack {
public:
    Stack() = default;

    Stack(Stack const &src) = default;

    virtual ~Stack() = default;

    Stack &operator=(Stack const &) = default;

    bool push(std::string const &value, eOperandType const &operandType);

    bool assert(std::string const &value, eOperandType const &);

    bool pop();

    bool dump();

    bool add();

    bool sub();

    bool mul();

    bool div();

    bool mod();

    bool print();

    bool exit();

private:

    void pushStack(IOperand const *newOperand);

    std::stack<IOperand const *> operandStack{};

};

std::ostream &operator<<(std::ostream &o, Stack const &i);


#endif
