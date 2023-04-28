// Copyright 2023 Nikolaev Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Nikolaev_Alexander_ComplexNumberTest, Can_Copy_Constructor) {
    // Arrange
    double re = 3.0;
    double im = 4.0;
    ComplexNumber a(re, im);

    // Act
    ComplexNumber b = a;

    // Assert
    EXPECT_EQ(b.getRe(), re);
    EXPECT_EQ(b.getIm(), im);
}

TEST(Nikolaev_Alexander_ComplexNumberTest, Can_Equals) {
    // Arrange
    double re = 3.0;
    double im = 4.0;
    ComplexNumber a(re, im);
    ComplexNumber b(re, im);

    // Act
    bool result = (a == b);

    // Assert
    ASSERT_TRUE(result);
}

TEST(Nikolaev_Alexander_ComplexNumberTest, Can_Sum) {
    // Arrange
    double re = 1.0;
    double im = 2.0;
    ComplexNumber a(re, im);
    ComplexNumber b(re, im);

    // Act
    ComplexNumber c = a + b;

    // Assert
    ASSERT_EQ(c.getRe(), 2.0);
    ASSERT_EQ(c.getIm(), 4.0);
}
