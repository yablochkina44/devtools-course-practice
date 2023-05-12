// Copyright 2023 Popov Andrey

#include <gtest/gtest.h>

#include <tuple>

#include "include/quadrical_equal.h"

TEST(Popov_A_quadratic_equation, Discriminant_positive) {
  Quadrical_equal z1;
  std::string D_more_zero = z1.solution(1, 3, -4);

  EXPECT_EQ(D_more_zero, "1.000000_-4.000000");
}

TEST(Popov_A_quadratic_equation, Discriminant_zero) {
  Quadrical_equal z1;
  std::string D_more_zero = z1.solution(1, -4, 4);

  EXPECT_EQ(D_more_zero, "2.000000");
}

TEST(Popov_A_quadratic_equation, Discriminant_negative) {
  Quadrical_equal z1;
  std::string D_more_zero = z1.solution(1, -5, 9);

  EXPECT_EQ(D_more_zero, "No solution");
}
