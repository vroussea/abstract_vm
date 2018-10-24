#include "../catch.hpp"
#include "../../includes/Stack.hpp"

TEST_CASE("test assert stack without error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);

    REQUIRE_NOTHROW(stack.assert("5", eOperandType::Int8));
}

TEST_CASE("test assert stack with error") {
    Stack stack;

    stack.push("5", eOperandType::Int8);

    REQUIRE_THROWS_AS(stack.assert("6", eOperandType::Int8), StackExceptions::FalseAssertException);
}

TEST_CASE("test assert stack with empty stack") {
    Stack stack;

    REQUIRE_THROWS_AS(stack.assert("5", eOperandType::Int8), StackExceptions::TooFewValuesException);
}