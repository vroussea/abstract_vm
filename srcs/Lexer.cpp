#include "../includes/Lexer.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Lexer::Lexer() {
    this->commandsMap = {
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

    this->typesMap = {
            {"int8",   Token::ValueType::INT8},
            {"int16",  Token::ValueType::INT16},
            {"int32",  Token::ValueType::INT32},
            {"float",  Token::ValueType::FLOAT},
            {"double", Token::ValueType::DOUBLE}
    };
}

Lexer::Lexer(Lexer const &src) {
    *this = src;
}

Lexer::~Lexer() = default;

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Lexer &Lexer::operator=(Lexer const &rhs) {
    if (this != &rhs) {
        this->setCommandsMap(rhs.getCommandsMap());
        this->setTypesMap(rhs.getTypesMap());
    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, Lexer const &instance) {
    o << "Lexer" << std::endl;
    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */

Token Lexer::findComment(std::string &expression) {
    std::smatch smatch;

    if (std::regex_search(expression, smatch, std::regex(";[[:print:]]*"))) {
        size_t pos = expression.find(smatch[0]);
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
        expression.erase(pos, commandName.length());
        Token token(Token::COMMAND);
        token.setCommandType(getCommandsMap().at(commandName));
        return token;
    }
    throw UnknownIntructionException();
}

Token Lexer::findType(std::string &expression) {
    std::smatch smatch;

    if (std::regex_search(expression, smatch, std::regex("^ (int(8|16|32)|float|double)"))) {
        std::string typeName = smatch[0];
        size_t pos = expression.find(typeName);
        expression.erase(pos, typeName.length());
        typeName.erase(0, 1);
        Token token(Token::TYPE);
        token.setValueType(getTypesMap().at(typeName));
        return token;
    }
    throw LexicalErrorException();
}

Token Lexer::findValue(std::string &expression) {
    std::smatch smatch;

    if (std::regex_search(expression, smatch, std::regex("^[0-9]+(.[0-9]+)?"))) {
        std::string value = smatch[0];
        size_t pos = expression.find(value);
        expression.erase(pos, value.length());
        Token token(Token::VALUE);
        token.setTokenValue(std::stod(value));
        return token;
    }
    throw LexicalErrorException();
}

Token Lexer::findBracket(std::string &expression) {
    std::smatch smatch;

    if (std::regex_search(expression, smatch, std::regex("^\\(|\\)"))) {
        std::string bracket = smatch[0];
        size_t pos = expression.find(bracket);
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

const Lexer::StringToEnumMap &Lexer::getCommandsMap() const {
    return commandsMap;
}

void Lexer::setCommandsMap(const Lexer::StringToEnumMap &commandsMap) {
    Lexer::commandsMap = commandsMap;
}

const Lexer::StringToEnumMap &Lexer::getTypesMap() const {
    return typesMap;
}

void Lexer::setTypesMap(const Lexer::StringToEnumMap &typesMap) {
    Lexer::typesMap = typesMap;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

const char *Lexer::LexicalErrorException::what() const noexcept {
    return "Lexical error in this line";
}

const char *Lexer::UnknownIntructionException::what() const noexcept {
    return "Unknown instruction in this line";
}