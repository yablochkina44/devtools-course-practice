// Copyright 2023 Frank Maksim

#include <gtest/gtest.h>

#include "include/Converter.h"
TEST(RomanNumeralConverterTest, CanConvertArabicToRoman) {
  std::string result = toRoman(1);
  EXPECT_EQ(result, "I");
  result = toRoman(4);
  EXPECT_EQ(result, "IV");
  result = toRoman(5);
  EXPECT_EQ(result, "V");
  result = toRoman(9);
  EXPECT_EQ(result, "IX");
  result = toRoman(10);
  EXPECT_EQ(result, "X");
  result = toRoman(40);
  EXPECT_EQ(result, "XL");
  result = toRoman(50);
  EXPECT_EQ(result, "L");
  result = toRoman(90);
  EXPECT_EQ(result, "XC");
  result = toRoman(100);
  EXPECT_EQ(result, "C");
  result = toRoman(400);
  EXPECT_EQ(result, "CD");
  result = toRoman(500);
  EXPECT_EQ(result, "D");
  result = toRoman(900);
  EXPECT_EQ(result, "CM");
  result = toRoman(1000);
  EXPECT_EQ(result, "M");
}

TEST(RomanNumeralConverterTest, CanConvertRomanToArabic) {
  int result = toArabic("I");
  EXPECT_EQ(result, 1);
  result = toArabic("IV");
  EXPECT_EQ(result, 4);
  result = toArabic("V");
  EXPECT_EQ(result, 5);
  result = toArabic("IX");
  EXPECT_EQ(result, 9);
  result = toArabic("X");
  EXPECT_EQ(result, 10);
  result = toArabic("XL");
  EXPECT_EQ(result, 40);
  result = toArabic("L");
  EXPECT_EQ(result, 50);
  result = toArabic("XC");
  EXPECT_EQ(result, 90);
  result = toArabic("C");
  EXPECT_EQ(result, 100);
  result = toArabic("CD");
  EXPECT_EQ(result, 400);
  result = toArabic("D");
  EXPECT_EQ(result, 500);
  result = toArabic("CM");
  EXPECT_EQ(result, 900);
  result = toArabic("M");
  EXPECT_EQ(result, 1000);
}

TEST(RomanNumeralConverterTest, CanCheckInputType) {
  std::string result = checkInputType("123");
  EXPECT_EQ(result, "Arabic");
  result = checkInputType("XIV");
  EXPECT_EQ(result, "Roman");
  result = checkInputType("abc");
  EXPECT_EQ(result, "Invalid input");
}

TEST(RomanNumeralConverterTest, CanConvertRomanToArabicWithValidInput) {
  int result = toArabic("IV");
  EXPECT_EQ(result, 4);
  result = toArabic("MCMXCIV");
  EXPECT_EQ(result, 1994);
}
