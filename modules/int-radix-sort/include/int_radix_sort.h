// Copyright 2023 Bulgakov Daniil

#pragma once

#include <vector>
#include <stdexcept>

/**
 * @brief Class represent integer radix sort.
 * @link https://en.wikipedia.org/wiki/Radix_sort
 * @author Daniil Bulgakov
 */
class IntRadixSort {
 private:
    /**
     * @brief Number of bits in one rank
     */
    static const int BITS = 8;
    /**
     * @brief Amount of bits in one byte
     */
    static const int BITS_IN_BYTE = 8;
    /**
     * @brief Count sorting for a specific rank on iteration
     * 
     * @param array input sorting array data
     * @param size  size of array
     * @param iter  rank number by which to sort
     * @param base  rank size
     */
    static void count_sorter(int * array, const int size,
                                    const int iter, const int base);

 public:
    /**
     * @brief  Get sorted integer vector using Radix Sort Algorithm
     * 
     * @param  vec input vector to sort
     * @return Sorted vector
     */
    static std::vector<int> get_sorted(const std::vector<int>& vec);
    /**
     * @brief  Sorting integer array using Radix Sort Algorithm
     * 
     * @param  array input array which will be sorted
     * @param  size input array size
     */
    static void make_sort(int * array, const int size);
};
