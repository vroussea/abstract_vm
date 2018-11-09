cmake_minimum_required(VERSION 3.9)
project(abstract_vm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(CMAKE_CXX_STANDARD 11)

set(sourceCode srcs/Commands.cpp srcs/Lexer.cpp srcs/Parser.cpp srcs/Token.cpp srcs/Stack.cpp srcs/Operand.cpp srcs/OperandFactory.cpp)

set(exceptionSourceCode srcs/exceptions/OperandExceptions.cpp srcs/exceptions/LexerExceptions.cpp srcs/exceptions/StackExceptions.cpp)

set(testLexerCode tests/lexer/testCommentsLexer.cpp tests/lexer/testCommandsLexer.cpp tests/lexer/testTypeLexer.cpp tests/lexer/testBracketsLexer.cpp tests/lexer/testValuesLexer.cpp)

set(testParserCode tests/parser/testPushAssertParser.cpp tests/parser/testSingleParameterCommandParser.cpp)

set(testOperandCode tests/operand/testCreateOperand.cpp tests/operand/testAddOperand.cpp tests/operand/testSubOperand.cpp tests/operand/testMulOperand.cpp tests/operand/testDivOperand.cpp tests/operand/testModOperand.cpp)

set(testOperandFactoryCode tests/operandFactory/testNewCharOperand.cpp tests/operandFactory/testNewShortOperand.cpp tests/operandFactory/testNewIntOperand.cpp tests/operandFactory/testNewFloatOperand.cpp tests/operandFactory/testNewDoubleOperand.cpp)

set(testStackCode tests/stack/testPushStack.cpp tests/stack/testAssertStack.cpp tests/stack/testPopStack.cpp tests/stack/testOperationsStack.cpp tests/stack/testPrintStack.cpp)

set(testMainCode tests/testMain.cpp)

set(HEADER_FILES includes/Commands.hpp includes/Lexer.hpp includes/Parser.hpp includes/Token.hpp includes/Stack.hpp includes/IOperand.hpp includes/eOperandType.hpp includes/OperandFactory.hpp)

set(EXCEPTION_HEADER_FILES includes/exceptions/OperandExceptions.hpp includes/exceptions/LexerExceptions.hpp includes/exceptions/StackExceptions.hpp)

add_executable(abstract_vm ${HEADER_FILES} ${EXCEPTION_HEADER_FILES} srcs/main.cpp ${sourceCode} ${exceptionSourceCode})

add_executable(testsLexer ${HEADER_FILES} ${EXCEPTION_HEADER_FILES} ${sourceCode} ${exceptionSourceCode} ${testLexerCode} ${testMainCode})

add_executable(testsParser ${HEADER_FILES} ${EXCEPTION_HEADER_FILES} ${sourceCode} ${exceptionSourceCode} ${testParserCode} ${testMainCode})

add_executable(testsOperand ${HEADER_FILES} ${EXCEPTION_HEADER_FILES} ${sourceCode} ${exceptionSourceCode} ${testOperandCode} ${testMainCode})

add_executable(testsOperandFactory ${HEADER_FILES} ${EXCEPTION_HEADER_FILES} ${sourceCode} ${exceptionSourceCode} ${testOperandFactoryCode} ${testMainCode})

add_executable(testsStack ${HEADER_FILES} ${EXCEPTION_HEADER_FILES} ${sourceCode} ${exceptionSourceCode} ${testStackCode} ${testMainCode})

add_executable(testsAll ${HEADER_FILES} ${EXCEPTION_HEADER_FILES} ${sourceCode} ${exceptionSourceCode} ${testLexerCode} ${testParserCode} ${testOperandCode} ${testOperandFactoryCode} ${testStackCode} ${testMainCode})

