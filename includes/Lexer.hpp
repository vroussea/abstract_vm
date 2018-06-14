#ifndef ABSTRACT_VM_LEXER_HPP
#define ABSTRACT_VM_LEXER_HPP

#include <vector>
#include <iostream>
#include <regex>

class Lexer {
public:
    std::vector<std::string> static getTokens(std::vector<std::string> const &lines);

private:
    std::string getToken(std::string const &line) const;
};

#endif
