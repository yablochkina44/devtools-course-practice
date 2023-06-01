// Copyright 2023 Mukhin Vadim

#include <gtest/gtest.h>

#include "include/Calculator.h"
#include "include/Converter.h"
#include "include/Calculator_app.h"

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM) {
    std::string num1 = "1010";
    int base1 = 2;
    std::string num2 = "FF";
    int base2 = 16;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "109");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM9) {
    std::string num1 = "1f";
    int base1 = 16;
    std::string num2 = "FF";
    int base2 = 16;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "11E");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM10) {
    std::string num1 = "0";
    int base1 = 16;
    std::string num2 = "0";
    int base2 = 16;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "0");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM2) {
    std::string num1 = "1010";
    int base1 = 2;
    std::string num2 = "11";
    int base2 = 2;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "1101");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM3) {
    std::string num1 = "102";
    int base1 = 10;
    std::string num2 = "1";
    int base2 = 10;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "103");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM4) {
    std::string num1 = "1010";
    int base1 = 2;
    std::string num2 = "11";
    int base2 = 10;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "21");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_SUM5) {
    std::string num1 = "110000";
    int base1 = 10;
    std::string num2 = "1F";
    int base2 = 16;
    // slovo
    std::string sum = add(num1, base1, num2, base2);
    EXPECT_EQ(sum, "1ADCF");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_DIFF) {
    std::string num1 = "f";
    int base1 = 16;
    std::string num2 = "8";
    int base2 = 10;
    std::string diff = subtract(num1, base1, num2, base2);
    EXPECT_EQ(diff, "7");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_PRODUCT) {
    std::string num1 = "4";
    int base1 = 10;
    std::string num2 = "6";
    int base2 = 8;
    std::string product = multiply(num1, base1, num2, base2);
    EXPECT_EQ(product, "24");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_DIV) {
    std::string num1 = "15";
    int base1 = 8;
    std::string num2 = "10";
    int base2 = 2;
    std::string quotient = divide(num1, base1, num2, base2);
    EXPECT_EQ(quotient, "6");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER) {
    std::string num = "101001";
    int base1 = 2;
    int base2 = 10;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "41");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER2) {
    std::string num = "10";
    int base1 = 10;
    int base2 = 8;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "12");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER3) {
    std::string num = "F";
    int base1 = 16;
    int base2 = 10;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "15");
}

TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER4) {
    std::string num = "a";
    int base1 = 16;
    int base2 = 10;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "10");
}
TEST(Mukhin_Vadim_Konverter_and_calculator, TEST_CONVERTER5) {
    std::string num = "123456789";
    int base1 = 10;
    int base2 = 16;
    std::string result = convert(num, base1, base2);
    EXPECT_EQ(result, "75BCD15");
}
TEST(Mukhin_Vadim_Konverter_and_calculator, TestAdd) {
    // Проверяем сложение чисел в системе счисления 10
    std::string num1 = "123";
    std::string num2 = "456";
    int base1 = 10;
    int base2 = 10;
    std::string expected = "579";
    std::string result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в системе счисления 2
    num1 = "1010";
    num2 = "1101";
    base1 = 2;
    base2 = 2;
    expected = "10111";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);
}
TEST(AddTest, TestAdd) {
    // Проверяем сложение чисел в системе счисления 10
    std::string num1 = "123";
    std::string num2 = "456";
    int base1 = 10;
    int base2 = 10;
    std::string expected = "579";
    std::string result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в системе счисления 2
    num1 = "1010";
    num2 = "1101";
    base1 = 2;
    base2 = 2;
    expected = "10111";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в системе счисления 16
    num1 = "FF";
    num2 = "1A";
    base1 = 16;
    base2 = 16;
    expected = "119";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в системе счисления 8
    num1 = "77";
    num2 = "12";
    base1 = 8;
    base2 = 8;
    expected = "111";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в разных системах счисления
    num1 = "5";
    num2 = "10";
    base1 = 16;
    base2 = 10;
    expected = "F";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в разных системах счисления
    num1 = "101";
    num2 = "11";
    base1 = 2;
    base2 = 8;
    expected = "16";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);

    // Проверяем сложение чисел в разных системах счисления
    num1 = "1111";
    num2 = "1111";
    base1 = 2;
    base2 = 16;
    expected = "1120";
    result = add(num1, base1, num2, base2);
    EXPECT_EQ(result, expected);
}
TEST(Mukhin_Vadim_Konverter_and_calculator, TES) {
    std::string result1 = add("123", 10, "456", 10);
    assert(result1 == "579");
    std::string result2 = add("ab", 16, "12d", 16);
    assert(result2 == "1D8");
    std::string result3 = add("123", 10, "0", 10);
    assert(result3 == "123");
    std::string result4 = add("0", 10, "456", 10);
    assert(result4 == "456");
    std::string result5 = add("ABC", 16, "1010", 2);
    assert(result5 == "AC6");
    std::string result6 = add("10", 2, "7", 8);
    assert(result6 == "11");
    std::string result7 = add("123", 10, "12345", 10);
    assert(result7 == "12468");
    std::string result8 = add("0", 10, "0", 10);
    assert(result8 == "0");
}
TEST(Mukhin_Vadim_Konverter_and_calculator, TES2) {
    std::string result1 = subtract("456", 10, "123", 10);
    assert(result1 == "333");
    std::string result2 = subtract("ab", 16, "3", 16);
    assert(result2 == "A8");
    std::string result3 = subtract("123", 10, "123", 10);
    assert(result3 == "0");
    std::string result4 = subtract("0", 10, "456", 10);
    assert(result4 == "-456");
    std::string result5 = subtract("0", 16, "ABC", 16);
    assert(result5 == "-ABC");
    std::string result6 = subtract("1010", 2, "7", 8);
    assert(result6 == "11");
    std::string result7 = subtract("123", 10, "456", 10);
    assert(result7 == "-333");
    std::string result8 = subtract("FFF", 16, "1", 16);
    assert(result8 == "FFE");
    std::string result9 = subtract("12345", 10, "12", 10);
    assert(result9 == "12333");
    std::string result10 = subtract("ab", 16, "1010", 2);
    assert(result10 == "A1");
    std::string result11 = subtract("ab", 16, "a", 16);
    assert(result11 == "A1");
}
TEST(Mukhin_Vadim_Konverter_and_calculator, TES3) {
    std::string result1 = multiply("123", 10, "456", 10);
    assert(result1 == "56088");
    std::string result2 = multiply("a", 16, "3", 16);
    assert(result2 == "7E");
    std::string result3 = multiply("123", 10, "0", 10);
    assert(result3 == "0");
    std::string result4 = multiply("0", 10, "456", 10);
    assert(result4 == "0");
    std::string result5 = multiply("1010", 2, "3", 8);
    assert(result5 == "11110");
    std::string result6 = multiply("a", 16, "10", 2);
    assert(result6 == "2A0");
    std::string result7 = multiply("123", 10, "1", 10);
    assert(result7 == "123");
    std::string result8 = multiply("3", 16, "a", 16);
    assert(result8 == "7E");
    std::string result10 = multiply("123", 10, "3", 8);
    assert(result10 == "369");
}
TEST(Mukhin_Vadim_Konverter_and_calculator, TES4) {
    std::string result1 = divide("10", 10, "2", 10);
    assert(result1 == "5");
    std::string result2 = divide("a", 16, "2", 16);
    assert(result2 == "5");
    std::string result3 = divide("0", 10, "12", 10);
    assert(result3 == "0");
    std::string result4 = divide("-6", 10, "2", 10);
    assert(result4 == "-3");
    std::string result5 = divide("2a", 16, "a", 16);
    assert(result5 == "4");
    std::string result6 = divide("2a", 16, "10", 2);
    assert(result6 == "15");
    std::string result7 = divide("123", 10, "1", 10);
    assert(result7 == "123");
    std::string result8 = divide("3", 16, "a", 16);
    assert(result8 == "0");
    std::string result10 = divide("123", 10, "3", 8);
    assert(result10 == "41");
}
TEST(Mukhin_Vadim_Konverter_and_calculator, TES5) {
    std::string result10_1 = divide("10", 10, "2", 10);
    assert(result10_1 == "5");
    std::string result10_2 = divide("123", 10, "7", 10);
    assert(result10_2 == "17");
    std::string result10_3 = divide("1000", 10, "3", 10);
    assert(result10_3 == "333");
    std::string result10_4 = divide("123456", 10, "789", 10);
    assert(result10_4 == "156");
    std::string result16_1 = divide("ff", 16, "f", 16);
    assert(result16_1 == "11");
    std::string result16_2 = divide("1A", 16, "2", 10);
    assert(result16_2 == "D");
    std::string result16_3 = divide("ABC", 16, "5", 10);
    assert(result16_3 == "225");
    std::string result16_4 = divide("BE", 16, "B", 16);
    assert(result16_4 == "11");
    std::string result10_5 = divide("123", 10, "1", 10);
    assert(result10_5 == "123");
    std::string result16_5 = divide("ABC", 16, "1", 16);
    assert(result16_5 == "ABC");
    std::string result10_6 = divide("0", 10, "123", 10);
    assert(result10_6 == "0");
    std::string result10_8 = divide("123", 10, "456", 10);
    assert(result10_8 == "0");
    std::string result10_9 = divide("-100", 10, "10", 10);
    assert(result10_9 == "-10");
    std::string result10_10 = divide("100", 10, "-10", 10);
    assert(result10_10 == "-10");
    std::string result10_11 = divide("-100", 10, "-10", 10);
    assert(result10_11 == "10");
    std::string result16_6 = divide("-A", 16, "2", 10);
    assert(result16_6 == "-5");
    std::string result16_7 = divide("A", 16, "-2", 10);
    assert(result16_7 == "-5");
    std::string result16_8 = divide("-A", 16, "-2", 10);
    assert(result16_8 == "5");
    std::string result16_9 = divide("FF", 16, "10", 10);
    assert(result16_9 == "19");
}
