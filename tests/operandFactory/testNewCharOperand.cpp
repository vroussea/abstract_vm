#include "../catch.hpp"
#include "../../includes/OperandFactory.hpp"

TEST_CASE("test new char overflow") {
    OperandFactory operandFactory;

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Int8, "128"), OperandExceptions::OverflowException);
}

TEST_CASE("test new char underflow") {
    OperandFactory operandFactory;

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Int8, "-129"), OperandExceptions::UnderflowException);
}

TEST_CASE("test new char works") {
    OperandFactory operandFactory;


    IOperand const *IOperand = operandFactory.createOperand(eOperandType::Int8, "97");
    Operand<char> const *newOperand = dynamic_cast<Operand<char> const *>(IOperand);


    REQUIRE(newOperand->getValue() == 'a');

    delete newOperand;
}
