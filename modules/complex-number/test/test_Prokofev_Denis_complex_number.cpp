// Copyright 2023 Prokofev Denis

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Prokofev_Denis_ComplexNumberTest, CanCreate) {
  double re = 1.6;
  double im = 2.4;
  ComplexNumber cn(re, im);
  EXPECT_EQ(re, cn.getRe());
  EXPECT_EQ(im, cn.getIm());
}

TEST(Prokofev_Denis_ComplexNumberTest, CanSetRe) {
  double re = 2.7;
  ComplexNumber cn(0.0, 0.0);
  cn.setRe(re);
  EXPECT_EQ(re, cn.getRe());
}

TEST(Prokofev_Denis_ComplexNumberTest, CanSetIm) {
  double im = 7.2;
  ComplexNumber cn(0.0, 0.0);
  cn.setIm(im);
  EXPECT_EQ(im, cn.getIm());
}

TEST(Prokofev_Denis_ComplexNumberTest, CanPlus) {
  double re1 = 3.0;
  double im1 = 4.0;
  double re2 = 1.0;
  double im2 = 0.0;
  ComplexNumber cn1(re1, im1);
  ComplexNumber cn2(re2, im2);
  ComplexNumber cn_res = cn1 + cn2;

  EXPECT_DOUBLE_EQ(4.0, cn_res.getRe());
  EXPECT_DOUBLE_EQ(4.0, cn_res.getIm());
}
