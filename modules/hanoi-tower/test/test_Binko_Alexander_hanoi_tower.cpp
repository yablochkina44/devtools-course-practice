// Copyright 2023 Binko Alexandr

#include <gtest/gtest.h>

#include "include/hanoi_tower.h"

TEST(Binko_Alexander_HanoiTowerTest, TEST_DIRECTION) {
  int n(3), from_rod(1), to_rod(1), aux_rod(1);
  ASSERT_THROW(tower_solve(n, from_rod, to_rod, aux_rod), std::string);
}

TEST(Binko_Alexander_HanoiTowerTest, TEST_STEP) {
  int n(4), from_rod(1), to_rod(3), aux_rod(2);
  int res = tower_solve(n, from_rod, to_rod, aux_rod);
  int expected = 15;
  ASSERT_EQ(expected, res);
}

TEST(Binko_Alexander_HanoiTowerTest, TEST_ROD) {
  int n(4), from_rod(5), to_rod(3), aux_rod(2);
  ASSERT_THROW(tower_solve(n, from_rod, to_rod, aux_rod), std::string);
}

TEST(Binko_Alexander_HanoiTowerTest, TEST_STEP2) {
  int n(6), from_rod(1), to_rod(3), aux_rod(2);
  int res = tower_solve(n, from_rod, to_rod, aux_rod);
  int expected = 63;
  ASSERT_EQ(expected, res);
}

TEST(Binko_Alexander_HanoiTowerTest, TEST_ROD1) {
  int n(4), from_rod(2), to_rod(1), aux_rod(1);
  ASSERT_THROW(tower_solve(n, from_rod, to_rod, aux_rod), std::string);
}

TEST(Binko_Alexander_HanoiTowerTest, TEST_ROD2) {
  int n(4), from_rod(2), to_rod(3), aux_rod(2);
  ASSERT_THROW(tower_solve(n, from_rod, to_rod, aux_rod), std::string);
}
