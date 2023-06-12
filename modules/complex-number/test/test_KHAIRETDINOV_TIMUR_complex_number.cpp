// Copyright 2023 Khairetdinov Timur

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Khairetdinov_Timur_ComplexNumberTest, Can_Add_For_Numbers) {
    // Arrange
    double re1 = 1.0;
    double re2 = 2.0;
    double re3 = 2.0;
    double re4 = 1.0;
    double im1 = 10.0;
    double im2 = 11.0;
    double im3 = 11.0;
    double im4 = 10.0;


    // Act
    ComplexNumber n1(re1, im1);
    ComplexNumber n2(re2, im2);
    ComplexNumber n3(re3, im3);
    ComplexNumber n4(re4, im4);

    // Assert
    EXPECT_EQ(n1 + n2, n3 + n4);
}

TEST(Khairetdinov_Timur_ComplexNumberTest, Can_Create_And_Multiply) {
    // Arrange
    double re1 = 1.0;
    double im1 = 10.0;
    ComplexNumber n2(2.0, 10.0);


    // Act
    ComplexNumber n1(re1, im1);
    ComplexNumber rezult(3.0, 20.0);


    // Assert
    EXPECT_EQ(n1 + n2, rezult);
    EXPECT_EQ((n1 + n2).getRe(), rezult.getRe());
    EXPECT_EQ((n1 + n2).getIm(), rezult.getIm());
}

TEST(Khairetdinov_Timur_ComplexNumberTest, Can_Setting_And_Eq) {
    // Arrange
    double re1 = 5.0;
    double im1 = 32.0;
    ComplexNumber n1;
    ComplexNumber n2;


    // Act
    n1.setIm(im1);
    n1.setRe(re1);
    n2 = n1;


    // Assert
    EXPECT_EQ(n1.getIm(), im1);
    EXPECT_EQ(n1.getRe(), re1);
    EXPECT_EQ(n2.getIm(), im1);
    EXPECT_EQ(n2.getRe(), re1);
    EXPECT_EQ(n2.getIm(), n1.getIm());
    EXPECT_EQ(n2.getRe(), n1.getRe());
}

TEST(Khairetdinov_Timur_ComplexNumberTest, Can_Multiply_And_Subtraction) {
    // Arrange
    double re1 = 1.0;
    double re2 = 2.0;
    double re3 = 4.0;
    double re4 = 1.0;
    double im1 = 10.0;
    double im2 = 11.0;
    double im3 = 31.0;
    double im4 = 10.0;


    // Act
    ComplexNumber n1(re1, im1);
    ComplexNumber n2(re2, im2);
    ComplexNumber n3(re3, im3);
    ComplexNumber n4(re4, im4);
    ComplexNumber n_multy = n1 + n2;
    ComplexNumber n_subst = n3 - n4;

    // Assert
    EXPECT_EQ(n_subst, n_multy);
    EXPECT_EQ(n_multy.getIm(), (n1 + n2).getIm());
    EXPECT_EQ(n_multy.getRe(), (n1 + n2).getRe());
    EXPECT_EQ(n_subst.getRe(), (n3 - n4).getRe());
    EXPECT_EQ(n_subst.getIm(), (n3 - n4).getIm());
    EXPECT_EQ(n_subst.getIm(), n_multy.getIm());
    EXPECT_EQ(n_subst.getRe(), n_multy.getRe());
}
