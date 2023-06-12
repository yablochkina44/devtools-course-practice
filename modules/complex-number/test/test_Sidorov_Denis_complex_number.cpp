// Copyright 2023 Sidorov Denis

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sidorov_Denis_ComplexNumberTest, TEST_SUM) {
  ComplexNumber a(1600.0, 25.0), b(800.0, 11.0), expected(2400.0, 36.0);
  ComplexNumber result = a + b;
  ASSERT_EQ(expected, result);
}

TEST(Sidorov_Denis_ComplexNumberTest, TEST_MINUS) {
  ComplexNumber z1(50.0, 20.0);
  ComplexNumber z2(40.0, 10.0);
  ComplexNumber expression = z1 - z2;
  EXPECT_EQ(expression, ComplexNumber(10.0, 10.0));
}

TEST(Sidorov_Denis_ComplexNumberTest, TEST_MULT) {
  ComplexNumber z1(5.0, 5.0);
  ComplexNumber z2(3.0, 3.0);

  ComplexNumber z1_M_z2 = z1 * z2;

  EXPECT_EQ(z1_M_z2, ComplexNumber(0, 30));
}
