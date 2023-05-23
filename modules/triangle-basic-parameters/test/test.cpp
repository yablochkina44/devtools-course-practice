// Copyright 2023 Lebedinskiy Ilya

#include <gtest/gtest.h>
#include <utility>
#include "../include/lebedinskiy_ilya_triangle_basic_params.h"

#define EPSILON 0.0001

TEST(Lebedinskiy_lab2, test_get_a_point_with_standart_constructor) {
    Triangle a({});
    std::pair<float, float> a_point = a.get_a_point();
    std::pair<float, float> expected = { 0, 3 };
    EXPECT_EQ(a_point, expected);
}

TEST(Lebedinskiy_lab2, test_get_a_point_with_change_param_constructor) {
    Triangle a({ 5, 2 }, { 3, 1 }, { 0, 8 });
    std::pair<float, float> a_point = a.get_a_point();
    std::pair<float, float> expected = { 5, 2 };
    EXPECT_EQ(a_point, expected);
}

TEST(Lebedinskiy_lab2, test_get_b_point_with_change_param_constructor) {
    Triangle a({ 5, 2 }, { 3, 1 }, { 0, 8 });
    std::pair<float, float> b_point = a.get_b_point();
    std::pair<float, float> expected = { 3, 1 };
    EXPECT_EQ(b_point, expected);
}

TEST(Lebedinskiy_lab2, test_get_c_point_with_change_param_constructor) {
    Triangle a({ 5, 2 }, { 3, 1 }, { 0, 8 });
    std::pair<float, float> c_point = a.get_c_point();
    std::pair<float, float> expected = { 0, 8 };
    EXPECT_EQ(c_point, expected);
}

TEST(Lebedinskiy_lab2, test_change_a_point) {
    Triangle a({ 5, 2 }, { 3, 1 }, { 0, 8 });
    a.set_a_point({ 0, 0 });
    std::pair<float, float> expected = { 0, 0 };
    EXPECT_EQ(a.get_a_point(), expected);
}

TEST(Lebedinskiy_lab2, test_change_b_point) {
    Triangle a({ 5, 2 }, { 3, 1 }, { 0, 8 });
    a.set_b_point({ 7, 3 });
    std::pair<float, float> expected = { 7, 3 };

    EXPECT_EQ(a.get_b_point(), expected);
}

TEST(Lebedinskiy_lab2, test_change_c_point) {
    Triangle a({ 5, 2 }, { 3, 1 }, { 0, 8 });
    a.set_c_point({ 5, 2 });
    std::pair<float, float> expected = { 5, 2 };

    EXPECT_EQ(a.get_c_point(), expected);
}

TEST(Lebedinskiy_lab2, get_height_of_bottom_side) {
    Triangle a({ 0, 0 }, { 2, 3 }, { 4, 0 });
    float bottom_side = a.get_side_lenght({ 0, 0 }, { 4, 0 });
    float height = a.get_height(bottom_side);
    float expected = 3;
    ASSERT_NEAR(height, expected, EPSILON);
}

TEST(Lebedinskiy_lab2, get_side_lenght) {
    Triangle a({ 0, 0 }, { 2, 3 }, { 4, 0 });
    float b = a.get_side_lenght({ 0, 0 }, { 4, 0 });
    float expected = 4;
    ASSERT_NEAR(b, expected, EPSILON);
}

TEST(Lebedinskiy_lab2, get_square) {
    Triangle a({ 0, 0 }, { 6, 0 }, { 6, 3 });
    float square = a.get_square();
    float expected = 9;
    ASSERT_NEAR(square, expected, EPSILON);
}

TEST(Lebedinskiy_lab2, get_perimeter) {
    Triangle a({ 0, 0 }, { 6, 0 }, { 6, 3 });
    float perimeter = a.get_perimeter();
    float expected = 15.7082;
    ASSERT_NEAR(perimeter, expected, EPSILON);
}
