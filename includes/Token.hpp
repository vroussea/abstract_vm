
#ifndef ABSTRACT_VM_TOKKEN_HPP
#define ABSTRACT_VM_TOKKEN_HPP


#include <iostream>

class Token {
public:

    typedef enum {
        COMMAND, VALUE, TYPE, BRACKET_OPENER, BRACKET_CLOSER, COMMENT, NULLTYPE
    } TokenType;

    typedef enum {
        PUSH, ASSERT, POP, DUMP, ADD, SUB, MUL, DIV, MOD, PRINT, EXIT
    } CommandType;

    explicit Token(int _tokkenType);

    Token(int _tokkenType, double _value);

    Token(Token const &src);

    virtual ~Token();

    Token &operator=(Token const &);

    int getTokenType() const;

    void setTokenType(int tokkenType);

    double getTokenValue() const;

    void setTokenValue(double tokkenValue);

    int getCommandType() const;

    void setCommandType(int commandType);

    int getValueType() const;

    void setValueType(int valueType);


private:
    Token();

    int tokenType;
    int commandType;
    int valueType;
    double tokenValue;
};

std::ostream &operator<<(std::ostream &o, Token const &i);


#endif
