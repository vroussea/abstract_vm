#include "../catch.hpp"
#include "../../includes/OperandFactory.hpp"
#include "../../includes/Operand.hpp"

TEST_CASE("test new float overflow") {
    OperandFactory operandFactory;

    long double max = std::numeric_limits<double>::max();

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Float, std::to_string(max)),
                      OperandExceptions::OverflowException);
}

TEST_CASE("test new float underflow") {
    OperandFactory operandFactory;

    long double min = -std::numeric_limits<double>::max();

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Float, std::to_string(min)),
                      OperandExceptions::UnderflowException);
}

TEST_CASE("test new float works") {
    OperandFactory operandFactory;


    IOperand const *IOperand = operandFactory.createOperand(eOperandType::Float, "97.5");

    REQUIRE(std::stod(dynamic_cast<Operand<float> const *>(IOperand)->toString()) == 97.5);

    delete IOperand;
}
