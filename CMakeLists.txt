cmake_minimum_required(VERSION 3.9)
project(abstract_vm)

set(CMAKE_CXX_STANDARD 11)

set(sourceCode srcs/Commands.cpp srcs/Lexer.cpp tests/testCommands.cpp tests/testLexer.cpp srcs/Token.cpp)

set(testCode tests/testCommands.cpp tests/testLexer.cpp)

add_executable(abstract_vm srcs/main.cpp ${sourceCode})

add_executable(tests ${sourceCode} ${testCode})
