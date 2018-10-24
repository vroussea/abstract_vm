#include "../includes/Lexer.hpp"
#include "../includes/eOperandType.hpp"

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
            {"int8",   eOperandType::Int8},
            {"int16",  eOperandType::Int16},
            {"int32",  eOperandType::Int32},
            {"float",  eOperandType::Float},
            {"double", eOperandType::Double}
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

std::ostream &operator<<(std::ostream &o, Lexer const &) {
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
    throw LexerExceptions::UnknownIntructionException();
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
    throw LexerExceptions::LexicalErrorException();
}

Token Lexer::findValue(std::string &expression) {
    std::smatch smatch;

    if (std::regex_search(expression, smatch, std::regex("^[0-9]+(.[0-9]+)?"))) {
        std::string value = smatch[0];
        size_t pos = expression.find(value);
        expression.erase(pos, value.length());
        Token token(Token::VALUE);
        token.setTokenValue(value);
        return token;
    }
    throw LexerExceptions::LexicalErrorException();
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
    throw LexerExceptions::LexicalErrorException();
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