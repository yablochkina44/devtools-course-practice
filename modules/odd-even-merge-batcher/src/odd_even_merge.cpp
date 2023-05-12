// Copyright 2023 Nikolaev Alexander

#include "include/odd_even_merge.h"

void OddEvenMerge::OddEvenMergeBatcherSort(std::vector<int>* array) {
    const int size = array->size();
    for (int p = 1; p < size; p += p) {
        for (int k = p; k > 0; k /= 2) {
            for (int j = k % p; j + k < size; j += 2 * k) {
                for (int i = 0; i < size - j - k; i++) {
                    if ((i + j) / (2 * p) == (i + j + k) / (2 * p)) {
                        if (array->at(j + i) > array->at(j + i + k)) {
                            std::swap(array->at(i + j), array->at(i + j + k));
                        }
                    }
                }
            }
        }
    }
}

std::vector<int> OddEvenMerge::getRandomArray(const int sizeArray) {
    std::vector<int> array(sizeArray);
    std::random_device dev;
    std::mt19937 gen(dev());
    for (int i = 0; i < sizeArray; i++) {
        array[i] = static_cast<int>(gen() % 10);
    }
    return array;
}
