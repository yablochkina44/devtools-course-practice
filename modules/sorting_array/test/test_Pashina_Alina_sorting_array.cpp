// Copyright 2023 Pashina Alina

#include <gtest/gtest.h>

#include <vector>

#include "include/sorting_array.h"

TEST(Pashina_A_sorting_array, simple_insert_sort) {
  double myArray[] = {2, 3, 1};
  double expectedArray[] = {1, 2, 3};

  SortInsert(myArray, 3);

  EXPECT_EQ(myArray[0], expectedArray[0]);
  EXPECT_EQ(myArray[1], expectedArray[1]);
  EXPECT_EQ(myArray[2], expectedArray[2]);
}

TEST(Pashina_A_sorting_array, simple_quick_sort) {
  double myArray[] = {2, 3, 1};
  double expectedArray[] = {1, 2, 3};

  SortQuick(myArray, 0, 2);

  EXPECT_EQ(myArray[0], expectedArray[0]);
  EXPECT_EQ(myArray[1], expectedArray[1]);
  EXPECT_EQ(myArray[2], expectedArray[2]);
}

TEST(Pashina_A_sorting_array, negative_insert_sort) {
  double myArray[] = {-20, -30, -10};
  double expectedArray[] = {-30, -20, -10};

  SortInsert(myArray, 3);

  EXPECT_EQ(myArray[0], expectedArray[0]);
  EXPECT_EQ(myArray[1], expectedArray[1]);
  EXPECT_EQ(myArray[2], expectedArray[2]);
}

TEST(Pashina_A_sorting_array, negative_quick_sort) {
  double myArray[] = {-20, -30, -10};
  double expectedArray[] = {-30, -20, -10};

  SortQuick(myArray, 0, 2);

  EXPECT_EQ(myArray[0], expectedArray[0]);
  EXPECT_EQ(myArray[1], expectedArray[1]);
  EXPECT_EQ(myArray[2], expectedArray[2]);
}
