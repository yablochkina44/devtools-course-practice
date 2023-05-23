// Copyright 2023 Ivlev Alexander

#include <gtest/gtest.h>
#include <stdint.h>
#include <vector>
#include <string>
#include <cinttypes>

#include "include/gronsfeld_cipher.hpp"
#include "include/gronsfeld_cipher_app.h"

TEST(gronsfeld_cipher_app, test_default_construct) {
    ASSERT_NO_THROW(gronsfeld_cipher_app app);
}

TEST(gronsfeld_cipher_app, test_run_code) {
    gronsfeld_cipher_app app;
    const char *temp[] = {"_", "0", "10_2", "abc"};

    ASSERT_NO_THROW(app(4, temp));
    EXPECT_EQ(app(4, temp), "kdm");
}

TEST(gronsfeld_cipher_app, test_run_decode) {
    gronsfeld_cipher_app app;
    const char *temp[] = {"_", "1", "3_11", "cba"};

    ASSERT_NO_THROW(app(4, temp));
    EXPECT_EQ(app(4, temp), "zqx");
}
