// Copyright 2023 Terina Alina

#include <gtest/gtest.h>
#include <cmath>
#include "include/Function_Eyler.h"

TEST(Terina_Alina_EylerTest, can_check_the_multiplicativity_property) {
    Function_Eyler f;
    Function_Eyler f1;

    Function_Eyler f2;
    int f1_ = f1.Function_Euler(2);
    int f2_ = f2.Function_Euler(3);
    int res = f1_ * f2_;

    EXPECT_EQ(res, f.Function_Euler(6));
}

TEST(Terina_Alina_EylerTest, can_count_the_function_from_1) {
    Function_Eyler f;

    EXPECT_EQ(1, f.Function_Euler(1));
}

TEST(Terina_Alina_EylerTest, can_count_the_function_from_10000) {
    Function_Eyler f;
    int elem = 10000;

    EXPECT_EQ(4000, f.Function_Euler(elem));
}

TEST(Terina_Alina_EylerTest, can_count_the_function_from_huge_number) {
    Function_Eyler f;
    int elem = 12345678;

    EXPECT_EQ(4027392, f.Function_Euler(elem));
}

TEST(Terina_Alina_EylerTest, cant_calculate_negative) {
    Function_Eyler f;
    EXPECT_ANY_THROW(f.Function_Euler(-10));
}

TEST(Terina_Alina_EylerTest, can_check_the_property_of_eyler_function) {
    // phi(2^20)= 2^(20-1);
    Function_Eyler f1;
    Function_Eyler f2;

    int elem1 = pow(2, 20);
    int elem2 = pow(2, 19);

    EXPECT_EQ(elem2 , f1.Function_Euler(elem1));
}

TEST(Terina_Alina_EylerTest, can_check_the_property_of_Ferma_small_theorem) {
    // a^phi(b)= 1{modulo b}, NOD(A,B) = 1;
    Function_Eyler f;

    int a = 7;
    int b = 5;
    int elem1 = pow(a, f.Function_Euler(b));
    int res = elem1 % b;

    EXPECT_EQ(1, res);
}

TEST(Terina_Alina_EylerTest, can_check_the_property_of_Ferma_small_theorem_1) {
    Function_Eyler f;

    int a = 21;
    int b = 10;
    int elem1 = pow(a, f.Function_Euler(b));
    int res = elem1 % b;

    EXPECT_EQ(1, res);
}

TEST(Terina_Alina_EylerTest, can_calculate_a_F_mutually_simple_numbers) {
    Function_Eyler f;

    int a = 19;
    int b = 29;
    int c = a * b;
    int res = (a - 1) * (b - 1);

    EXPECT_EQ(res, f.Function_Euler(c));
}

TEST(Terina_Alina_EylerTest, can_calculate_a_F_of_mutually_simple_numbers_1) {
    Function_Eyler f;

    int a = 11;
    int b = 19;
    int c = a * b;
    int res = (a - 1) * (b - 1);
    EXPECT_EQ(res, f.Function_Euler(c));
}
