#include "../catch.hpp"
#include "../../includes/Stack.hpp"

TEST_CASE("test print stack with not enough values error") {
    Stack stack;

    REQUIRE_THROWS_AS(stack.print(), StackExceptions::TooFewValuesException);
}

TEST_CASE("test print stack with too big type") {
    Stack stack;

    stack.push("128", eOperandType::Int16);

    REQUIRE_THROWS_AS(stack.print(), StackExceptions::FalseAssertException);
}

TEST_CASE("test print stack with normal value") {
    Stack stack;

    stack.push("97", eOperandType::Int8);

    REQUIRE_NOTHROW(stack.print());
}

TEST_CASE("test print stack with negative value") {
    Stack stack;

    stack.push("-5", eOperandType::Int8);

    REQUIRE_NOTHROW(stack.print());
}