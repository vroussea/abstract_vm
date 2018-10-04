#ifndef ABSTRACT_VM_LEXER_HPP
#define ABSTRACT_VM_LEXER_HPP

#include <vector>
#include <iostream>
#include <regex>
#include "Token.hpp"

class Lexer {
public:
    bool doesExist(std::string expression);

    Token getInstruction(std::string &expression);

    class LexicalErrorException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

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
};

#endif
