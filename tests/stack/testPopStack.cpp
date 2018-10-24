#include "../catch.hpp"
#include "../../includes/Stack.hpp"

TEST_CASE("test pop stack ok") {
    Stack stack;

    stack.push("5", eOperandType::Int8);

    REQUIRE_NOTHROW(stack.pop());
}

TEST_CASE("test pop stack with error") {
    Stack stack;

    REQUIRE_THROWS_AS(stack.pop(), StackExceptions::PopOnEmptyStackException);
}