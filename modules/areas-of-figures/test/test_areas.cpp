// Copyright 2023 Nikitin Aleksandr

#include <gtest/gtest.h>

#include <tuple>

#include "include/areas.h"

TEST(Nikitin_test_areas, TEST_Parallelepiped_area) {
  Parallelepiped z1(5, 5, 5);

  ASSERT_EQ(150, z1.area());
}

TEST(Nikitin_test_areas, TEST_Parallelepiped_entered_non_positive) {
  Parallelepiped z(-1, 0, 5);

  ASSERT_EQ(0, z.area());
}

TEST(Nikitin_test_areas, TEST_Cylinder_area) {
  Cylinder z2(5, 5);

  ASSERT_EQ(314, z2.area());
}

TEST(Nikitin_test_areas, TEST_Cylinder_entered_non_positive) {
  Cylinder z(-1, 4);

  ASSERT_EQ(0, z.area());
}

TEST(Nikitin_test_areas, TEST_Sphere_area) {
  Sphere z3(5);

  ASSERT_EQ(314, z3.area());
}

TEST(Nikitin_test_areas, TEST_Sphere_entered_non_positive) {
  Sphere z(-1);

  ASSERT_EQ(0, z.area());
}
