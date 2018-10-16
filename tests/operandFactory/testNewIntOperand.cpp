#include "../catch.hpp"
#include "../../includes/OperandFactory.hpp"
#include "../../srcs/Operand.hpp"

TEST_CASE("test new int overflow") {
    OperandFactory operandFactory;

    long max = std::numeric_limits<int>::max();
    max++;

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Int32, std::to_string(max)),
                      OperandExceptions::OverflowException);
}

TEST_CASE("test new int underflow") {
    OperandFactory operandFactory;

    long min = std::numeric_limits<int>::min();
    min--;

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Int32, std::to_string(min)),
                      OperandExceptions::UnderflowException);
}

TEST_CASE("test new int works") {
    OperandFactory operandFactory;


    IOperand const *IOperand = operandFactory.createOperand(eOperandType::Int32, "97.5");

    REQUIRE(dynamic_cast<Operand<int> const *>(IOperand)->toString() == "97");

    delete IOperand;
}
