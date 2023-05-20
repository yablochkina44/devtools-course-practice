// Copyright 2023 Lebedinskiy Ilya

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Lebedinskiy_Ilya_ComplexNumberTest, Can_Sum) {
  double re1 = 5.0;
  double im1 = 1.0;
  double re2 = 4.0;
  double im2 = 6.0;
  ComplexNumber a(re1, im1);
  ComplexNumber b(re2, im2);
  ComplexNumber z = a + b;
  ASSERT_EQ(9, z.getRe());
  ASSERT_EQ(7, z.getIm());
}

TEST(Lebedinskiy_Ilya_ComplexNumberTest, Can_Min) {
  double re1 = 10.0;
  double im1 = 7.0;
  double re2 = 5.0;
  double im2 = 1.0;
  ComplexNumber a(re1, im1);
  ComplexNumber b(re2, im2);
  ComplexNumber z = a - b;
  ASSERT_EQ(5, z.getRe());
  ASSERT_EQ(6, z.getIm());
}

TEST(Lebedinskiy_Ilya_ComplexNumberTest, Can_Num) {
  double re = 15.0;
  double im = 7.0;
  ComplexNumber z(re, im);
  ASSERT_EQ(z.getRe(), 15.0);
  ASSERT_EQ(z.getIm(), 7.0);
}
