// Copyright 2023 Tychinin Alexey

#include <gtest/gtest.h>

#include "include/check_segments_intersection.h"

using geom::Point;
using geom::check_segments_intersection;

TEST(check_segments_intersection, not_intersecting_points_not_intersect) {
    Point p1{};
    Point p2{10., 10.};
    ASSERT_FALSE(check_segments_intersection({p1, p1}, {p2, p2}));
}

TEST(check_segments_intersection, points_with_same_loc_intersect) {
    Point p1{};
    ASSERT_TRUE(check_segments_intersection({p1, p1}, {p1, p1}));
}

TEST(check_segments_intersection, intersecting_point_and_segment) {
    Point p1{1., 1.};
    Point s2p1{0., 0.};
    Point s2p2{3., 3.};
    ASSERT_TRUE(check_segments_intersection({p1, p1}, {s2p1, s2p2}));
}

TEST(check_segments_intersection, not_intersecting_point_and_segment) {
    Point p1{-1., -1.};
    Point s2p1{0., 0.};
    Point s2p2{3., 3.};
    ASSERT_FALSE(check_segments_intersection({p1, p1}, {s2p1, s2p2}));
}

TEST(check_segments_intersection, parallel_segments_not_intersect) {
    Point s1p1{0., 2.};
    Point s1p2{1., 3.};
    Point s2p1{0., 0.};
    Point s2p2{3., 3.};
    ASSERT_FALSE(check_segments_intersection({s1p1, s1p2}, {s2p1, s2p2}));
}

TEST(check_segments_intersection, overlapping_segments_intersect) {
    Point s1p1{-1., -1.};
    Point s1p2{5., 5.};
    Point s2p1{0., 0.};
    Point s2p2{2., 2.};
    ASSERT_TRUE(check_segments_intersection({s1p1, s1p2}, {s2p1, s2p2}));
}

TEST(check_segments_intersection, intersecting_segments_on_single_line) {
    Point s1p1{0., 0.};
    Point s1p2{2., 2.};
    Point s2p1{2., 2.};
    Point s2p2{3., 3.};
    ASSERT_TRUE(check_segments_intersection({s1p1, s1p2}, {s2p1, s2p2}));
}

TEST(check_segments_intersection, not_intersecting_segments_on_single_line) {
    Point s1p1{0., 0.};
    Point s1p2{2., 2.};
    Point s2p1{3., 3.};
    Point s2p2{5., 5.};
    ASSERT_FALSE(check_segments_intersection({s1p1, s1p2}, {s2p1, s2p2}));
}

TEST(check_segments_intersection, boundary_intersection_s1p1_s2p1) {
    Point s1p1{0., 0.};
    Point s1p2{5., 5.};
    Point s2p1{0., 0.};
    Point s2p2{-3., 6.};
    ASSERT_TRUE(check_segments_intersection({s1p1, s1p2}, {s2p1, s2p2}));
}

TEST(check_segments_intersection, boundary_intersection_s1p1_s2p2) {
    Point s1p1{0., 0.};
    Point s1p2{5., 5.};
    Point s2p1{-3., -3.};
    Point s2p2{0., 0.};
    ASSERT_TRUE(check_segments_intersection({s1p1, s1p2}, {s2p1, s2p2}));
}

TEST(check_segments_intersection, boundary_intersection_s1p2_s2p1) {
    Point s1p1{0., 0.};
    Point s1p2{5., 5.};
    Point s2p1{5., 5.};
    Point s2p2{-3., 6.};
    ASSERT_TRUE(check_segments_intersection({s1p1, s1p2}, {s2p1, s2p2}));
}

TEST(check_segments_intersection, boundary_intersection_s1p2_s2p2) {
    Point s1p1{0., 0.};
    Point s1p2{5., 5.};
    Point s2p1{12., 16.};
    Point s2p2{5., 5.};
    ASSERT_TRUE(check_segments_intersection({s1p1, s1p2}, {s2p1, s2p2}));
}

TEST(check_segments_intersection, simple_intersection) {
    Point s1p1{-10., -10.};
    Point s1p2{20., 20.};
    Point s2p1{2., 0.};
    Point s2p2{-6., 10.};
    ASSERT_TRUE(check_segments_intersection({s1p1, s1p2}, {s2p1, s2p2}));
}
