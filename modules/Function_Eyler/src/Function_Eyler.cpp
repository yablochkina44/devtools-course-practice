// Copyright 2023 Terina Alina

#include <gtest/gtest.h>
#include <utility>
#include "include/Function_Eyler.h"

int Function_Eyler::Function_Euler(int n) {
        if (n <= 0) {
            throw std::invalid_argument(
                "Invalid value of argument. Must be positive");
        }

        if (n == 1 || n == 2) {
            return 1;
        }

        int c, k, l;

        c = 1;
        for (int i = 2; i < n; i++) {
            k = n;
            l = i;
            do {
                if (k > l) {
                    k = k - l;
                }
                if (k < l) { l = l - k; }
            } while (k != l);

            if (k == 1) {
                c++;
            }
        }

        return c;
}
