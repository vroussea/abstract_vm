cmake_minimum_required(VERSION 3.9)
project(abstract_vm)

set(CMAKE_CXX_STANDARD 11)

set(sourceCode srcs/Commands.cpp srcs/Lexer.cpp srcs/Parser.cpp)

set(testCode tests/testCommands.cpp tests/testLexer.cpp)

set(HEADER_FILES includes/Commands.hpp includes/Lexer.hpp includes/Parser.hpp)

add_executable(abstract_vm ${HEADER_FILES} srcs/main.cpp ${sourceCode})

add_executable(tests ${HEADER_FILES} ${sourceCode} ${testCode})
