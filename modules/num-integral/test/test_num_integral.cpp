// Copyright 2023 Bochkarev Vladimir

#include <gtest/gtest.h>
#include "../include/num_integral.h"

double f1D(double x) {
    return x * x;
}

double f2D(double x, double y) {
    return x * x + y * y;
}

double f3D(double x, double y, double z) {
    return x * x + y * y + z * z;
}

TEST(Bochkarev_Num_Integral_Test, Test_Answer_For_1D_Function) {
    double (*fun)(double);
    fun = f1D;
    double a = 1, b = 4;
    int n = 150;
    double expected = 21;

    ASSERT_NEAR(expected, NumIntegral::integral1D(a, b, n, fun), 0.0014);
}

TEST(Bochkarev_Num_Integral_Test, Test_Incorrect_Argument_N_1D) {
    double (*fun)(double);
    fun = f1D;
    double a = 1, b = 4;
    int n = -1;

    ASSERT_THROW(NumIntegral::integral1D(a, b, n, fun), std::invalid_argument);
}

TEST(Bochkarev_Num_Integral_Test, Test_Invalid_Function_Pointer_1D) {
    double (*fun)(double);
    fun = nullptr;
    double a = 1, b = 4;
    int n = 150;

    ASSERT_THROW(NumIntegral::integral1D(a, b, n, fun), std::invalid_argument);
}

TEST(Bochkarev_Num_Integral_Test, Test_Answer_For_2D_Function) {
    double (*fun)(double, double);
    fun = f2D;
    double a = 1, b = 4;
    double c = 1, d = 4;
    int n = 150;
    double expected = 126;

    ASSERT_NEAR(expected, NumIntegral::integral2D(a, b, c, d, n, fun), 0.0014);
}

TEST(Bochkarev_Num_Integral_Test, Test_Incorrect_Argument_N_2D) {
    double (*fun)(double, double);
    fun = f2D;
    double a = 1, b = 4;
    double c = 1, d = 4;
    int n = -10;

    ASSERT_THROW(NumIntegral::integral2D(a, b, c, d, n, fun),
    std::invalid_argument);
}

TEST(Bochkarev_Num_Integral_Test, Test_Invalid_Function_Pointer_2D) {
    double (*fun)(double, double);
    fun = nullptr;
    double a = 1, b = 4;
    double c = 1, d = 4;
    int n = 150;

    ASSERT_THROW(NumIntegral::integral2D(a, b, c, d, n, fun),
    std::invalid_argument);
}

TEST(Bochkarev_Num_Integral_Test, Test_Answer_For_3D_Function) {
    double (*fun)(double, double, double);
    fun = f3D;
    double a = 0, b = 3;
    double c = 0, d = 2;
    double e = 0, f = 1;
    int n = 150;
    double expected = 28;

    ASSERT_NEAR(expected, NumIntegral::integral3D(a, b, c, d, e, f, n, fun),
    0.0014);
}

TEST(Bochkarev_Num_Integral_Test, Test_Incorrect_Argument_N_3D) {
    double (*fun)(double, double, double);
    fun = f3D;
    double a = 0, b = 3;
    double c = 0, d = 2;
    double e = 0, f = 1;
    int n = 0;

    ASSERT_THROW(NumIntegral::integral3D(a, b, c, d, e, f, n, fun),
    std::invalid_argument);
}

TEST(Bochkarev_Num_Integral_Test, Test_Invalid_Function_Pointer_3D) {
    double (*fun)(double, double, double);
    fun = nullptr;
    double a = 0, b = 3;
    double c = 0, d = 2;
    double e = 0, f = 1;
    int n = 150;

    ASSERT_THROW(NumIntegral::integral3D(a, b, c, d, e, f, n, fun),
    std::invalid_argument);
}
