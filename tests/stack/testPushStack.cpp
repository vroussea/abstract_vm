#include "../catch.hpp"
#include "../../includes/Stack.hpp"

TEST_CASE("test push stack without error") {
    Stack stack;

    REQUIRE_NOTHROW(stack.push("5", eOperandType::Int8));
}