// Copyright 2023 Chubenko Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Chubenko_Andrey_ComplexNumberTest, Can_Copy_Constructor) {
    // Arrange
    double re = 3.0;
    double im = 4.0;
    ComplexNumber x(re, im);

    // Act
    ComplexNumber y = x;

    // Assert
    EXPECT_EQ(y.getRe(), re);
    EXPECT_EQ(y.getIm(), im);
}

TEST(Chubenko_Andrey_ComplexNumberTest, Can_Equals) {
    // Arrange
    double re = 3.0;
    double im = 4.0;
    ComplexNumber x(re, im);
    ComplexNumber y(re, im);

    // Assert
    ASSERT_EQ(x, y);
}

TEST(Chubenko_Andrey_ComplexNumberTest, Can_Sum) {
    // Arrange
    double re = 1.0;
    double im = 2.0;
    ComplexNumber x(re, im);
    ComplexNumber y(re, im);

    // Act
    ComplexNumber z = x + y;

    // Assert
    ASSERT_EQ(z.getRe(), 2.0);
    ASSERT_EQ(z.getIm(), 4.0);
}
