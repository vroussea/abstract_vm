#include "../catch.hpp"
#include "../../includes/Stack.hpp"

TEST_CASE("test add stack without error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);
    stack.push("5", eOperandType::Int8);
    stack.add();

    REQUIRE_NOTHROW(stack.assert("10", eOperandType::Int8), eOperandType::Int8);
}

TEST_CASE("test add stack with error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);

    REQUIRE_THROWS_AS(stack.add(), StackExceptions::TooFewValuesException);
}

TEST_CASE("test sub stack without error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);
    stack.push("5", eOperandType::Int8);
    stack.sub();

    REQUIRE_NOTHROW(stack.assert("00", eOperandType::Int8), eOperandType::Int8);
}

TEST_CASE("test sub stack with error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);

    REQUIRE_THROWS_AS(stack.sub(), StackExceptions::TooFewValuesException);
}

TEST_CASE("test mul stack without error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);
    stack.push("5", eOperandType::Int8);
    stack.mul();

    REQUIRE_NOTHROW(stack.assert("25", eOperandType::Int8), eOperandType::Int8);
}

TEST_CASE("test mul stack with error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);

    REQUIRE_THROWS_AS(stack.mul(), StackExceptions::TooFewValuesException);
}

TEST_CASE("test div stack without error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);
    stack.push("5", eOperandType::Int8);
    stack.div();

    REQUIRE_NOTHROW(stack.assert("1", eOperandType::Int8), eOperandType::Int8);
}

TEST_CASE("test div stack with error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);

    REQUIRE_THROWS_AS(stack.div(), StackExceptions::TooFewValuesException);
}

TEST_CASE("test div stack with div by 0") {
    Stack stack;

    stack.push("5", eOperandType::Int8);
    stack.push("0", eOperandType::Int8);

    REQUIRE_THROWS_AS(stack.div(), OperandExceptions::ForbiddenMathsException);
}

TEST_CASE("test mod stack without error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);
    stack.push("5", eOperandType::Int8);
    stack.mod();

    REQUIRE_NOTHROW(stack.assert("0", eOperandType::Int8), eOperandType::Int8);
}

TEST_CASE("test mod stack with error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);

    REQUIRE_THROWS_AS(stack.mod(), StackExceptions::TooFewValuesException);
}

TEST_CASE("test mod stack with mod by 0") {
    Stack stack;

    stack.push("5", eOperandType::Int8);
    stack.push("0", eOperandType::Int8);

    REQUIRE_THROWS_AS(stack.mod(), OperandExceptions::ForbiddenMathsException);
}