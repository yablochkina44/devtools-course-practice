// Copyright 2023 Maxim Kolesov

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kolesov_Maxim_ComplexNumberTest, Divide_By_Zero) {
  ComplexNumber num1(42, 42);
  ComplexNumber zero = ComplexNumber(0, 0);

  ASSERT_THROW((num1 / zero), std::string);
}

TEST(Kolesov_Maxim_ComplexNumberTest, Getters) {
  ComplexNumber number(42, 24);

  const double re = number.getRe();
  const double im = number.getIm();

  ASSERT_EQ(re, 42);
  ASSERT_EQ(im, 24);
}

TEST(Kolesov_Maxim_ComplexNumberTest, Setters) {
  ComplexNumber number(42, 24);

  number.setRe(1);
  number.setIm(7);

  ASSERT_EQ(number.getRe(), 1);
  ASSERT_EQ(number.getIm(), 7);
}

