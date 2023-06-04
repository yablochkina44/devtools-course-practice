// Copyright 2023 Voronov Alexandr

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Trenina_Elizaveta_ComplexNumberTest, Can_Create_Without_Parameters) {
    // Act & Assert
    ASSERT_NO_THROW(ComplexNumber{});
}

TEST(Voronov_Alexandr_ComplexNumberTest, Complex_Copy_Number) {
    // Arrange
    double a = 13.0;
    double b = 13.0;
    ComplexNumber cn(a , b);

    // Act
    ComplexNumber cn1(cn);

    // Assert
    EXPECT_EQ(cn1, cn);
}

TEST(Voronov_Alexandr_ComplexNumberTest, Comolex_Number_Negative_Create) {
    // Arrange
    double a = -10.0;
    double b = -11.0;

    // Act
    ComplexNumber z(a , b);

    // Assert
    EXPECT_EQ(a , z.getRe());
    EXPECT_EQ(b , z.getIm());
}

TEST(Voronov_Alexandr_ComplexNumberTest, Defauld_Value_Is_Zero_Value) {
    // Arrange
    ComplexNumber a(0, 0);
    ComplexNumber b;

    // Assert
    ASSERT_EQ(a, b);
}

TEST(Voronov_Alexandr_ComplexNumberTest, Complex_Number_Copy_Empty) {
    // Arrange
    ComplexNumber cn0;

    // Act
    ComplexNumber cn1(cn0);

    // Assert
    EXPECT_EQ(cn1.getRe() , 0.0);
    EXPECT_EQ(cn1.getIm() , 0.0);
}
