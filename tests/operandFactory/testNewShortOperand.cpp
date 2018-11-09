#include "../catch.hpp"
#include "../../includes/OperandFactory.hpp"
#include "../../srcs/Operand.cpp"

TEST_CASE("test new short overflow") {
    OperandFactory operandFactory;

    long max = std::numeric_limits<short>::max();
    max++;

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Int16, std::to_string(max)),
                      OperandExceptions::OverflowException);
}

TEST_CASE("test new short underflow") {
    OperandFactory operandFactory;

    long min = std::numeric_limits<short>::min();
    min--;

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Int16, std::to_string(min)),
                      OperandExceptions::UnderflowException);
}

TEST_CASE("test new short works") {
    OperandFactory operandFactory;


    IOperand const *IOperand = operandFactory.createOperand(eOperandType::Int16, "97");

    REQUIRE(dynamic_cast<Operand<short> const *>(IOperand)->toString() == "97");

    delete IOperand;
}
