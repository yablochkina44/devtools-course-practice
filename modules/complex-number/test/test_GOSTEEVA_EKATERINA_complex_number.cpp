// Copyright 2023 Gosteeva Ekaterina

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Gosteeva_Ekaterina_ComplexNumberTest, Copy_and_Eq) {
    double re = 3.0;
    double im = 14.0;

    ComplexNumber z(re, im);
    ComplexNumber x(z);
    ComplexNumber y = z;

    EXPECT_EQ(x, y);
}

TEST(Gosteeva_Ekaterina_ComplexNumberTest, Triple_Mult) {
    ComplexNumber x(1.0, 2.0), y(3.0, 4.0), z(5.0, 6.0);
    ComplexNumber res_first = x * y * z;
    ComplexNumber res_second = y * z * x;
    ComplexNumber res_real(-85.0, 20.0);

    EXPECT_EQ(res_real, res_first);
    EXPECT_EQ(res_real, res_second);
    EXPECT_EQ(res_first, res_second);
}

TEST(Gosteeva_Ekaterina_ComplexNumberTest, Equality) {
    ComplexNumber x(3, 14);
    ComplexNumber y(3, 14);
    ComplexNumber z(14, 3);

    ASSERT_TRUE(x == y);
    ASSERT_FALSE(x == z);
    ASSERT_FALSE(y == z);
}

TEST(Gosteeva_Ekaterina_ComplexNumberTest, NoEquality) {
    ComplexNumber x(3, 14);
    ComplexNumber y(14, 3);

    ASSERT_TRUE(x != y);
}
