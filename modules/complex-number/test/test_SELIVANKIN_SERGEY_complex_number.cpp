// Copyright 2023 Selivankin Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Selivankin_Sergey_ComplexNumberTest, Test_Equal) {
    // Arrange
    double re = 0.3;
    double im = 8.1;
    ComplexNumber a(re, im);
    ComplexNumber b(re, im);

    // Act & Assert
    EXPECT_EQ(a, b);
}

TEST(Selivankin_Sergey_ComplexNumberTest, Test_Not_Equal) {
    // Arrange
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(1.0, 3.0);

    // Act & Assert
    EXPECT_NE(a, b);
}

TEST(Selivankin_Sergey_ComplexNumberTest, Test_Sum) {
    // Arrange
    ComplexNumber a(1.1, 2.0);
    ComplexNumber b(4.0, 3.8);
    ComplexNumber expected(5.1, 5.8);

    // Act
    ComplexNumber result = a + b;

    // Assert
    ASSERT_EQ(expected.getIm(), result.getIm());
    ASSERT_EQ(expected.getRe(), result.getRe());
}
