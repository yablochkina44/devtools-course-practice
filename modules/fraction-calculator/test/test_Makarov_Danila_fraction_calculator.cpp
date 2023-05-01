// Copyright 2023 Makarov Danila

#include <gtest/gtest.h>

#include "include/fraction_number.h"
#include "include/fraction_calculator.h"

TEST(Makarov_Danila_FractionNumberTest, TEST_SUM) {
  FractionNumber a(24, 10), b(12, 20), expected(3, 1);
  FractionNumber res = a + b;
  // FractionCalculator::print(c);

  ASSERT_EQ(expected, res);
}

TEST(Makarov_Danila_FractionNumberTest, TEST_SUM2) {
  FractionNumber a(2, 1), b(12, 15), d(10, 30), expected(47, 15);
  FractionNumber res = a + b + d;
  // FractionCalculator::print(c);

  ASSERT_EQ(expected, res);
}

TEST(Makarov_Danila_FractionNumberTest, TEST_DIFF) {
  FractionNumber a(5, 6), b(5, 8), expected(5, 24);
  FractionNumber res = a - b;
  // FractionCalculator::print(c);

  ASSERT_EQ(expected, res);
}

TEST(Makarov_Danila_FractionNumberTest, TEST_MULT) {
  FractionNumber a(2, 16), b(3, 8), c(3, 64);
  FractionNumber expected(b);
  FractionNumber res = a * b;
  bool check = (expected == b);

  if (check)
    expected = c;
  check = (expected != c);



  // FractionCalculator::print(c);
  // FractionCalculator::print(expected);
  // std::cout <<

  ASSERT_EQ(expected, res);
}

TEST(Makarov_Danila_FractionNumberTest, TEST_DIV) {
  FractionNumber a(2, 16), b(3, 8), expected(1, 3);
  FractionNumber res = a / b;
  // FractionCalculator::print(c);

  ASSERT_EQ(expected, res);
}
