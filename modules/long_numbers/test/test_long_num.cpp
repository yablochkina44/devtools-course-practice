//  Copyright 2023 Rezchikov Dmitrii

#include <gtest/gtest.h>
#include "../include/long_num.h"


TEST(LongNumTest, fic_test) {
    ASSERT_EQ(true, true);
}

TEST(LongNumTest, Can_Add) {
    LongNumber n1("123");
    LongNumber n2("123");
    LongNumber expected = LongNumber("246");
    LongNumber n3 = n1 + n2;
    ASSERT_EQ(n3, expected);
}

TEST(LongNumTest, Can_Subtract) {
    LongNumber n1("123");
    LongNumber n2("122");
    LongNumber expected = LongNumber("1");
    LongNumber n3 = n1 - n2;
    ASSERT_EQ(n3, expected);
}

TEST(LongNumTest, Subtract_from_lesser) {
    LongNumber n1("121");
    LongNumber n2("122");
    LongNumber expected = LongNumber("1");
    expected.changeSign();
    LongNumber n3 = n1 - n2;
    // std::cout << n3 << "\n";
    ASSERT_EQ(n3, expected);
}

TEST(LongNumTest, Carry_last) {
    LongNumber n1("499");
    LongNumber n2("501");
    LongNumber expected = LongNumber("1000");
    LongNumber n3 = n1 + n2;
    // std::cout << n3 << " " << expected << "\n";
    ASSERT_EQ(n3, expected);
}

TEST(LongNumTest, Add_Negative_Number) {
    LongNumber n1("500");
    LongNumber n2("501");
    n2.changeSign();
    LongNumber expected = LongNumber("1");
    expected.changeSign();
    LongNumber n3 = n1 + n2;
    // std::cout << n3 << " " << expected << "\n";
    ASSERT_EQ(n3, expected);
}

TEST(LongNumTest, Less_than) {
    LongNumber n1("-500");
    LongNumber n2("500");
    // bool expected = LongNumber("1");
    // expected.changeSign();
    // LongNumber n3 = n1 + n2;
    // std::cout << n3 << " " << expected << "\n";
    ASSERT_TRUE(n1 < n2);
}

TEST(LongNumTest, Less_than_2) {
    LongNumber n1("-500");
    LongNumber n2("-200");
    // bool expected = LongNumber("1");
    // expected.changeSign();
    // LongNumber n3 = n1 + n2;
    // std::cout << n3 << " " << expected << "\n";
    ASSERT_TRUE(n1 < n2);
}

TEST(LongNumTest, Carry_Some) {
    LongNumber n1("999");
    LongNumber n2("11");
    LongNumber expected = LongNumber("1010");
    LongNumber n3 = n1 + n2;
    // std::cout << n3 << " " << expected << "\n";
    ASSERT_EQ(n3, expected);
}

TEST(LongNumTest, Plus_equals) {
    LongNumber n1("499");
    LongNumber n2("501");
    LongNumber expected = LongNumber("1000");
    n1 += n2;
    // std::cout << n3 << " " << expected << "\n";
    ASSERT_EQ(n1, expected);
}

TEST(LongNumTest, Minus_equals) {
    LongNumber n1("501");
    LongNumber n2("500");
    LongNumber expected = LongNumber("1");
    n1 -= n2;
    // std::cout << n3 << " " << expected << "\n";
    ASSERT_EQ(n1, expected);
}

TEST(LongNumTest, Mult) {
    LongNumber n1("999");
    LongNumber n2("1");
    LongNumber expected = LongNumber("999");
    LongNumber n3 = n1 * n2;
    // std::cout << n3 << " " << expected << "\n";
    ASSERT_EQ(n3, expected);
}

TEST(LongNumTest, Divide) {
    LongNumber n1("999");
    LongNumber n2("1");
    LongNumber expected = LongNumber("999");
    LongNumber n3 = n1 / n2;
    // std::cout << n3 << " " << expected << "\n";
    ASSERT_EQ(n3, expected);
}
TEST(LongNumTest, Not_Equals) {
    LongNumber n1("999");
    LongNumber n2("11");
    // std::cout << n3 << " " << expected << "\n";
    ASSERT_TRUE(n1 != n2);
}

