// Copyright 2023 Bochkarev Vladimir

#pragma once

#ifndef MODULES_NUMINTEGRAL_INCLUDE_NUM_INTEGRAL_H_
#define MODULES_NUMINTEGRAL_INCLUDE_NUM_INTEGRAL_H_

#include <stdexcept>
#include <functional>

class NumIntegral {
 private:
 public:
     static double integral1D(double a, double b, int n,
     const std::function<double(double)>& fun);
     static double integral2D(double a, double b, double c, double d,
     int n, const std::function<double(double, double)>& fun);
     static double integral3D(double a, double b, double c, double d,
     double e, double f, int n,
     const std::function<double(double, double, double)>& fun);
};

#endif  // MODULES_NUM-INTEGRAL_INCLUDE_NUM_INTEGRAL_H_
