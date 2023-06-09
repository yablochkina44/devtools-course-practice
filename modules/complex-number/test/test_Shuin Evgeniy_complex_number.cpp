// Copyright 2023 Shuin Evgeniy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shuin_Evgeniy_tests, can_create_a_negative_number) {
ComplexNumber comp(1, 2);

EXPECT_EQ(1, comp.getRe());
EXPECT_EQ(2, comp.getIm());
}

TEST(Shuin_Evgeniy_tests, can_create_a_non_negative_number) {
ComplexNumber comp(3.7, 1.8);

EXPECT_EQ(3.7, comp.getRe());
EXPECT_EQ(1.8, comp.getIm());
}

TEST(Shuin_Evgeniy_tests, can_copy_a_complex_number) {
ComplexNumber comp(3.7, 1.8);
ComplexNumber comp2(comp);

EXPECT_EQ(comp2.getRe(), comp.getRe());
EXPECT_EQ(comp2.getIm(), comp.getIm());
}

TEST(Shuin_Evgeniy_tests, can_assign_complex_number_to_another) {
ComplexNumber comp(3.7, 1.8);
ComplexNumber comp2;
comp2 = comp;

EXPECT_EQ(comp2.getRe(), comp.getRe());
EXPECT_EQ(comp2.getIm(), comp.getIm());
}

TEST(Shuin_Evgeniy_tests, can_sum_two_complex_numbers) {
ComplexNumber comp(-1.5, 2.9);
ComplexNumber comp2(3, -0.5);
ComplexNumber comp3;
comp3 = comp + comp2;

EXPECT_EQ(1.5, comp3.getRe());
EXPECT_EQ(2.4, comp3.getIm());
}
