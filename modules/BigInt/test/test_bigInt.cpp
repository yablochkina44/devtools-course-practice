// Copyright 2023 Antonova Anastasya

#include <gtest/gtest.h>

#include "include/bigInt.h"

TEST(BigIntTest, DefaultConstructorTest) {
    BigInt x;
    EXPECT_FALSE(x.is_negative);
    EXPECT_EQ(x.digits, "0");
}

TEST(BigIntConstructorTest, PositiveNumber) {
    int n = 12345;
    BigInt num(n);
    EXPECT_FALSE(num.is_negative);
    EXPECT_EQ(num.digits, "12345");
}

TEST(BigIntConstructorTest, NegativeNumber) {
    int n = -12345;
    BigInt num(n);
    EXPECT_TRUE(num.is_negative);
    EXPECT_EQ(num.digits, "12345");
}

TEST(BigIntCopyConstructorTest, PositiveNumber) {
    BigInt num1(12345);
    BigInt num2(num1);

    EXPECT_FALSE(num2.is_negative);
    EXPECT_EQ(num2.digits, "12345");
}

TEST(BigIntCopyConstructorTest, NegativeNumber) {
    BigInt num1(-54321);
    BigInt num2(num1);

    EXPECT_TRUE(num2.is_negative);
    EXPECT_EQ(num2.digits, "54321");
}

TEST(BigIntConstructor, LargePositiveNumber) {
    BigInt a("123456789012345678901234567890");
    EXPECT_EQ(a.is_negative, false);
    EXPECT_EQ(a.digits, "123456789012345678901234567890");
}

TEST(BigIntConstructor, LargeNegativeNumber) {
    BigInt a("-123456789012345678901234567890");
    EXPECT_EQ(a.is_negative, true);
    EXPECT_EQ(a.digits, "123456789012345678901234567890");
}

TEST(BigIntAssignmentOperatorTest, PositiveNumber) {
    BigInt num1(12345);
    BigInt num2;

    num2 = num1;

    EXPECT_FALSE(num2.is_negative);
    EXPECT_EQ(num2.digits, "12345");
}

TEST(BigIntAssignmentOperatorTest, NegativeNumber) {
    BigInt num1(-54321);
    BigInt num2;

    num2 = num1;

    EXPECT_TRUE(num2.is_negative);
    EXPECT_EQ(num2.digits, "54321");
}

TEST(BigIntAssignmentOperatorTest, Zero) {
    BigInt num1(0);
    BigInt num2;

    num2 = num1;

    EXPECT_FALSE(num2.is_negative);
    EXPECT_EQ(num2.digits, "0");
}

TEST(BigIntTest, AdditionTest) {
    BigInt a("998");
    BigInt c("100999");
    BigInt b("100001");
    EXPECT_EQ(a + b, c);
}

TEST(BigIntTest, AdditionTest2) {
    BigInt a("99999999999999999999");
    BigInt b("1");
    BigInt c("100000000000000000000");
    EXPECT_EQ(a + b, c);
}

TEST(BigIntOperatorTest, SubtractionByNegative) {
    BigInt a("65546343226346899909087");
    BigInt b("-567554221325434");
    BigInt result = a - b;
    EXPECT_EQ(result, BigInt("65546342658792678583653"));
}

TEST(BigIntTest, MultiplicationTest) {
    BigInt a("99999999999999999999");
    BigInt b("2");
    BigInt c("199999999999999999998");
    EXPECT_EQ(a * b, c);
}

TEST(BigIntTest, GreaterThanOperatorTestFirst) {
    BigInt b("98765432109876543210987654321");
    BigInt c("-123456789012345678901234567890");

    EXPECT_FALSE(c > b);
}

TEST(BigIntTest, GreaterThanOperatorTestSecond) {
    BigInt a("123456789012345678901234567890");
    BigInt c("-123456789012345678901234567890");

    EXPECT_TRUE(a > c);
}

TEST(BigIntTest, GreaterThanOperatorTestThird) {
    BigInt a("123456789012345678901234567890");
    BigInt b("98765432109876543210987654321");

    EXPECT_TRUE(b > a);
}

TEST(BigIntTest, GreaterThanOperatorTest) {
    BigInt b("98765432109876543210987654321");
    BigInt c("-123456789012345678901234567890");

    EXPECT_TRUE(b > c);
}

TEST(BigIntTest, GreaterThanOrEqualToOperatorTest) {
    BigInt a("1364763897649287634876836487");
    BigInt b("1364763897649287634876836487");
    BigInt c("-1364763897649287634876836487");

    EXPECT_TRUE(b >= a);
    EXPECT_TRUE(a >= b);
    EXPECT_TRUE(a >= c);
    EXPECT_FALSE(c >= a);
    EXPECT_TRUE(b >= b);
}

TEST(BigIntTest, LessThanOperatorTestFirst) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-12345678901234567890123456781");

    EXPECT_TRUE(b < a);
    EXPECT_FALSE(a < b);
}

TEST(BigIntTest, LessThanOperatorTestSecond) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-12345678901234567890123456781");

    EXPECT_FALSE(a < b);
}

TEST(BigIntTest, LessThanOperatorTestThird) {
    BigInt a("123456789012345678901234567890");
    BigInt b("12345678901234567890123456781");

    EXPECT_TRUE(a < b);
}

TEST(BigIntTest, LessThanOrEqualToOperatorTest) {
    BigInt a("-123456789012345678901234567890");
    BigInt b("123456789012345678901234567890");

    EXPECT_TRUE(a <= b);
}

TEST(BigIntTest, LessThanTestOrEqual) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-12345678901234567890123456781");

    EXPECT_FALSE(a <= b);
}

TEST(BigIntTest, LessThanTest) {
    BigInt a("123456789012345678901");
    BigInt b("12345678901234567890123456781");

    EXPECT_TRUE(a <= b);
}

TEST(BigIntTest, EqualityOperatorTest) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-123456789012345678901234567890");
    BigInt c("123456789012345678901234567890");

    EXPECT_TRUE(a == a);
    EXPECT_TRUE(a == c);
    EXPECT_FALSE(a == b);
    EXPECT_FALSE(b == c);
}

TEST(BigIntTest, NotEqualityOperatorTest) {
    BigInt a("123456789012345678901234567890");
    BigInt b("-123456789012345678901234567890");
    BigInt c("123456789012345678901234567890");

    EXPECT_FALSE(a != a);
    EXPECT_FALSE(a != c);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b != c);
}

TEST(BigIntTest, AddAbsTest) {
    std::string a = "1000000000000000000000000000000";
    std::string b = "1234567891234567891234";
    std::string expected = "1000000001234567891234567891234";
    EXPECT_EQ(BigInt::add_abs(a, b), expected);
}

TEST(BigIntTest, SubtractAbsTest) {
    std::string a = "1000000000000000000000000000000";
    std::string b = "1234567891234567891234";
    std::string expected = "999999998765432108765432108766";
    EXPECT_EQ(BigInt::subtract_abs(a, b), expected);
}

TEST(BigIntTest, MultiplyIntTest) {
    std::string a = "1000000000000000000000";
    int b = 5;
    std::string expected = "5000000000000000000000";
    EXPECT_EQ(BigInt::multiply_int(a, b), expected);
}

TEST(BigIntTest, CompareAbsTest) {
    std::string a = "123456789";
    std::string b = "234567891";
    EXPECT_TRUE(BigInt::compare_abs(a, b));
}

TEST(BigIntTest, MultiplyTest) {
    std::string a = "111111111111111111111";
    std::string b = "123456789111112131415";
    std::string expected = "13717421012345792379430727023432098652065";
    EXPECT_EQ(BigInt::multiply(a, b), expected);
}

TEST(BigIntTest, DivideTest) {
    std::string a = "123456789";
    std::string b = "7";
    std::pair<std::string, std::string> result = BigInt::divide(a, b);

    EXPECT_EQ(result.second, "723456789");

    a = "123456789";
    b = "7";
    result = BigInt::divide(a, b);

    EXPECT_EQ(result.second, "723456789");
}

TEST(BigIntDivideTest, PositiveNumbers) {
    std::string a = "123456789";
    std::string b = "9876543";
    std::pair<std::string, std::string> result = BigInt::divide(a, b);
    EXPECT_EQ(result.first, "");
    EXPECT_EQ(result.second, "987655789");
}

TEST(BigIntDivideTest, PositiveNumbersBiggerSecond) {
    std::string a = "1234567";
    std::string b = "98765431234567890";
    std::pair<std::string, std::string> result = BigInt::divide(a, b);
    EXPECT_EQ(result.first, "0");
    EXPECT_EQ(result.second, "1234567");
}

TEST(BigIntDivideTest, NegativeNumbers) {
    std::string a = "-123456789";
    std::string b = "-9876543";
    std::pair<std::string, std::string> result = BigInt::divide(a, b);
    EXPECT_EQ(result.first, "");
    EXPECT_EQ(result.second, "9135802489");
}

TEST(BigIntDivideTest, MixedNumbers) {
    std::string a = "-123456789";
    std::string b = "9876543";
    std::pair<std::string, std::string> result = BigInt::divide(a, b);
    EXPECT_EQ(result.first, "");
    EXPECT_EQ(result.second, "-3246913789");
}

TEST(BigIntDivideIntTest, PositiveNumbers) {
    std::string a = "123456789";
    int b = 9;
    std::pair<std::string, int> result = BigInt::divide_int(a, b);
    EXPECT_EQ(result.first, "963937901");
    EXPECT_EQ(result.second, 0);
}

TEST(BigIntDivideIntTest, NegativeNumbers) {
    std::string a = "-123456789";
    int b = -7;
    std::pair<std::string, int> result = BigInt::divide_int(a, b);
    EXPECT_EQ(result.first, "-3-4-7-4-3-90-1-4-1");
    EXPECT_EQ(result.second, 6);
}

TEST(BigIntDivideIntTest, MixedNumbers) {
    std::string a = "-123456789";
    int b = 8;
    std::pair<std::string, int> result = BigInt::divide_int(a, b);
    EXPECT_EQ(result.first, "97654321");
    EXPECT_EQ(result.second, 7);
}

TEST(BigIntOperatorPlus, Addition) {
    EXPECT_EQ(BigInt("100"), BigInt("23") + BigInt("77"));
    EXPECT_EQ(BigInt("100"), BigInt("77") + BigInt("23"));
}

TEST(BigIntTest, operator_output) {
    BigInt a("123456789");
    BigInt b("-987654321");
    BigInt c("0");
    BigInt d("-1");

    std::ostringstream oss;
    oss << a << " " << b << " " << c << " " << d;
    ASSERT_EQ("123456789 -987654321 0 -1", oss.str());
}

TEST(BigIntOperatorTest, DivideTest) {
    BigInt a("123");
    BigInt b("3");
    BigInt c = a / b;
}

TEST(BigIntOperatorTest, Test) {
    BigInt a("123");
    BigInt b("3");
    BigInt c = a % b;
    EXPECT_EQ(c, BigInt("823"));
}
