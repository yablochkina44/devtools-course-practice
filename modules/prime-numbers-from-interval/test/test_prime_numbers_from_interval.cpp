// Copyright 2023 Ivlev Alexander

#include <gtest/gtest.h>

#include "../include/prime_numbers_from_interval.h"


TEST(Ivlev_test_prime_numbers_from_interval, test_gcd) {
    ASSERT_NO_THROW(gcd(1, 6));

    EXPECT_EQ(3, gcd(3, 9));
}

TEST(Ivlev_test_prime_numbers_from_interval, test_ModMul) {
    ASSERT_NO_THROW(ModMul(2, 3, 5));

    EXPECT_EQ(5, static_cast<int>(ModMul(4, 3, 7)));
}

TEST(Ivlev_test_prime_numbers_from_interval, test_ModExp) {
    ASSERT_NO_THROW(ModExp(2, 3, 5));

    EXPECT_EQ(2, static_cast<int>(ModExp(4, 5, 7)));
}

TEST(Ivlev_test_prime_numbers_from_interval, test_primality_test) {
    ASSERT_NO_THROW(Ferma_primality_test(1));

    EXPECT_TRUE(Ferma_primality_test(5));
    EXPECT_FALSE(Ferma_primality_test(6));
}

TEST(Ivlev_test_prime_numbers_from_interval, test_primality_test_interval) {
    std::vector<unsigned int> test_prime{5, 7, 11, 13, 17, 19};

    ASSERT_NO_THROW(primality_test_interval(0, 100));

    std::vector<unsigned int> result = primality_test_interval(5, 20);
    ASSERT_EQ(test_prime.size(), result.size());
    for (unsigned int i = 0; i < test_prime.size(); i++) {
        EXPECT_EQ(test_prime[i], result[i]);
    }
}
