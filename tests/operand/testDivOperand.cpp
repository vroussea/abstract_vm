#include "../catch.hpp"

#include "../../includes/eOperandType.hpp"
#include "../../includes/Operand.hpp"

TEST_CASE("test div two chars with div by 0 exception") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, "125", std::numeric_limits<char>::min(),
                                        std::numeric_limits<char>::max());
    IOperand *char2 = new Operand<char>(eOperandType::Int8, "0", std::numeric_limits<char>::min(),
                                        std::numeric_limits<char>::max());

    REQUIRE_THROWS_AS(*char1 / *char2, OperandExceptions::ForbiddenMathsException);
}

TEST_CASE("test div two chars") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, std::to_string('A'), std::numeric_limits<char>::min(),
                                        std::numeric_limits<char>::max());
    IOperand *char2 = new Operand<char>(eOperandType::Int8, "1", std::numeric_limits<char>::min(),
                                        std::numeric_limits<char>::max());

    IOperand const *divResult = (*char1 / *char2);

    REQUIRE(dynamic_cast<const Operand<char> *>(divResult)->toString() == std::to_string('A'));
}

TEST_CASE("test div short to char") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, std::to_string('A'), std::numeric_limits<char>::min(),
                                        std::numeric_limits<char>::max());
    IOperand *short1 = new Operand<short>(eOperandType::Int16, "1", std::numeric_limits<short>::min(),
                                          std::numeric_limits<short>::max());

    IOperand const *divResult = (*char1 / *short1);

    REQUIRE(dynamic_cast<const Operand<short> *>(divResult)->toString() == std::to_string('A'));
}

TEST_CASE("test div int to double") {
    IOperand *double1 = new Operand<double>(eOperandType::Double, "1.1", std::numeric_limits<double>::min(),
                                            std::numeric_limits<double>::max());
    IOperand *int1 = new Operand<int>(eOperandType::Int32, "1", std::numeric_limits<int>::min(),
                                      std::numeric_limits<int>::max());

    IOperand const *divResult = (*double1 / *int1);

    REQUIRE(std::stof(dynamic_cast<const Operand<double> *>(divResult)->toString()) == 1.1f);
}

TEST_CASE("test div two shorts") {
    IOperand *short1 = new Operand<short>(eOperandType::Int16, "10", std::numeric_limits<short>::min(),
                                          std::numeric_limits<short>::max());
    IOperand *short2 = new Operand<short>(eOperandType::Int16, "5", std::numeric_limits<short>::min(),
                                          std::numeric_limits<short>::max());

    IOperand const *divResult = (*short1 / *short2);

    REQUIRE(dynamic_cast<const Operand<short> *>(divResult)->toString() == "2");
}

TEST_CASE("test div two ints") {
    IOperand *int1 = new Operand<int>(eOperandType::Int32, "2000000000", std::numeric_limits<int>::min(),
                                      std::numeric_limits<int>::max());
    IOperand *int2 = new Operand<int>(eOperandType::Int32, "1", std::numeric_limits<int>::min(),
                                      std::numeric_limits<int>::max());

    IOperand const *divResult = (*int1 / *int2);

    REQUIRE(dynamic_cast<const Operand<int> *>(divResult)->toString() == "2000000000");
}

TEST_CASE("test div two floats") {
    IOperand *float1 = new Operand<float>(eOperandType::Float, "3f", std::numeric_limits<float>::min(),
                                          std::numeric_limits<float>::max());
    IOperand *float2 = new Operand<float>(eOperandType::Float, "1.5f", std::numeric_limits<float>::min(),
                                          std::numeric_limits<float>::max());

    IOperand const *divResult = (*float1 / *float2);

    REQUIRE(std::stof(dynamic_cast<const Operand<float> *>(divResult)->toString()) == 2.0f);
}

TEST_CASE("test div two doubles") {
    IOperand *double1 = new Operand<double>(eOperandType::Double, "3", std::numeric_limits<double>::min(),
                                            std::numeric_limits<double>::max());
    IOperand *double2 = new Operand<double>(eOperandType::Double, "1.5",
                                            std::numeric_limits<double>::min(), std::numeric_limits<double>::max());

    IOperand const *divResult = (*double1 / *double2);

    REQUIRE(std::stod(dynamic_cast<const Operand<double> *>(divResult)->toString()) == 2);
}
