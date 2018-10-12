#include "../catch.hpp"

#include "../../includes/eOperandType.hpp"
#include "../../srcs/Operand.tpp"

TEST_CASE("test operand type is ok") {
    Operand<char> testInt8(eOperandType::Int8, static_cast<char>(5), CHAR_MIN, CHAR_MAX);

    REQUIRE(testInt8.getType() == eOperandType::Int8);
}

TEST_CASE("test operand precision is ok") {
    Operand<char> testInt8(eOperandType::Int8, static_cast<char>(5), CHAR_MIN, CHAR_MAX);

    REQUIRE(testInt8.getPrecision() == static_cast<int>(eOperandType::Int8));
}

TEST_CASE("test operand creation works") {
    char value = static_cast<auto>(5);
    Operand<int> testInt8(eOperandType::Int8, value, CHAR_MIN, CHAR_MAX);
    Operand<int> secondTestInt8(eOperandType::Int8, value, CHAR_MIN, CHAR_MAX);

    REQUIRE(testInt8.toString() == secondTestInt8.toString());
}