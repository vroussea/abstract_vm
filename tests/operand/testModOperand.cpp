#include "../catch.hpp"

#include "../../includes/eOperandType.hpp"
#include "../../srcs/Operand.cpp"

TEST_CASE("test mod two chars with mod by 0 exception") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, "125");
    IOperand *char2 = new Operand<char>(eOperandType::Int8, "0");

    REQUIRE_THROWS_AS(*char1 % *char2, OperandExceptions::ForbiddenMathsException);
}

TEST_CASE("test mod two chars") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, std::to_string('A'));
    IOperand *char2 = new Operand<char>(eOperandType::Int8, std::to_string('B'));

    IOperand const *modResult = (*char1 % *char2);

    REQUIRE(dynamic_cast<const Operand<char> *>(modResult)->toString() == std::to_string('A'));
}

TEST_CASE("test mod short to char") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, std::to_string('A'));
    IOperand *short1 = new Operand<short>(eOperandType::Int16, std::to_string('B'));

    IOperand const *modResult = (*char1 % *short1);

    REQUIRE(dynamic_cast<const Operand<short> *>(modResult)->toString() == std::to_string('A'));
}

TEST_CASE("test mod int to double") {
    IOperand *double1 = new Operand<double>(eOperandType::Double, "1.1");
    IOperand *int1 = new Operand<int>(eOperandType::Int32, "1");

    REQUIRE_THROWS_AS((*double1 % *int1), OperandExceptions::ForbiddenMathsException);
}

TEST_CASE("test mod two shorts") {
    IOperand *short1 = new Operand<short>(eOperandType::Int16, "10");
    IOperand *short2 = new Operand<short>(eOperandType::Int16, "5");

    IOperand const *modResult = (*short1 % *short2);

    REQUIRE(dynamic_cast<const Operand<short> *>(modResult)->toString() == "0");
}

TEST_CASE("test mod two ints") {
    IOperand *int1 = new Operand<int>(eOperandType::Int32, "2000000000");
    IOperand *int2 = new Operand<int>(eOperandType::Int32, "1");

    IOperand const *modResult = (*int1 % *int2);

    REQUIRE(std::stoi(dynamic_cast<const Operand<int> *>(modResult)->toString()) == 0);
}

TEST_CASE("test mod two floats") {
    IOperand *float1 = new Operand<float>(eOperandType::Float, "3f");
    IOperand *float2 = new Operand<float>(eOperandType::Float, "1.5f");

    REQUIRE_THROWS_AS((*float1 % *float2), OperandExceptions::ForbiddenMathsException);
}

TEST_CASE("test mod two doubles") {
    IOperand *double1 = new Operand<double>(eOperandType::Double, "3");
    IOperand *double2 = new Operand<double>(eOperandType::Double, "1.5");

    REQUIRE_THROWS_AS((*double1 % *double2), OperandExceptions::ForbiddenMathsException);
}
