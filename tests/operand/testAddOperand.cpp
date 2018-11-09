#include "../catch.hpp"

#include "../../includes/eOperandType.hpp"
#include "../../srcs/Operand.cpp"


TEST_CASE("test add two chars") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, std::to_string('A'));
    IOperand *char2 = new Operand<char>(eOperandType::Int8, std::to_string(' '));

    IOperand const *addResult = (*char1 + *char2);

    REQUIRE(dynamic_cast<const Operand<char> *>(addResult)->toString() == std::to_string('a'));
}

TEST_CASE("test add two chars with exception") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, "125");
    IOperand *char2 = new Operand<char>(eOperandType::Int8, "125");

    REQUIRE_THROWS_AS(*char1 + *char2, OperandExceptions::OverflowException);
}

TEST_CASE("test add short to char") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, std::to_string('A'));
    IOperand *short1 = new Operand<short>(eOperandType::Int16, "1");

    IOperand const *addResult = (*char1 + *short1);

    REQUIRE(dynamic_cast<const Operand<short> *>(addResult)->toString() == std::to_string('B'));
}

TEST_CASE("test add int to double") {
    IOperand *double1 = new Operand<double>(eOperandType::Double, "1.1");
    IOperand *int1 = new Operand<int>(eOperandType::Int32, "1");

    IOperand const *addResult = (*double1 + *int1);

    REQUIRE(std::stof(dynamic_cast<const Operand<double> *>(addResult)->toString()) == 2.1f);
}

TEST_CASE("test add two shorts") {
    IOperand *short1 = new Operand<short>(eOperandType::Int16, "10");
    IOperand *short2 = new Operand<short>(eOperandType::Int16, "5");

    IOperand const *addResult = (*short1 + *short2);

    REQUIRE(dynamic_cast<const Operand<short> *>(addResult)->toString() == "15");
}

TEST_CASE("test add two ints") {
    IOperand *int1 = new Operand<int>(eOperandType::Int32, "2000000000");
    IOperand *int2 = new Operand<int>(eOperandType::Int32, "1");

    IOperand const *addResult = (*int1 + *int2);

    REQUIRE(std::stoi(dynamic_cast<const Operand<int> *>(addResult)->toString()) == 2000000001);
}

TEST_CASE("test add two floats") {
    IOperand *float1 = new Operand<float>(eOperandType::Float, "1.5f");
    IOperand *float2 = new Operand<float>(eOperandType::Float, "3.1");

    IOperand const *addResult = (*float1 + *float2);

    REQUIRE(std::stof(dynamic_cast<const Operand<float> *>(addResult)->toString()) == 4.6f);
}

TEST_CASE("test add two doubles") {
    IOperand *double1 = new Operand<double>(eOperandType::Double, "1.5");
    IOperand *double2 = new Operand<double>(eOperandType::Double, "3.1");

    IOperand const *addResult = (*double1 + *double2);

    REQUIRE(std::stod(dynamic_cast<const Operand<double> *>(addResult)->toString()) == 4.6);
}
