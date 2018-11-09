#include "../catch.hpp"
#include "../../includes/OperandFactory.hpp"
#include "../../srcs/Operand.cpp"

TEST_CASE("test new double overflow") {
    OperandFactory operandFactory;

    long double max = std::numeric_limits<long double>::max();

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Double, std::to_string(max)),
                      OperandExceptions::OverflowException);
}

TEST_CASE("test new double underflow") {
    OperandFactory operandFactory;

    long double min = -std::numeric_limits<long double>::max();

    REQUIRE_THROWS_AS(operandFactory.createOperand(eOperandType::Double, std::to_string(min)),
                      OperandExceptions::UnderflowException);
}

TEST_CASE("test new double works") {
    OperandFactory operandFactory;

    IOperand const *IOperand = operandFactory.createOperand(eOperandType::Double, "97.5");

    REQUIRE(std::stod(dynamic_cast<Operand<double> const *>(IOperand)->toString()) == 97.5);

    delete IOperand;
}
