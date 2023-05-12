// Copyright 2023 Bulgakov Daniil

#include <gtest/gtest.h>
#include "../include/int_radix_sort.h"

// Supporting functions

template <typename T>
void AssertVectorEqual(std::vector<T> a, std::vector<T> b) {
    ASSERT_EQ(a.size(), b.size()) << "Vectors sizes not equal";
    for (size_t i = 0; i < a.size(); i++) {
        ASSERT_EQ(a[i], b[i]);
    }
}

template <typename T>
void AssertArrayEqual(const T * a, const T * b, const int size) {
    for (int i = 0; i < size; i++) {
        ASSERT_EQ(a[i], b[i]);
    }
}

// Testing

TEST(Bulgakov_Radix_Sort_Test, Get_Vector_Sorted_Test) {
    std::vector<int> to_sort = {6, 12, 1};
    std::vector<int> expected = {1, 6, 12};
    std::vector<int> sorted = IntRadixSort::get_sorted(to_sort);
    AssertVectorEqual(sorted, expected);
}

TEST(Bulgakov_Radix_Sort_Test, Empty_Get_Vector_Sorting_Test) {
    std::vector<int> to_sort = {};
    std::vector<int> sorted = IntRadixSort::get_sorted(to_sort);
    ASSERT_EQ(sorted.empty(), true);
}

TEST(Bulgakov_Radix_Sort_Test, Empty_Get_Vector_Not_Throw_Error_Sorting_Test) {
    std::vector<int> to_sort = {};

    ASSERT_NO_THROW(IntRadixSort::get_sorted(to_sort));
}

TEST(Bulgakov_Radix_Sort_Test, Array_Sorting_Test) {
    const int array_size = 3;
    int* to_sort  = new int[array_size]{6, 12, 1};
    int* expected = new int[array_size]{1, 6, 12};

    IntRadixSort::make_sort(to_sort, array_size);

    AssertArrayEqual(to_sort, expected, array_size);
}

TEST(Bulgakov_Radix_Sort_Test, Array_Sorting_Nullptr_Test) {
    const int array_size = 3;
    int* to_sort = nullptr;

    ASSERT_THROW(IntRadixSort::make_sort(to_sort, array_size),
                        std::invalid_argument);
}

TEST(Bulgakov_Radix_Sort_Test, Array_Sorting_Zero_Size_Test) {
    const int array_size = 0;
    int* to_sort = new int[array_size];

    ASSERT_NO_THROW(IntRadixSort::make_sort(to_sort, array_size));
}
