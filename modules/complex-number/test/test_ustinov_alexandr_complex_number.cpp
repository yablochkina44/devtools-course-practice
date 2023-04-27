// Copyright 2023 Ustinov Alexandr

#include <gtest/gtest.h>

#include <utility>

#include "include/complex_number.h"

TEST(Ustinov_ComplexNumberTest, Equality) {
    std::pair<ComplexNumber, ComplexNumber> eq_pair
        {ComplexNumber(3.0, 1.0), ComplexNumber(3.0, 1.0)};

    EXPECT_EQ(eq_pair.first, eq_pair.second);
}

TEST(Ustinov_ComplexNumberTest, NonEquality) {
    std::pair<ComplexNumber, ComplexNumber> neq_pair
        {ComplexNumber(1.0, 1.0), ComplexNumber(1.0, -1.0)};

    EXPECT_NE(neq_pair.first, neq_pair.second);
}

TEST(Ustinov_ComplexNumberTest, Addition) {
    std::pair<ComplexNumber, ComplexNumber> z1_z2_pair_array[3]{
        {ComplexNumber(1.0, 0.0), ComplexNumber(0.0, 1.0)},
        {ComplexNumber(2.0, 3.0), ComplexNumber(3.0, 5.0)},
        {ComplexNumber(0.0, 1.0), ComplexNumber(0.0, -1.0)}};
    ComplexNumber expected_z1_plus_z2_array[3]{
        ComplexNumber(1.0, 1.0),
        ComplexNumber(5.0, 8.0),
        ComplexNumber(0.0, 0.0)};
    ComplexNumber actual_z1_plus_z2_array[3];

    for (int i = 0; i < 3; ++i)
        actual_z1_plus_z2_array[i] = z1_z2_pair_array[i].first +
                                     z1_z2_pair_array[i].second;

    for (int i = 0; i < 3; ++i)
        EXPECT_EQ(actual_z1_plus_z2_array[i], expected_z1_plus_z2_array[i]);
}

TEST(Ustinov_ComplexNumberTest, Subtraction) {
    std::pair<ComplexNumber, ComplexNumber> z1_z2_pair_array[4]{
        {ComplexNumber(1.0, 0.0), ComplexNumber(0.0, 1.0)},
        {ComplexNumber(3.0, 1.0), ComplexNumber(1.0, 3.0)},
        {ComplexNumber(0.0, 1.0), ComplexNumber(0.0, 1.0)},
        {ComplexNumber(0.0, 0.0), ComplexNumber(0.0, -0.0)}};
    ComplexNumber expected_z1_minus_z2_array[4]{
        ComplexNumber(1.0, -1.0),
        ComplexNumber(2.0, -2.0),
        ComplexNumber(0.0, 0.0),
        ComplexNumber(0.0, 0.0)};
    ComplexNumber actual_z1_minus_z2_array[4];

    for (int i = 0; i < 4; ++i)
        actual_z1_minus_z2_array[i] = z1_z2_pair_array[i].first -
                                      z1_z2_pair_array[i].second;

    for (int i = 0; i < 4; ++i)
        EXPECT_EQ(actual_z1_minus_z2_array[i], expected_z1_minus_z2_array[i]);
}

TEST(Ustinov_ComplexNumberTest, Multiplication) {
    std::pair<ComplexNumber, ComplexNumber> z1_z2_pair_array[5]{
        {ComplexNumber(0.0, 0.0), ComplexNumber(0.0, 0.0)},
        {ComplexNumber(3.0, 0.0), ComplexNumber(5.0, 0.0)},
        {ComplexNumber(0.0, 2.0), ComplexNumber(0.0, 1.0)},
        {ComplexNumber(1.0, 1.0), ComplexNumber(1.0, 1.0)},
        {ComplexNumber(2.0, 3.0), ComplexNumber(0.0, 0.0)}
    };
    ComplexNumber expected_z1_times_z2_array[5]{
        ComplexNumber(0.0, 0.0),
        ComplexNumber(15.0, 0.0),
        ComplexNumber(-2.0, 0.0),
        ComplexNumber(0.0, 2.0),
        ComplexNumber(0.0, 0.0)
    };
    ComplexNumber actual_z1_times_z2_array[5];  // z1 * z2

    for (int i = 0; i < 5; ++i)
        actual_z1_times_z2_array[i] = z1_z2_pair_array[i].first *
                                      z1_z2_pair_array[i].second;

    for (int i = 0; i < 5; ++i)
        EXPECT_EQ(actual_z1_times_z2_array[i], expected_z1_times_z2_array[i]);
}

TEST(Ustinov_ComplexNumberTest, Division) {
    std::pair<ComplexNumber, ComplexNumber> z1_z2_pair_array[3]{
        {ComplexNumber(5.0, 8.0), ComplexNumber(1.0, 0.0)},
        {ComplexNumber(5.0, 8.0), ComplexNumber(0.0, 1.0)},
        {ComplexNumber(1.0, 0.0), ComplexNumber(1.0, 1.0)},
    };
    ComplexNumber expected_z1_over_z2_array[3]{
        ComplexNumber(5.0, 8.0),
        ComplexNumber(8.0, -5.0),
        ComplexNumber(0.5, -0.5),
    };
    ComplexNumber actual_z1_over_z2_array[3];  // z1 / z2

    for (int i = 0; i < 3; ++i)
        actual_z1_over_z2_array[i] = z1_z2_pair_array[i].first /
                                     z1_z2_pair_array[i].second;

    for (int i = 0; i < 3; ++i)
        EXPECT_EQ(actual_z1_over_z2_array[i], expected_z1_over_z2_array[i]);
}
