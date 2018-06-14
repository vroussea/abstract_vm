#include <regex>
#include "../includes/Lexer.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Lexer::Lexer() = default;

Lexer::~Lexer() = default;

Lexer::Lexer(Lexer const &src) {
    *this = src;
}

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Lexer &Lexer::operator=(Lexer const &rhs) {
    if (this != &rhs) {

    }

    return *this;
}

//std::ostream &operator<<(std::ostream &o, Lexer const &instance) {
//    o << "The value of  is : ";

//    return o;
//}

/* ******************************* */
/*            Functions            */
/* ******************************* */

std::vector<std::string> Lexer::getTokens(const std::vector<std::string> lines) {
    std::vector<std::string> tokens;
    Lexer lexer;
    for (std::string const &line : lines) {
        try {
            std::string token = lexer.getToken(line);
            tokens.push_back(token);
        } catch (std::exception &e) {
            std::cout << e.what();
        }
    }
    return tokens;
}

std::string Lexer::getToken(std::string const &line) const {
    std::regex regex("^[^;^\\n]*");
    std::smatch match;
    if (std::regex_search(line, match, regex)) {
        return match.str();
    } else {
        throw;
    }
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

