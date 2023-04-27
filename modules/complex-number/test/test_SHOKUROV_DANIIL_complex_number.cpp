// Copyright 2023 Kandrin Alexey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shokurov_Daniil_ComplexNumberTest, Can_create_ComplexNumber) {
    // Arrange
    double real = 5.0, im = 2.0;

    // Assert
    EXPECT_NO_THROW(ComplexNumber z(real, im));
}

TEST(Shokurov_Daniil_ComplexNumberTest, New_number_equal_null) {
    // Arrange
    ComplexNumber z;

    // Assert
    EXPECT_DOUBLE_EQ((z.getRe()), 0.0);
    EXPECT_DOUBLE_EQ((z.getIm()), 0.0);
}

TEST(Shokurov_Daniil_ComplexNumberTest, dont_divide_by_zero) {
    // Arrange
    double re = 1.0, im = -2.0;
    ComplexNumber z1{ re, im };
    ComplexNumber z2{ 0.0, 0.0 };
    ComplexNumber z;

    // Assert
    ASSERT_ANY_THROW(z = z1 / z2);
}

TEST(Shokurov_Daniil_ComplexNumberTest, sum_is_correct) {
    // Arrange
    ComplexNumber z, ans{ 3.0, 5.0 };
    ComplexNumber z1{ 1.0, 2.0 };
    ComplexNumber z2{ 2.0, 3.0 };

    // Act
    z = z1 + z2;

    // Assert
    EXPECT_DOUBLE_EQ(ans.getRe(), z.getRe());
    EXPECT_DOUBLE_EQ(ans.getIm(), z.getIm());
}

TEST(Shokurov_Daniil_ComplexNumberTest, div_complex_numbers_is_correct) {
    // Arrange
    ComplexNumber z, ans{ 1.0, 1.0 };
    ComplexNumber z1{ 3.0, 1.0 };
    ComplexNumber z2{ 2.0, -1.0 };

    // Act
    z = z1 / z2;

    // Assert
    EXPECT_DOUBLE_EQ(ans.getRe(), z.getRe());
    EXPECT_DOUBLE_EQ(ans.getIm(), z.getIm());
}

TEST(Shokurov_Daniil_ComplexNumberTest, sub_is_correct) {
    // Arrange
    ComplexNumber z, ans{ 1.0, 2.0 };
    ComplexNumber z1{ 3.0, 5.0 };
    ComplexNumber z2{ 2.0, 3.0 };

    // Act
    z = z1 - z2;

    // Assert
    EXPECT_DOUBLE_EQ(ans.getRe(), z.getRe());
    EXPECT_DOUBLE_EQ(ans.getIm(), z.getIm());
}

TEST(Shokurov_Daniil_ComplexNumberTest, mul_real_numbers_is_correct) {
    // Arrange
    ComplexNumber z, ans{ 2.0, 0.0 };
    ComplexNumber z1{ 1.0, 0.0 };
    ComplexNumber z2{ 2.0, 0.0 };

    // Act
    z = z1 * z2;

    // Assert
    EXPECT_DOUBLE_EQ(ans.getRe(), z.getRe());
    EXPECT_DOUBLE_EQ(ans.getIm(), z.getIm());
}

TEST(Shokurov_Daniil_ComplexNumberTest, div_real_numbers_is_correct) {
    // Arrange
    ComplexNumber z, ans{ 2.0, 0.0 };
    ComplexNumber z1{ 2.0, 0.0 };
    ComplexNumber z2{ 1.0, 0.0 };

    // Act
    z = z1 / z2;

    // Assert
    EXPECT_DOUBLE_EQ(ans.getRe(), z.getRe());
    EXPECT_DOUBLE_EQ(ans.getIm(), z.getIm());
}

TEST(Shokurov_Daniil_ComplexNumberTest, mul_complex_numbers_is_correct) {
    // Arrange
    ComplexNumber z, ans{ 5.0, 5.0 };
    ComplexNumber z1{ 1.0, 3.0 };
    ComplexNumber z2{ 2.0, -1.0 };

    // Act
    z = z1 * z2;

    // Assert
    EXPECT_DOUBLE_EQ(ans.getRe(), z.getRe());
    EXPECT_DOUBLE_EQ(ans.getIm(), z.getIm());
}
