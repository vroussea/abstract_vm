
#ifndef ABSTRACT_VM_STACK_HPP
#define ABSTRACT_VM_STACK_HPP


#include <iostream>

class Stack {
public:
    Stack();

    Stack(int);

    Stack(Stack const &src);

    virtual ~Stack();

    Stack &operator=(Stack const &);

    void push(double value);

    void assert(double value);

    void pop();

    void dump();

    void add();

    void sub();

    void mul();

    void div();

    void mod();

    void print();

    void exit();

private:
};

std::ostream &operator<<(std::ostream &o, Stack const &i);


#endif
