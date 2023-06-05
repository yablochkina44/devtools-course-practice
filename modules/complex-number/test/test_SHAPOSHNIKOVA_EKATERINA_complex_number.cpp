// Copyright 2023 Shaposhnikova Ekaterina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shaposhnikova, test_default_constructor) {
  ComplexNumber compNum;

  ASSERT_EQ(compNum.getRe(), 0);
  ASSERT_EQ(compNum.getIm(), 0);
}

TEST(Shaposhnikova, test_copy_constructor) {
  ComplexNumber compNum1(1, 2);
  ComplexNumber compNum2(compNum1);

  ASSERT_EQ(compNum1.getRe(), compNum2.getRe());
  ASSERT_EQ(compNum1.getIm(), compNum2.getIm());
}

TEST(Shaposhnikova, test_compare_operator) {
  ComplexNumber compNum1(1, 2);
  ComplexNumber compNum2(1, 2);

  ASSERT_EQ(compNum1 == compNum2, true);
}

TEST(Shaposhnikova, test_add_method) {
  ComplexNumber compNum1(1, 2);
  ComplexNumber compNum2(3, 4);
  ComplexNumber compNum3;

  compNum3 = compNum1 + compNum2;

  ASSERT_EQ(compNum3.getRe(), 4);
  ASSERT_EQ(compNum3.getIm(), 6);
}
