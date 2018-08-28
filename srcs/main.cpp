#include <iostream>
#include <vector>
#include "../includes/Commands.hpp"
#include "../includes/Lexer.hpp"
#include "../includes/Parser.hpp"

int main(int argc, char **argv) {
    Commands commands;
    Parser parser;

    if (argc > 3 || (argc == 3 && strncmp(argv[1], "-e", 2) != 0)) {
        std::cout << "Error with arguments" << std::endl;
        return 1;
    } else if (argc == 3 && strncmp(argv[1], "-e", 2) == 0) {
        parser.setErrorMode(true);
    }
    try {
        if (argc == 1)
            commands.setCommands();
        else if (argc >= 2)
            commands.setCommands(argv[argc - 1]);
    } catch (std::exception &e) {
        std::cout << "Error at execution" << std::endl;
        return 1;
    }
    std::cout << "### commands :" << std::endl;
    std::cout << commands;
    std::vector<std::string> tokens = Lexer::getTokens(commands.getList());
    std::cout << "### tokens :" << std::endl;
    for (std::string const &token : tokens) {
        std::cout << token << std::endl;
    }
    std::cout << "Exception : " << std::is_scalar<std::exception>::value << std::endl;
    std::cout << "int : " << std::is_scalar<int>::value << std::endl;
    return 0;
}