// Copyright 2023 Alexandr Terentev

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Terentev_Alexandr_ComplexNumberTest, TEST_Get_Set) {
  ComplexNumber a(9.0, 4.0);

  a.setRe(2.5);
  a.setIm(9.0);

  ASSERT_EQ(a.getRe(), 2.5);
  ASSERT_EQ(a.getIm(), 9.0);
}

TEST(Terentev_Alexandr_ComplexNumberTest, TEST_Sum) {
  ComplexNumber a(14.0, 1.0), b(56.0, 111.0), expected(70.0, 112.0);

  ComplexNumber result = a + b;

  ASSERT_EQ(expected, result);
}

TEST(Terentev_Alexandr_ComplexNumberTest, TEST_Subt) {
  ComplexNumber z1(110.0, 20.0);
  ComplexNumber z2(12.0, 15.0);

  ComplexNumber expression = z1 - z2;

  EXPECT_EQ(expression, ComplexNumber(98.0, 5.0));
}
