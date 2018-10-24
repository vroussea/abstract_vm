
#include "../includes/Parser.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Parser::Parser() {
    this->lineNumber = 1;

    this->errorModeMethods = &Parser::withoutErrorMode;
    this->instructionMethods.at(0) = &Parser::pushAssertCommand;
    this->instructionMethods.at(1) = &Parser::littleCommand;

    this->paramStackMethods.at(0) = &Stack::push;
    this->paramStackMethods.at(1) = &Stack::assert;

    this->littleStackMethods.at(2) = &Stack::pop;
    this->littleStackMethods.at(3) = &Stack::dump;
    this->littleStackMethods.at(4) = &Stack::add;
    this->littleStackMethods.at(5) = &Stack::sub;
    this->littleStackMethods.at(6) = &Stack::mul;
    this->littleStackMethods.at(7) = &Stack::div;
    this->littleStackMethods.at(8) = &Stack::mod;
    this->littleStackMethods.at(9) = &Stack::print;
    this->littleStackMethods.at(10) = &Stack::exit;
}

Parser::Parser(Parser const &src) {
    *this = src;
}

Parser::~Parser() = default;

/* ******************************* */
/*       operators  overload       */
/* ******************************* */

Parser &Parser::operator=(Parser const &rhs) {
    if (this != &rhs) {
        this->lexer = rhs.lexer;
        this->errorModeMethods = rhs.errorModeMethods;
    }

    return *this;
}

std::ostream &operator<<(std::ostream &o, Parser const &) {
    o << "Parser" << std::endl;
    return o;
}

/* ******************************* */
/*            Functions            */
/* ******************************* */

bool Parser::pushAssertCommand(std::string expression, Token commandToken) {
    try {
        Token typeToken = lexer.findType(expression);
        if (lexer.findBracket(expression).getTokenType() != Token::BRACKET_OPENER)
            throw LexerExceptions::LexicalErrorException();
        Token valueToken = lexer.findValue(expression);
        if (lexer.findBracket(expression).getTokenType() != Token::BRACKET_CLOSER)
            throw LexerExceptions::LexicalErrorException();
        if (!expression.empty())
            throw LexerExceptions::LexicalErrorException();
        return (stack->*paramStackMethods[commandToken.getCommandType()])(valueToken.getTokenValue(),
                                                                          static_cast<eOperandType>(typeToken.getValueType()));
    } catch (LexerExceptions::LexicalErrorException const &e) {
        throw e;
    } catch (std::exception const &e) {
        throw e;
    }
}

bool Parser::littleCommand(std::string expression, Token commandToken) {
    try {
        if (!expression.empty())
            throw LexerExceptions::LexicalErrorException();
        return (stack->*littleStackMethods[commandToken.getCommandType()])();
    } catch (LexerExceptions::LexicalErrorException const &e) {
        throw e;
    } catch (std::exception const &e) {
        throw e;
    }
}

void Parser::setErrorMode() {
    this->errorModeMethods = &Parser::withErrorMode;
}

void Parser::withErrorMode(std::string whatHappened) {
    std::stringstream sstream;
    sstream << "line " << this->lineNumber << " : " << whatHappened << std::endl;
    this->allErrors.push_back(sstream.str());
}

void Parser::withoutErrorMode(std::string whatHappened) {
    std::cerr << "line " << this->lineNumber << " : " << whatHappened << std::endl;
    exit(EXIT_FAILURE);
}

void Parser::parse(std::vector<std::string> list) {
    bool isExit = false;
    for (std::string const &line : list) {
        std::string expression = line;
        lexer.findComment(expression);
        try {
            Token commandToken = this->lexer.findCommand(expression);
            if ((this->*instructionMethods[commandToken.getCommandType() > 1 ? 1 : 0])(expression, commandToken)) {
                isExit = true;
                break;
            }
        } catch (std::exception const &e) {
            (this->*errorModeMethods)(e.what());
        }
        lineNumber++;
    }
    if (!isExit) {
        LexerExceptions::NoExitInstructionException noExitInstructionException;
        (this->*errorModeMethods)(noExitInstructionException.what());
    }
    if (!this->allErrors.empty())
        for (std::string const &error : this->allErrors)
            std::cerr << error;
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */

/* ******************************* */
/*            Exceptions           */
/* ******************************* */



