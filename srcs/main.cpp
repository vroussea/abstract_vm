#include <iostream>
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
        parser.setErrorMode();
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
    parser.parse(commands.getList());
    return 0;
}