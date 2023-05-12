// Copyright 2023 Bulgakov Daniil

#include "../include/int_radix_sort.h"

void IntRadixSort::count_sorter(int * array, const int size,
                                    const int iter, const int base) {
    int * local_arr = new int[size];
    int * cnt = new int[base]();
    int mask = base - 1;
    int ind;

    for (int i = 0 ; i < size; i++) {
        ind = (((array[i]) >> (BITS_IN_BYTE * iter)) & mask);
        cnt[ind]++;
    }

    for (int i = 1; i < base; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        ind = (((array[i]) >> (BITS_IN_BYTE * iter)) & mask);
        local_arr[cnt[ind] - 1] = array[i];
        cnt[ind]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = local_arr[i];

    delete[] local_arr;
    delete[] cnt;
}

std::vector<int> IntRadixSort::get_sorted(const std::vector<int> &vec) {
    if (vec.empty()) return std::vector<int>();

    std::vector<int> result(vec);
    make_sort(result.data(), result.size());
    return result;
}

void IntRadixSort::make_sort(int *array, const int size) {
    if (array == nullptr) {
        throw std::invalid_argument("Input array parameter is null");
    } else if (size == 0) {
        return;
    }

    int base = (1 << BITS);
    int iters = (sizeof(int) * BITS_IN_BYTE) / BITS;

    for (int i = 0; i < iters; i++) {
        count_sorter(array, size, i, base);
    }
}
