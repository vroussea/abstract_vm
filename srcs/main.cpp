#include <iostream>
#include <vector>
#include "Commands.hpp"

int main(int argc, char **argv) {
    Commands commands;

    if (argc > 2) {
        return 1;
    }
    if (argc == 1)
        commands.setCommands();
    else
        commands.setCommands(argv[1]);
    std::cout << commands;
    //lexer_parser(commands);
    return 0;
}