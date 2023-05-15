// Copyright 2023 Ivlev Alexander

#include "include/prime_numbers_from_interval.h"

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

unsigned int ModMul(unsigned int a,
    unsigned int b, unsigned int M) {
        if (b == 0) {
            return 0;
        }

        unsigned int z = ModMul(a, b / 2, M);

        if (b % 2 == 0) {
            return ((2 * z) % M);
        } else {
            return ((a + ((2 * z) % M)) % M);
        }
}

unsigned int ModExp(unsigned int x,
    unsigned int n, unsigned int M) {
        if (n == 0) {
            return 1;
        }

        unsigned int z = ModExp(x, n / 2, M);

        if (n % 2 == 0) {
            return ModMul(z, z, M);
        } else {
            return ModMul(ModMul(z, z, M), x, M);
        }
}

bool Ferma_primality_test(unsigned int N) {
    if (N < 2) {
        return false;
    }
    if (N == 2) {
        return true;
    }

    unsigned int multiplier = 0;

    if (N % 2 == 0) {
        multiplier = 2;
    }

    if (N % 3 == 0) {
        multiplier = 3;
    }

    if (multiplier != 0 && multiplier != N) {
        return false;
    }

    std::mt19937 gen(N);
    std::uniform_int_distribution<unsigned int> uid(2, N - 1);

    unsigned int k = 0;
    unsigned int X = 0;
    while (multiplier == 0 && k < 10) {
        X = uid(gen);
        if (gcd(X, N) != 1) {
            multiplier = gcd(X, N);
            break;
        }

        if (ModExp(X, N - 1, N) != 1) {
            multiplier = N - 1;
            break;
        }

        k += 1;
    }

    if (multiplier != N && multiplier != 0) {
        return false;
    } else {
        return true;
    }
}

std::vector<unsigned int> primality_test_interval(unsigned int a,
    unsigned int b) {
        std::vector<unsigned int> prime;

        for (unsigned int i = a; i <= b; i++) {
            if (Ferma_primality_test(i)) {
                prime.push_back(i);
            }
        }

        return prime;
}
