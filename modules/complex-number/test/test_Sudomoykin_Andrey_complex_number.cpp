// Copyright 2023 Sudomoykin Andrey

#include <gtest/gtest.h>
#include "include/complex_number.h"

// Test the default constructor
TEST(ComplexNumberTest, DefaultConstructor) {
  ComplexNumber z;
  EXPECT_EQ(z.getRe(), 0.0);
  EXPECT_EQ(z.getIm(), 0.0);
}

// Test the constructor with real and imaginary parts
TEST(ComplexNumberTest, ConstructorWithValues) {
  ComplexNumber z(2.0, -3.0);
  EXPECT_EQ(z.getRe(), 2.0);
  EXPECT_EQ(z.getIm(), -3.0);
}

// Test the copy constructor
TEST(ComplexNumberTest, CopyConstructor) {
  ComplexNumber z1(2.0, -3.0);
  ComplexNumber z2(z1);
  EXPECT_EQ(z2.getRe(), 2.0);
  EXPECT_EQ(z2.getIm(), -3.0);
}

// Test the assignment operator
TEST(ComplexNumberTest, AssignmentOperator) {
  ComplexNumber z1(2.0, -3.0);
  ComplexNumber z2;
  z2 = z1;
  EXPECT_EQ(z2.getRe(), 2.0);
  EXPECT_EQ(z2.getIm(), -3.0);
}

// Test addition operator
TEST(ComplexNumberTest, AdditionOperator) {
  ComplexNumber z1(2.0, -3.0);
  ComplexNumber z2(-1.0, 4.0);
  ComplexNumber sum = z1 + z2;
  EXPECT_EQ(sum.getRe(), 1.0);
  EXPECT_EQ(sum.getIm(), 1.0);
}

// Test subtraction operator
TEST(ComplexNumberTest, SubtractionOperator) {
  ComplexNumber z1(2.0, -3.0);
  ComplexNumber z2(-1.0, 4.0);
  ComplexNumber diff = z1 - z2;
  EXPECT_EQ(diff.getRe(), 3.0);
  EXPECT_EQ(diff.getIm(), -7.0);
}

// Test multiplication operator
TEST(ComplexNumberTest, MultiplicationOperator) {
  ComplexNumber z1(2.0, -3.0);
  ComplexNumber z2(-1.0, 4.0);
  ComplexNumber product = z1 * z2;
  EXPECT_EQ(product.getRe(), 10.0);
  EXPECT_EQ(product.getIm(), 11.0);
}

// Test division operator
TEST(ComplexNumberTest, DivisionOperator) {
    ComplexNumber z1(2.0, -3.0);
    ComplexNumber z2(-1.0, 4.0);
    ComplexNumber quotient = z1 / z2;
    EXPECT_NEAR(quotient.getRe(), -0.8235294117647058, 1e-6);
    EXPECT_NEAR(quotient.getIm(), -0.29411764705882354, 1e-6);
}

// Test equality operator
TEST(ComplexNumberTest, EqualityOperator) {
  ComplexNumber z1(2.0, -3.0);
  ComplexNumber z2(2.0, -3.0);
  EXPECT_TRUE(z1 == z2);
}

// Test inequality operator
TEST(ComplexNumberTest, InequalityOperator) {
  ComplexNumber z1(2.0, -3.0);
  ComplexNumber z2(-1.0, 4.0);
  EXPECT_TRUE(z1 != z2);
}
