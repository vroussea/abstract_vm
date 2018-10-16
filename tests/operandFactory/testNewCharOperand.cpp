#include "../catch.hpp"
#include "../../includes/OperandFactory.hpp"
#include "../../srcs/Operand.hpp"

TEST_CASE("test new char overflow") {
    OperandFactory operandFactory;

    long max = std::numeric_limits<char>::max();
    max++;

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Int8, std::to_string(max)),
                      OperandExceptions::OverflowException);
}

TEST_CASE("test new char underflow") {
    OperandFactory operandFactory;

    long min = std::numeric_limits<char>::min();
    min--;

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Int8, std::to_string(min)),
                      OperandExceptions::UnderflowException);
}

TEST_CASE("test new char works") {
    OperandFactory operandFactory;


    IOperand const *IOperand = operandFactory.createOperand(eOperandType::Int8, std::to_string('a'));

    REQUIRE(dynamic_cast<Operand<char> const *>(IOperand)->toString() == std::to_string('a'));

    delete IOperand;
}
