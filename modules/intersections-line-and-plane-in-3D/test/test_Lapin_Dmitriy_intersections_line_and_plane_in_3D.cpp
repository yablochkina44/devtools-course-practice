// Copyright 2023 Lapin Dmitriy

#include <gtest/gtest.h>
#include <cmath>

#include "include/intersections_line_and_plane.h"

TEST(Lapin_Dmitriy_IntersectionTest, Intersection_test_one) {
    std::vector<double>plane = { 3, 2, 3, 4 };
    std::vector<double>dot = { 1, 2, 1 };
    std::vector<double>direction = { 1, 2, 3 };
    std::pair<int,
        std::vector<double>> result = isIntersection(plane, dot, direction);

    EXPECT_EQ(result.first, 0);
    EXPECT_EQ(result.second[0], 0.125);
    EXPECT_EQ(result.second[1], 0.25);
    EXPECT_EQ(result.second[2], -1.625);
}

TEST(Lapin_Dmitriy_IntersectionTest, Intersection_test_two) {
    std::vector<double>plane = { 0, 0, 1, 1 };
    std::vector<double>dot = { 1, 1, 0 };
    std::vector<double>direction = { 0, 0, 1 };
    std::pair<int,
        std::vector<double>> result = isIntersection(plane, dot, direction);

    EXPECT_EQ(result.first, 0);
    EXPECT_EQ(result.second[0], 1);
    EXPECT_EQ(result.second[1], 1);
    EXPECT_EQ(result.second[2], -1);
}


TEST(Lapin_Dmitriy_IntersectionTest, Overlap_test) {
    std::vector<double>plane = { 1, 0, -1, 0 };
    std::vector<double>dot = { 0, 1, 0 };
    std::vector<double>direction = { 1, 1, 1 };
    std::pair<int,
        std::vector<double>> result = isIntersection(plane, dot, direction);

    EXPECT_EQ(result.first, 1);
}


TEST(Lapin_Dmitriy_IntersectionTest, Parallel_test) {
    std::vector<double>plane = { 1, 0, -1, 0 };
    std::vector<double>dot = { 0, 0, -1 };
    std::vector<double>direction = { 1, 1, 1 };
    std::pair<int,
        std::vector<double>> result = isIntersection(plane, dot, direction);

    EXPECT_EQ(result.first, 2);
}
