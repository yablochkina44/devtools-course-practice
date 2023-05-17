// Copyright 2023 Mitin Roman

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <cinttypes>
#include <numeric>

#include "include/gronsfeld_cipher.hpp"

TEST(gronsfeld_cipher, constructable_with_initlist) {
    // Act and Assert
    EXPECT_NO_THROW(gronsfeld_cipher_t cipher({1, 2, 3}));
}

TEST(gronsfeld_cipher, vector_constructable) {
    // Arrange
    std::vector<uint8_t> vec{3, 2, 1};

    // Act and Assert
    EXPECT_NO_THROW(gronsfeld_cipher_t cipher(vec));
}

TEST(gronsfeld_cipher, to_big_val_in_vector_throw_in_ctor) {
    // Arrange
    std::vector<uint8_t> vec{0, 50, 20};

    // Act and Assert
    EXPECT_ANY_THROW(gronsfeld_cipher_t cipher(vec));
}

TEST(gronsfeld_cipher, one_letter_code) {
    // Arrange
    uint8_t shift = 10;
    gronsfeld_cipher_t cipher({shift});
    char letter = 'a';

    // Act
    std::string code = cipher.code({letter});

    // Assert
    EXPECT_EQ(code[0], 'a' + shift);
}

TEST(gronsfeld_cipher, shift_manyletters_code) {
    // Arrange
    gronsfeld_cipher_t cipher({1});
    std::string s;
    s.resize(26);
    std::fill(s.begin(), s.end(), 'a');

    // Act
    std::string code = cipher.code(s);
    std::fill(s.begin(), s.end(), 'b');

    // Assert
    EXPECT_EQ(code, s);
}

TEST(gronsfeld_cipher, shift_allalphabet_code) {
    // Arrange
    uint8_t shift = 1;
    gronsfeld_cipher_t cipher({shift});
    std::string s;
    s.resize(26);
    std::iota(s.begin(), s.end(), 'a');

    // Act
    std::string code = cipher.code(s);
    std::iota(s.begin(), prev(s.end(), shift), 'b');
    std::iota(prev(s.end(), shift), s.end(), 'a');

    // Assert
    EXPECT_EQ(code, s);
}

TEST(gronsfeld_cipher, decode_code_all_alphabet) {
    // Arrange
    gronsfeld_cipher_t cipher({1, 5, 2, 0, 10});
    std::string s;
    s.resize(26);
    std::iota(s.begin(), s.end(), 'a');

    // Act
    std::string code = cipher.code(s);
    std::string decode = cipher.decode(code);

    // Assert
    EXPECT_EQ(decode, s);
}
