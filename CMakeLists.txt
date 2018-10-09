cmake_minimum_required(VERSION 3.9)
project(abstract_vm)

set(CMAKE_CXX_STANDARD 11)

set(sourceCode srcs/Commands.cpp srcs/Lexer.cpp srcs/Parser.cpp srcs/Token.cpp srcs/Stack.cpp)

set(testLexerCode tests/lexer/testCommentsLexer.cpp tests/lexer/testCommandsLexer.cpp tests/lexer/testTypeLexer.cpp tests/lexer/testBracketsLexer.cpp tests/lexer/testValuesLexer.cpp)

set(testParserCode tests/parser/testPushAssertParser.cpp tests/parser/testSingleParameterCommandParser.cpp)

set(testMainCode tests/testCommands.cpp)

set(HEADER_FILES includes/Commands.hpp includes/Lexer.hpp includes/Parser.hpp includes/Token.hpp)

add_executable(abstract_vm ${HEADER_FILES} srcs/main.cpp ${sourceCode})

add_executable(testsLexer ${HEADER_FILES} ${sourceCode} ${testLexerCode} ${testMainCode})

add_executable(testsParser ${HEADER_FILES} ${sourceCode} ${testParserCode} ${testMainCode})

add_executable(testsAll ${HEADER_FILES} ${sourceCode} ${testLexerCode} ${testParserCode} ${testMainCode})

