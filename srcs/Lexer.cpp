#include "../includes/Lexer.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

/* ******************************* */
/*            Functions            */
/* ******************************* */

std::vector<std::string> Lexer::getTokens(std::vector<std::string> const &lines) {
    std::vector<std::string> tokens;
    Lexer lexer;
    for (std::string const &line : lines) {
        try {
            std::string token = lexer.getToken(line);
            if (!token.empty())
                tokens.push_back(token);
        } catch (std::exception &e) {
            std::cout << "Error : " << e.what() << std::endl;
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
        throw std::exception();
    }
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

const char *Lexer::LexicalErrorException::what() const throw() {
    return "Lexical error in this line";
}
