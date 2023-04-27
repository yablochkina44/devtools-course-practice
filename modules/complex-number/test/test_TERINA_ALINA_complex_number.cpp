// Copyright 2023 Alina Terina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Terina_Alina_ComplexNumberTest, Can_Create_Complex_Number) {
    double re = 2.0;
    double im = 0.1;

    ComplexNumber z(re, im);

    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Terina_Alina_ComplexNumberTest, Can_Create_Copy) {
    double re = 2.0;
    double im = 0.1;

    ComplexNumber z1(re, im);
    ComplexNumber z2(z1);

    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Terina_Alina_ComplexNumberTest, Can_Multiply_Complex_Numbers) {
    double re1 = 0.3;
    double im1 = 0.1;

    double re2 = 0.8;
    double im2 = 0.6;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 * z2;

    EXPECT_EQ(0.18, z3.getRe());
    EXPECT_EQ(0.26, z3.getIm());
}

TEST(Terina_Alina_ComplexNumberTest, Can_Sum_Complex_Numbers) {
    double re1 = 2.0;
    double im1 = 0.1;

    ComplexNumber z1(re1, im1);

    double re2 = 5.0;
    double im2 = 0.8;

    ComplexNumber z2(re2, im2);

    ComplexNumber sum = z1 + z2;

    EXPECT_EQ(7, sum.getRe());
    EXPECT_EQ(0.9, sum.getIm());
}

TEST(Terina_Alina_ComplexNumberTest, Can_Subtract_Complex_Numbers) {
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 2.0;
    double im2 = 1.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 - z2;

    EXPECT_EQ(-1, z3.getRe());
    EXPECT_EQ(1, z3.getIm());
}

TEST(Terina_Alina_ComplexNumberTest, Can_Equate_Complex_Numbers) {
    double re = 2.0;
    double im = 0.1;

    ComplexNumber z1(re, im);
    ComplexNumber z2;
    z2 = z1;

    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}

TEST(Terina_Alina_ComplexNumberTest, Can_Compare_Complex_Numbers_1) {
    double re1 = 5.0;
    double im1 = 0.2;

    ComplexNumber z1(re1, im1);

    double re2 = 4.0;
    double im2 = 0.3;

    ComplexNumber z2(re2, im2);

    EXPECT_TRUE(z1 != z2);
}
