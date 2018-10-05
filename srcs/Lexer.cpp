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

Token Lexer::findComment(std::string &expression) {
    std::smatch smatch;

    if (std::regex_search(expression, smatch, std::regex(";[[:print:]]*"))) {
        size_t pos = expression.find(smatch[0]);
        if (pos != std::string::npos)
            expression.erase(pos, static_cast<unsigned long>(smatch[0].length()));
        return Token(Token::TokenType::COMMENT);
    }
    return Token(Token::TokenType::NULLTYPE);
}

Token Lexer::findCommand(std::string &expression) {
    std::smatch smatch;

    if (std::regex_search(expression, smatch, std::regex("^(push|assert|pop|dump|add|sub|mul|div|mod|print|exit)"))) {
        std::string commandName = smatch[0];
        size_t pos = expression.find(commandName);
        if (pos != std::string::npos)
            expression.erase(pos, commandName.length());
        Token token(Token::COMMAND);
        token.setCommandType(Lexer::commandsMap.at(commandName));
        return token;
    }
    throw UnknownIntructionException();
}

Token Lexer::findType(std::string &expression) {
    std::smatch smatch;

    if (std::regex_search(expression, smatch, std::regex("^ (int(8|16|32)|float|double)"))) {
        std::string typeName = smatch[0];
        size_t pos = expression.find(typeName);
        if (pos != std::string::npos)
            expression.erase(pos, typeName.length());
        typeName.erase(0, 1);
        Token token(Token::TYPE);
        token.setValueType(Lexer::typesMap.at(typeName));
        return token;
    }
    throw LexicalErrorException();
}

Token Lexer::findBracket(std::string &expression) {
    std::smatch smatch;

    if (std::regex_search(expression, smatch, std::regex("^(|)"))) {
        std::string bracket = smatch[0];
        size_t pos = expression.find(bracket);
        if (pos != std::string::npos)
            expression.erase(pos, bracket.length());
        if (bracket == "(") {
            Token token(Token::BRACKET_OPENER);
            return token;
        } else {
            Token token(Token::BRACKET_CLOSER);
            return token;
        }
    }
    throw LexicalErrorException();
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

const char *Lexer::UnknownIntructionException::what() const noexcept {
    return "Unknown instruction in this line";
}

Lexer::StringToEnumMap Lexer::commandsMap = {
        {"push",   Token::CommandType::PUSH},
        {"assert", Token::CommandType::ASSERT},
        {"pop",    Token::CommandType::POP},
        {"dump",   Token::CommandType::DUMP},
        {"add",    Token::CommandType::ADD},
        {"sub",    Token::CommandType::SUB},
        {"mul",    Token::CommandType::MUL},
        {"div",    Token::CommandType::DIV},
        {"mod",    Token::CommandType::MOD},
        {"print",  Token::CommandType::PRINT},
        {"exit",   Token::CommandType::EXIT}
};

Lexer::StringToEnumMap Lexer::typesMap = {
        {"int8",   Token::ValueType::INT8},
        {"int16",  Token::ValueType::INT16},
        {"int32",  Token::ValueType::INT32},
        {"float",  Token::ValueType::FLOAT},
        {"double", Token::ValueType::DOUBLE}
};