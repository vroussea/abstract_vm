#include "../catch.hpp"

#include "../../includes/eOperandType.hpp"
#include "../../includes/Operand.hpp"


TEST_CASE("test sub two chars") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, std::to_string('b'), std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
    IOperand *char2 = new Operand<char>(eOperandType::Int8, std::to_string(1), std::numeric_limits<char>::min(), std::numeric_limits<char>::max());

    IOperand const *addResult = (*char1 - *char2);

    REQUIRE(dynamic_cast<const Operand<char> *>(addResult)->toString() == std::to_string('a'));
}

TEST_CASE("test sub short to char") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, std::to_string('C'), std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
    IOperand *short1 = new Operand<short>(eOperandType::Int16, "1", std::numeric_limits<short>::min(), std::numeric_limits<short>::max());

    IOperand const *addResult = (*char1 - *short1);

    REQUIRE(dynamic_cast<const Operand<short> *>(addResult)->toString() == std::to_string('B'));
}

TEST_CASE("test sub two shorts") {
    IOperand *short1 = new Operand<short>(eOperandType::Int16, "10", std::numeric_limits<short>::min(), std::numeric_limits<short>::max());
    IOperand *short2 = new Operand<short>(eOperandType::Int16, "5", std::numeric_limits<short>::min(), std::numeric_limits<short>::max());

    IOperand const *addResult = (*short1 - *short2);

    REQUIRE(dynamic_cast<const Operand<short> *>(addResult)->toString() == "5");
}

TEST_CASE("test sub two ints") {
    IOperand *int1 = new Operand<int>(eOperandType::Int32, "2000000001", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    IOperand *int2 = new Operand<int>(eOperandType::Int32, "1", std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    IOperand const *addResult = (*int1 - *int2);

    REQUIRE(dynamic_cast<const Operand<int> *>(addResult)->toString() == "2000000000");
}

TEST_CASE("test sub two floats") {
    IOperand *float1 = new Operand<float>(eOperandType::Float, "4.1", std::numeric_limits<float>::min(),
                                          std::numeric_limits<float>::max());
    IOperand *float2 = new Operand<float>(eOperandType::Float, "3.1", std::numeric_limits<float>::min(),
                                          std::numeric_limits<float>::max());

    IOperand const *addResult = (*float1 - *float2);

    REQUIRE(std::stof(dynamic_cast<const Operand<float> *>(addResult)->toString()) == 1.0f);
}

TEST_CASE("test sub two doubles") {
    IOperand *double1 = new Operand<double>(eOperandType::Double, "4.1", std::numeric_limits<double>::min(),
                                            std::numeric_limits<double>::max());
    IOperand *double2 = new Operand<double>(eOperandType::Double, "3.1",
                                            std::numeric_limits<double>::min(), std::numeric_limits<double>::max());

    IOperand const *addResult = (*double1 - *double2);

    REQUIRE(std::stod(dynamic_cast<const Operand<double> *>(addResult)->toString()) == 1.0);
}
