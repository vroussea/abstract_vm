
#include "../includes/Parser.hpp"

/* ******************************* */
/*    Constructors & destructor    */
/* ******************************* */

Parser::Parser() {
    this->errorModeMethods = &Parser::withoutErrorMode;
    Parser::ParserMethodPointer addMethod = &Parser::pushAssertCommand;
    this->instructionMethods.push_back(addMethod);
    addMethod = &Parser::littleCommand;
    this->instructionMethods.push_back(addMethod);

    Parser::ParamStackMethodPointer addParamMethod = &Stack::push;
    this->paramStackMethods.push_back(addParamMethod);
    addParamMethod = &Stack::assert;
    this->paramStackMethods.push_back(addParamMethod);

    Parser::SimpleStackMethodPointer addLittleMethod = &Stack::pop;
    this->littleStackMethods.push_back(addLittleMethod);
    this->littleStackMethods.push_back(addLittleMethod);
    this->littleStackMethods.push_back(addLittleMethod);
    addLittleMethod = &Stack::dump;
    this->littleStackMethods.push_back(addLittleMethod);
    addLittleMethod = &Stack::add;
    this->littleStackMethods.push_back(addLittleMethod);
    addLittleMethod = &Stack::sub;
    this->littleStackMethods.push_back(addLittleMethod);
    addLittleMethod = &Stack::mul;
    this->littleStackMethods.push_back(addLittleMethod);
    addLittleMethod = &Stack::div;
    this->littleStackMethods.push_back(addLittleMethod);
    addLittleMethod = &Stack::mod;
    this->littleStackMethods.push_back(addLittleMethod);
    addLittleMethod = &Stack::print;
    this->littleStackMethods.push_back(addLittleMethod);
    addLittleMethod = &Stack::exit;
    this->littleStackMethods.push_back(addLittleMethod);
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

void Parser::pushAssertCommand(std::string expression, Token commandToken) {
    try {
        Token typeToken = lexer.findType(expression);
        if (lexer.findBracket(expression).getTokenType() != Token::BRACKET_OPENER)
            throw Lexer::LexicalErrorException();
        Token valueToken = lexer.findValue(expression);
        if (lexer.findBracket(expression).getTokenType() != Token::BRACKET_CLOSER)
            throw Lexer::LexicalErrorException();
        if (!expression.empty())
            throw Lexer::LexicalErrorException();
        paramStackMethods[commandToken.getTokenType()];
    } catch (Lexer::LexicalErrorException const &e) {
        throw e;
    } catch (std::exception const &e) {
        throw e;
    }
}

void Parser::littleCommand(std::string expression, Token commandToken) {
    try {
        if (!expression.empty())
            throw Lexer::LexicalErrorException();
        littleStackMethods[commandToken.getTokenType()];
    } catch (Lexer::LexicalErrorException const &e) {
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
    this->lineNumber = 1;
    for (std::string const &line : list) {
        std::string expression = line;
        lexer.findComment(expression);
        try {
            Token commandToken = this->lexer.findCommand(expression);
            (this->*instructionMethods[commandToken.getCommandType()])(expression, commandToken);
        } catch (std::exception const &e) {
            (this->*errorModeMethods)(e.what());
        }
        lineNumber++;
    }
    if (!this->allErrors.empty())
        for (std::string const &error : this->allErrors)
            std::cerr << error;
}

/* ******************************* */
/*            Accessors            */
/* ******************************* */

const Lexer &Parser::getLexer() const {
    return lexer;
}

void Parser::setLexer(const Lexer &lexer) {
    Parser::lexer = lexer;
}

/* ******************************* */
/*            Exceptions           */
/* ******************************* */

const char *Parser::OverflowException::what() const noexcept {
    return "Overflow in this line";
}

const char *Parser::UnderflowException::what() const noexcept {
    return "Underflow in this line";
}

const char *Parser::PopOnEmptyStackException::what() const noexcept {
    return "Pop on empty stack in this line";
}

const char *Parser::ForbiddenMathsException::what() const noexcept {
    return "Division/modulo by 0 in this line";
}

const char *Parser::NoExitInstructionException::what() const noexcept {
    return "No exit instructions in the commands";
}

const char *Parser::FalseAssertException::what() const noexcept {
    return "False assertion in this line";
}

const char *Parser::TooFewValuesException::what() const noexcept {
    return "Not enough values do to the operation in this line";
}