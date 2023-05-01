// Copyright 2023 Bochkarev Vladimir

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bochkarev_Vladimir_ComplexNumberTest, Test_Substruct) {
    // Arrange
    ComplexNumber a(30.5, 10.9);
    ComplexNumber b(10.9, 30.5);
    ComplexNumber ans(19.6, -19.6);

    // Act
    ComplexNumber result = a - b;

    // Assert
    ASSERT_EQ(ans.getIm(), result.getIm());
    ASSERT_EQ(ans.getRe(), result.getRe());
}

TEST(Bochkarev_Vladimir_ComplexNumberTest, Test_Negative_Mult) {
    // Arrange
    ComplexNumber a(-1.0, -1.0);
    ComplexNumber b(-1.0, -1.0);
    ComplexNumber ans(0.0, 2.0);

    // Act
    ComplexNumber result = a * b;

    // Assert
    ASSERT_EQ(ans.getIm(), result.getIm());
    ASSERT_EQ(ans.getRe(), result.getRe());
}

TEST(Bochkarev_Vladimir_ComplexNumberTest, Test_Can_Multi_Sum) {
    // Arrange
    ComplexNumber a(2.0, 3.0);
    ComplexNumber b(5.0, -7.0);
    ComplexNumber c(3.0, 2.0);
    ComplexNumber ans(10.0, -2.0);

    // Act
    ComplexNumber result = a + b + c;

    // Assert
    ASSERT_EQ(ans.getIm(), result.getIm());
    ASSERT_EQ(ans.getRe(), result.getRe());
}

TEST(Bochkarev_Vladimir_ComplexNumberTest, Test_Division) {
    // Arrange
    ComplexNumber a(5, 5);
    ComplexNumber b(5, -5);
    ComplexNumber ans(0, 1);

    // Act
    ComplexNumber result = a / b;

    // Assert
    ASSERT_EQ(ans.getIm(), result.getIm());
    ASSERT_EQ(ans.getRe(), result.getRe());
}
