#include <iostream>
#include <vector>
#include "../includes/Commands.hpp"
#include "../includes/Lexer.hpp"

int main(int argc, char **argv) {
    Commands commands;

    if (argc > 2) {
        return 1;
    }
    if (argc == 1)
        commands.setCommands();
    else
        commands.setCommands(argv[1]);
    std::cout << "### commands :" << std::endl;
    std::cout << commands;
    std::vector<std::string> tokens = Lexer::getTokens(commands.getList());
    std::cout << "### tokens :" << std::endl;
    for (std::string const &token : tokens) {
        std::cout << token << std::endl;
    }
    return 0;
}