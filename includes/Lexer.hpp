
#ifndef ABSTRACT_VM_LEXER_HPP
#define ABSTRACT_VM_LEXER_HPP

#include <vector>
#include <iostream>

class Lexer {
public:
    Lexer(void);

    Lexer(Lexer const &src);

    virtual ~Lexer(void);

    Lexer &operator=(Lexer const &);

    std::vector<std::string> static getTokens(const std::vector<std::string> lines);

private:
    std::string getToken(std::string const &line) const;

};

std::ostream &operator<<(std::ostream &o, Lexer const &i);


#endif
