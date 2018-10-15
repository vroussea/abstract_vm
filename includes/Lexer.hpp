#ifndef ABSTRACT_VM_LEXER_HPP
#define ABSTRACT_VM_LEXER_HPP

#include <vector>
#include <iostream>
#include <regex>
#include <map>
#include "Token.hpp"
#include "exceptions/LexerExceptions.hpp"

class Lexer {
public:

    typedef std::map<std::string, int> StringToEnumMap;

    Lexer();

    Lexer(Lexer const &src);

    virtual ~Lexer();

    Lexer &operator=(Lexer const &);

    Token findComment(std::string &expression);

    Token findCommand(std::string &expression);

    Token findType(std::string &expression);

    Token findValue(std::string &expression);

    Token findBracket(std::string &expression);

    const StringToEnumMap &getCommandsMap() const;

    void setCommandsMap(const StringToEnumMap &commandsMap);

    const StringToEnumMap &getTypesMap() const;

    void setTypesMap(const StringToEnumMap &typesMap);

private:

    StringToEnumMap commandsMap;
    StringToEnumMap typesMap;

};

std::ostream &operator<<(std::ostream &o, Lexer const &i);

#endif
