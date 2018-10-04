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

bool Lexer::doesExist(std::string expression) {
    if (std::regex_match(expression, std::regex(
            "^(((push|assert) )(((int8|int16|int32)\\([0-9]+\\))|((float|double)\\([0-9]+(\\.[0-9]+)?\\)))|pop|dump|add|sub|mul|div|mod|print|exit)?(;([[:graph:]]|[[:blank:]])*)$")))
        return true;
    return false;
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */



/* ******************************* */
/*            Exceptions           */
/* ******************************* */

const char *Lexer::LexicalErrorException::what() const noexcept {
    return "Lexical error in this line";
}
