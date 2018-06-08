
#ifndef ABSTRACT_VM_TOKEN_HPP
#define ABSTRACT_VM_TOKEN_HPP

#include <iostream>

class Token {
public:
    Token();

    Token(Token const &src);

    virtual ~Token();

    Token &operator=(Token const &);

    std::string getType() const;

    double getValue() const;

    void setType(std::string type);

    void setValue(double value);

private:
    std::string type;
    double value;
};

std::ostream &operator<<(std::ostream &o, Token const &i);


#endif
