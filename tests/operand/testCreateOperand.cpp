#include "../catch.hpp"

#include "../../includes/eOperandType.hpp"
#include "../../srcs/Operand.cpp"

TEST_CASE("test operand type is ok") {
    Operand<char> testInt8(eOperandType::Int8, std::to_string(5));

    REQUIRE(testInt8.getType() == eOperandType::Int8);
}

TEST_CASE("test operand precision is ok") {
    Operand<char> testInt8(eOperandType::Int8, std::to_string(5));

    REQUIRE(testInt8.getPrecision() == static_cast<int>(eOperandType::Int8));
}

TEST_CASE("test operand creation works") {
    auto value = static_cast<char>(5);
    Operand<int> testInt8(eOperandType::Int8, std::to_string(value));
    Operand<int> secondTestInt8(eOperandType::Int8, std::to_string(value));

    REQUIRE(testInt8.toString() == secondTestInt8.toString());
}