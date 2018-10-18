#include "../catch.hpp"

#include "../../includes/eOperandType.hpp"
#include "../../includes/Operand.hpp"


TEST_CASE("test mul two chars") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, "10", std::numeric_limits<char>::min(),
                                        std::numeric_limits<char>::max());
    IOperand *char2 = new Operand<char>(eOperandType::Int8, "11", std::numeric_limits<char>::min(),
                                        std::numeric_limits<char>::max());

    IOperand const *mulResult = (*char1 * *char2);

    REQUIRE(dynamic_cast<const Operand<char> *>(mulResult)->toString() == std::to_string('n'));
}

TEST_CASE("test mul short to char") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, std::to_string('A'), std::numeric_limits<char>::min(),
                                        std::numeric_limits<char>::max());
    IOperand *short1 = new Operand<short>(eOperandType::Int16, "1", std::numeric_limits<short>::min(),
                                          std::numeric_limits<short>::max());

    IOperand const *mulResult = (*char1 * *short1);

    REQUIRE(dynamic_cast<const Operand<short> *>(mulResult)->toString() == std::to_string('A'));
}

TEST_CASE("test mul int to double") {
    IOperand *double1 = new Operand<double>(eOperandType::Double, "1.1", std::numeric_limits<double>::min(),
                                            std::numeric_limits<double>::max());
    IOperand *int1 = new Operand<int>(eOperandType::Int32, "1", std::numeric_limits<int>::min(),
                                      std::numeric_limits<int>::max());

    IOperand const *mulResult = (*double1 * *int1);

    REQUIRE(std::stof(dynamic_cast<const Operand<double> *>(mulResult)->toString()) == 1.1f);
}

TEST_CASE("test mul two shorts") {
    IOperand *short1 = new Operand<short>(eOperandType::Int16, "10", std::numeric_limits<short>::min(),
                                          std::numeric_limits<short>::max());
    IOperand *short2 = new Operand<short>(eOperandType::Int16, "5", std::numeric_limits<short>::min(),
                                          std::numeric_limits<short>::max());

    IOperand const *mulResult = (*short1 * *short2);

    REQUIRE(dynamic_cast<const Operand<short> *>(mulResult)->toString() == "50");
}

TEST_CASE("test mul two ints") {
    IOperand *int1 = new Operand<int>(eOperandType::Int32, "2000000000", std::numeric_limits<int>::min(),
                                      std::numeric_limits<int>::max());
    IOperand *int2 = new Operand<int>(eOperandType::Int32, "1", std::numeric_limits<int>::min(),
                                      std::numeric_limits<int>::max());

    IOperand const *mulResult = (*int1 * *int2);

    REQUIRE(dynamic_cast<const Operand<int> *>(mulResult)->toString() == "2000000000");
}

TEST_CASE("test mul two floats") {
    IOperand *float1 = new Operand<float>(eOperandType::Float, "1.5f", std::numeric_limits<float>::min(),
                                          std::numeric_limits<float>::max());
    IOperand *float2 = new Operand<float>(eOperandType::Float, "3.1", std::numeric_limits<float>::min(),
                                          std::numeric_limits<float>::max());

    IOperand const *mulResult = (*float1 * *float2);

    REQUIRE(std::stof(dynamic_cast<const Operand<float> *>(mulResult)->toString()) == 4.65f);
}

TEST_CASE("test mul two doubles") {
    IOperand *double1 = new Operand<double>(eOperandType::Double, "1.5", std::numeric_limits<double>::min(),
                                            std::numeric_limits<double>::max());
    IOperand *double2 = new Operand<double>(eOperandType::Double, "0",
                                            std::numeric_limits<double>::min(), std::numeric_limits<double>::max());

    OperandFactory operandFactory;

    IOperand const *mulResult = (*double1 * *double2);

    REQUIRE(std::stod(dynamic_cast<const Operand<double> *>(mulResult)->toString()) == 0);
}
