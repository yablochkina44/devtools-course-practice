// Copyright 2023 Nikolaev Alexander

#include <gtest/gtest.h>
#include "include/odd_even_merge.h"

bool checkSortArray(const std::vector<int>& array) {
    const int sizeArray = array.size();
    for (int i = 0; i < sizeArray - 1; i++) {
        if (array[i] > array[i + 1]) return false;
    }
    return true;
}

TEST(Nikolaev_OddEvenMerge, can_sort_array) {
    // Arrange
    std::vector<int> array = {6, 5, 4, 3, 2, 1};

    // Act
    OddEvenMerge::OddEvenMergeBatcherSort(&array);

    // Assert
    ASSERT_TRUE(checkSortArray(array));
}

TEST(Nikolaev_OddEvenMerge, can_sort_random_array) {
    // Arrange
    std::vector<int> array = OddEvenMerge::getRandomArray(20);

    // Act
    OddEvenMerge::OddEvenMergeBatcherSort(&array);

    // Assert
    ASSERT_TRUE(checkSortArray(array));
}

TEST(Nikolaev_OddEvenMerge, can_sort_an_array_of_negative_numbers) {
    // Arrange
    std::vector<int> array = {-1, -2, -3, -4, -5, -6};

    // Act
    OddEvenMerge::OddEvenMergeBatcherSort(&array);

    // Assert
    ASSERT_TRUE(checkSortArray(array));
}
