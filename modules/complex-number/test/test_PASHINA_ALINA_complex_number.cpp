// Copyright 2023 Pashina ALina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pashina_Alina_ComplexNumberTest, Can_Sum_Pos_Complex) {
  double re1 = 12.0;
  double im1 = 3.0;
  double re2 = 1.0;
  double im2 = 9.0;

  ComplexNumber num1(re1, im1);
  ComplexNumber num2(re2, im2);

  EXPECT_EQ(num1 + num2, ComplexNumber(13, 12));
}

TEST(Pashina_Alina_ComplexNumberTest, Can_Sum_Neg_Complex) {
  double re1 = -7.0;
  double im1 = -5.0;
  double re2 = -3.0;
  double im2 = -1.0;

  ComplexNumber num1(re1, im1);
  ComplexNumber num2(re2, im2);

  EXPECT_EQ(num1 + num2, ComplexNumber(-10.0, -6.0));
}

TEST(Pashina_Alina_ComplexNumberTest, Can_Substract_Neg_Complex) {
  double re1 = 19.0;
  double im1 = 22.0;
  double re2 = -6.0;
  double im2 = -2.0;

  ComplexNumber num1(re1, im1);
  ComplexNumber num2(re2, im2);

  EXPECT_EQ(num1 - num2, ComplexNumber(25.0, 24.0));
}

TEST(Pashina_Alina_ComplexNumberTest, Can_Substract_Smaller_Complex) {
  double re1 = 16.0;
  double im1 = 8.0;
  double re2 = 11.0;
  double im2 = 2.0;

  ComplexNumber num1(re1, im1);
  ComplexNumber num2(re2, im2);

  EXPECT_EQ(num1 - num2, ComplexNumber(5.0, 6.0));
}

TEST(Pashina_Alina_ComplexNumberTest, Can_Substract_Bigger_Complex) {
  double re1 = 3.0;
  double im1 = 4.0;
  double re2 = 23.0;
  double im2 = 8.0;

  ComplexNumber num1(re1, im1);
  ComplexNumber num2(re2, im2);

  EXPECT_EQ(num1 - num2, ComplexNumber(-20.0, -4.0));
}
