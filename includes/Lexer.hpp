#ifndef ABSTRACT_VM_LEXER_HPP
#define ABSTRACT_VM_LEXER_HPP

#include <vector>
#include <iostream>
#include <regex>
#include <map>
#include "Token.hpp"

class Lexer {
public:

    typedef std::map<std::string, int> StringToEnumMap;

    Lexer();

    virtual ~Lexer();

    Token findComment(std::string &expression);

    Token findCommand(std::string &expression);

    Token findType(std::string &expression);

    Token findValue(std::string &expression);

    Token findBracket(std::string &expression);

    class LexicalErrorException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    class UnknownIntructionException : public std::exception {
    public:
        const char *what() const noexcept override;
    };

    const StringToEnumMap &getCommandsMap() const;

    void setCommandsMap(const StringToEnumMap &commandsMap);

    const StringToEnumMap &getTypesMap() const;

    void setTypesMap(const StringToEnumMap &typesMap);

    /*
     *
     * regex
     * gallien
     * ^(((push|assert) )(((int8|int16|int32)\([0-9]+\))|((float|double)\([0-9]+(\.[0-9]+)?\)))|pop|dump|add|sub|mul|div|mod|print|exit)?[[:blank:]]*(;([[:graph:]]|[[:blank:]])*)?
     * moi
     * ^[a-z]+( [a-z]+[0-9]*\([0-9]+(\.[0-9]+)?\))?[[:blank:]]*(;([[:graph:]]|[[:blank:]])*)?
     *
     */

private:
    Lexer(Lexer const &src);

    StringToEnumMap commandsMap;
    StringToEnumMap typesMap;

    Lexer &operator=(Lexer const &);
};

std::ostream &operator<<(std::ostream &o, Lexer const &i);

#endif
