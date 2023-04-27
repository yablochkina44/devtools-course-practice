// Copyright 2023 Zorin Oleg

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Zorin_Oleg_ComplexNumberTest, Cant_Divide_By_Zero) {
  ComplexNumber x{ 1.0, 1.0 };
  ComplexNumber y{ 0.0, 0.0 };

  ASSERT_ANY_THROW(x / y);
}

TEST(Zorin_Oleg_ComplexNumberTest, Mult_By_Conjugate_Is_Real) {
  const double re = 2.0;
  const double im = 2.0;
  ComplexNumber x{ re, im };
  ComplexNumber y{ re, -im };

  ComplexNumber z = x * y;

  EXPECT_EQ(0.0, z.getIm());
}

TEST(Zorin_Oleg_ComplexNumberTest, Div_By_Same_Is_One) {
  const double re = 3.14;
  const double im = 2.71;
  ComplexNumber x{ re, im };
  ComplexNumber y = x;

  ComplexNumber z = x / y;

  EXPECT_EQ(1.0, z.getRe());
  EXPECT_EQ(0.0, z.getIm());
}
