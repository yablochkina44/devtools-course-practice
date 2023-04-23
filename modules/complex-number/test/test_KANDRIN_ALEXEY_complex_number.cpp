// Copyright 2023 Kandrin Alexey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kandrin_Alexey_ComplexNumberTest, Can_set_real) {
    // Arrange
    ComplexNumber z;
    double real = 5.0;

    // Act
    z.setRe(real);

    // Assert
    EXPECT_EQ(real, z.getRe());
}

TEST(Kandrin_Alexey_ComplexNumberTest, Can_set_im) {
    // Arrange
    ComplexNumber z;
    double im = 5.0;

    // Act
    z.setIm(im);

    // Assert
    EXPECT_EQ(im, z.getIm());
}

TEST(Kandrin_Alexey_ComplexNumberTest, Can_copy) {
    // Arrange
    double re = 5.0, im = -7.0;
    ComplexNumber z{ re, im };

    // Act
    ComplexNumber z_copy{ z };

    // Assert
    EXPECT_EQ(z, z_copy);
    EXPECT_EQ(re, z_copy.getRe());
    EXPECT_EQ(im, z_copy.getIm());
}
