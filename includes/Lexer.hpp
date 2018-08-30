#ifndef ABSTRACT_VM_LEXER_HPP
#define ABSTRACT_VM_LEXER_HPP

#include <vector>
#include <iostream>
#include <regex>

class Lexer {
public:
    std::vector<std::string> static getTokens(std::vector<std::string> const &lines);

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
    std::string getToken(std::string const &line) const;
};

#endif
