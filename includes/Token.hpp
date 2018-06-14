
#ifndef ABSTRACT_VM_TOKEN_HPP
#define ABSTRACT_VM_TOKEN_HPP

#include <iostream>


class Token {
public:
    Token();

    Token(std::string const &_data);

    Token(Token const &src);

    virtual ~Token();

    Token &operator=(Token const &);

    std::string const getData() const;

    void setData(std::string const &data);

    bool operator==(Token const &);

private:
    std::string data;
};

std::ostream &operator<<(std::ostream &o, Token const &i);


#endif
