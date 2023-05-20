// Copyright 2023 Simeunovic Aleksandar

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Simeunovic_Aleksandar_ComplexNumberTest, Can_Create_Complex_Test) {
    // Arrange
    double re = 3.0;
    double im = 4.5;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
TEST(Simeunovic_Aleksandar_ComplexNumberTest, Multiplication_Test) {
    double re1 = 3.5;
    double im1 = -1.2;
    double re2 = 2.33;
    double im2 = 1.0;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 * z2;
    EXPECT_EQ(re1 * re2 - im1 * im2, z3.getRe());
    EXPECT_EQ(re1 * im2 + re2 * im1, z3.getIm());
}
TEST(Simeunovic_Aleksandar_ComplexNumberTest, CopyConstructor_Test) {
    double re = 3.4;
    double im = 5.0;
    ComplexNumber z1(re, im);
    ComplexNumber z2 = z1;
    EXPECT_EQ(z1.getRe(), z2.getRe());
    EXPECT_EQ(z1.getIm(), z2.getIm());
}
TEST(Simeunovic_Aleksandar_ComplexNumberTest, NotEqual_Test) {
    double re1 = 2.5;
    double im1 = 5.6;
    double re2 = 2.5;
    double im2 = 6.1;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    EXPECT_TRUE(z1 != z2);
}
TEST(Simeunovic_Aleksandar_ComplexNumberTest, Add_Test) {
    double re1 = 8.8;
    double im1 = 2.2;
    double re2 = -4.5;
    double im2 = -1.1;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 + z2;
    EXPECT_EQ(z1.getRe() + z2.getRe(), z3.getRe());
    EXPECT_EQ(z1.getIm() + z2.getIm(), z3.getIm());
}
