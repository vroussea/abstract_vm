#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../includes/Commands.hpp"

TEST_CASE("Test with file") {
    Commands commands;
    std::string fileName = "commands/test1";
    std::ifstream file(fileName);
    std::string fileText((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());

    commands.setCommands(fileName.data());

    std::stringstream finalText;
    for (const std::string &command : commands.getList())
        finalText << command << "\n";
    REQUIRE(finalText.str() == fileText);
}