
#include "../includes/Stack.hpp"
#include "../includes/exceptions/StackExceptions.hpp"
#include "../includes/OperandFactory.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

std::ostream &operator<<(std::ostream &o, Stack const &) {
    o << "Nothing";

    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */

void Stack::pushStack(IOperand const *newOperand) {
    this->operandStack.push(newOperand);
}

bool Stack::push(std::string const &value, eOperandType const &operandType) {
    OperandFactory operandFactory;

    pushStack(operandFactory.createOperand(operandType, value));
    return false;
}

bool Stack::assert(std::string const &value, eOperandType const &) {
    if (this->operandStack.empty())
        throw StackExceptions::TooFewValuesException();

    IOperand const *topOperand = this->operandStack.top();

    if (std::stod(topOperand->toString()) != std::stod(value))
        throw StackExceptions::FalseAssertException();
    return false;
}

bool Stack::pop() {
    if (this->operandStack.empty())
        throw StackExceptions::PopOnEmptyStackException();
    IOperand const *toPop = this->operandStack.top();
    this->operandStack.pop();
    delete (toPop);
    return false;

}

bool Stack::dump() {
    std::stack<IOperand const *> copyStack = this->operandStack;

    while (!copyStack.empty()) {
        std::string stringValue = copyStack.top()->toString();
        if (stringValue.size() > 1)
            stringValue.erase(stringValue.find_last_not_of('0') + 1, std::string::npos);
        stringValue.erase(stringValue.find_last_not_of('.') + 1, std::string::npos);
        std::cout << stringValue << std::endl;
        copyStack.pop();
    }
    return false;

}

bool Stack::add() {
    OperandFactory operandFactory;

    if (this->operandStack.size() < 2)
        throw StackExceptions::TooFewValuesException();

    IOperand const *right = this->operandStack.top();
    this->operandStack.pop();

    IOperand const *left = this->operandStack.top();
    this->operandStack.pop();

    pushStack(*left + *right);
    delete (right);
    delete (left);
    return false;

}

bool Stack::sub() {
    OperandFactory operandFactory;

    if (this->operandStack.size() < 2)
        throw StackExceptions::TooFewValuesException();

    IOperand const *right = this->operandStack.top();
    this->operandStack.pop();

    IOperand const *left = this->operandStack.top();
    this->operandStack.pop();

    pushStack(*left - *right);
    delete (right);
    delete (left);
    return false;

}

bool Stack::mul() {
    OperandFactory operandFactory;

    if (this->operandStack.size() < 2)
        throw StackExceptions::TooFewValuesException();

    IOperand const *right = this->operandStack.top();
    this->operandStack.pop();

    IOperand const *left = this->operandStack.top();
    this->operandStack.pop();

    pushStack(*left * *right);
    delete (right);
    delete (left);
    return false;

}

bool Stack::div() {
    OperandFactory operandFactory;

    if (this->operandStack.size() < 2)
        throw StackExceptions::TooFewValuesException();

    IOperand const *right = this->operandStack.top();
    this->operandStack.pop();

    IOperand const *left = this->operandStack.top();
    this->operandStack.pop();

    pushStack(*left / *right);
    delete (right);
    delete (left);
    return false;

}

bool Stack::mod() {
    OperandFactory operandFactory;

    if (this->operandStack.size() < 2)
        throw StackExceptions::TooFewValuesException();

    IOperand const *right = this->operandStack.top();
    this->operandStack.pop();

    IOperand const *left = this->operandStack.top();
    this->operandStack.pop();

    pushStack(*left % *right);
    delete (right);
    delete (left);
    return false;

}

bool Stack::print() {
    if (this->operandStack.empty())
        throw StackExceptions::TooFewValuesException();

    IOperand const *value = this->operandStack.top();

    if (value->getType() != eOperandType::Int8)
        throw StackExceptions::FalseAssertException();

    std::cout << static_cast<char>(std::stoi(value->toString())) << std::endl;
    return false;

}

bool Stack::exit() {
    return true;
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

