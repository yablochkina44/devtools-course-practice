// Copyright 2023 Kudryashov Nikita

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Copy_ComplexNumber) {
    // Arrange
    ComplexNumber num1(3.0, 4.0);

    // Act
    ComplexNumber num2(num1);

    // Assert
    EXPECT_EQ(num1.getRe(), num2.getRe());
    EXPECT_EQ(num1.getIm(), num2.getIm());
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Sum_ComplexNumber) {
    // Arrange
    ComplexNumber num1(2.0, 2.0);
    ComplexNumber num2(3.0, 4.0);
    ComplexNumber realRes(5.0, 6.0);

    // Act
    ComplexNumber res = num1 + num2;

    // Assert
    EXPECT_EQ(res, realRes);
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Multiply_ComplexNumber) {
    // Arrange
    ComplexNumber num1(2.0, 2.0);
    ComplexNumber num2(3.0, 4.0);
    ComplexNumber realRes(-2, 14);

    // Act
    ComplexNumber res = num1 * num2;

    // Assert
    EXPECT_EQ(res, realRes);
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Get_Im) {
    // Arrange
    ComplexNumber num(1.0, 5.0);

    // Act
    double im = num.getIm();

    // Assert
    EXPECT_EQ(5.0, im);
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Set_Re) {
    // Arrange
    ComplexNumber num(1.0, 0.0);

    // Act
    num.setRe(5.0);

    // Assert
    EXPECT_EQ(5.0, num.getRe());
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Check_Equal) {
    // Arrange
    ComplexNumber num1(2.0, 4.0);
    ComplexNumber num2(2.0, 4.0);

    // Assert
    EXPECT_EQ(num1, num2);
}

TEST(Kudryashov_Nikita_ComplexNumberTest, Can_Check_NotEqual) {
    // Arrange
    ComplexNumber num1(2.0, 4.0);
    ComplexNumber num2(3.0, 4.0);

    // Act
    // Assert
    EXPECT_NE(num1, num2);
}
