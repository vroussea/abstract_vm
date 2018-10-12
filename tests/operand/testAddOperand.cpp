#include "../catch.hpp"

#include "../../includes/eOperandType.hpp"
#include "../../srcs/Operand.tpp"

TEST_CASE("test add two chars") {
    IOperand *char1 = new Operand<char>(eOperandType::Int8, 'A', CHAR_MIN, CHAR_MAX);
    IOperand *char2 = new Operand<char>(eOperandType::Int8, ' ', CHAR_MIN, CHAR_MAX);

    IOperand const *addResult = (*char1 + *char2);

    REQUIRE(dynamic_cast<const Operand<char> *>(addResult)->getValue() == 'a');
}

TEST_CASE("test add two shorts") {
    IOperand *short1 = new Operand<short>(eOperandType::Int16, 10, SHRT_MIN, SHRT_MAX);
    IOperand *short2 = new Operand<short>(eOperandType::Int16, 5, SHRT_MIN, SHRT_MAX);

    IOperand const *addResult = (*short1 + *short2);

    REQUIRE(dynamic_cast<const Operand<short> *>(addResult)->getValue() == 15);
}

TEST_CASE("test add two ints") {
    IOperand *int1 = new Operand<int>(eOperandType::Int32, 2000000000, INT_MIN, INT_MAX);
    IOperand *int2 = new Operand<int>(eOperandType::Int32, 1, INT_MIN, INT_MAX);

    IOperand const *addResult = (*int1 + *int2);

    REQUIRE(dynamic_cast<const Operand<int> *>(addResult)->getValue() == 2000000001);
}

TEST_CASE("test add two floats") {
    IOperand *float1 = new Operand<float>(eOperandType::Float, 1.5f, std::numeric_limits<float>::min(),
                                          std::numeric_limits<float>::max());
    IOperand *float2 = new Operand<float>(eOperandType::Float, 3.0000000001f, std::numeric_limits<float>::min(),
                                          std::numeric_limits<float>::max());

    IOperand const *addResult = (*float1 + *float2);

    REQUIRE(dynamic_cast<const Operand<float> *>(addResult)->getValue() == 4.5000000001f);
}

TEST_CASE("test add two doubles") {
    IOperand *double1 = new Operand<double>(eOperandType::Double, 1.5, std::numeric_limits<double>::min(),
                                            std::numeric_limits<double>::max());
    IOperand *double2 = new Operand<double>(eOperandType::Double, 3.00000000000000000001,
                                            std::numeric_limits<double>::min(), std::numeric_limits<double>::max());

    IOperand const *addResult = (*double1 + *double2);

    REQUIRE(dynamic_cast<const Operand<double> *>(addResult)->getValue() == 4.50000000000000000001);
}