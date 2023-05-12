// Copyright 2023 Vadim Mukhin

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Mukhin_Vadim_ComplexNumberTest, Test3) {
    ComplexNumber t1(0.4, 0.7);
    ComplexNumber t2(0.2, 0.9);
    ComplexNumber t3 = t1 * t2;

    EXPECT_DOUBLE_EQ(-0.55, t3.getRe());
    EXPECT_DOUBLE_EQ(0.5, t3.getIm());
}

TEST(Mukhin_Vadim_ComplexNumberTest, Test1) {
    ComplexNumber t1(5.0, 0.4);
    ComplexNumber t2 = t1;
    EXPECT_DOUBLE_EQ(t1.getRe(), t2.getRe());
    EXPECT_DOUBLE_EQ(t1.getIm(), t2.getIm());
}

TEST(Mukhin_Vadim_ComplexNumberTest, Test2) {
    ComplexNumber t1(7.0, 0.1), t2(2.0, 0.2);
    EXPECT_NE(t1, t2);
}
