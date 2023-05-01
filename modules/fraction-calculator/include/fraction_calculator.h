// Copyright 2023 Makarov Danila

#ifndef MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_CALCULATOR_H_
#define MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_CALCULATOR_H_

#include <iostream>
#include <string>

class FractionCalculator {
 public:
  FractionCalculator() {}
  static FractionNumber summ(FractionNumber a, FractionNumber b) {
    return a + b;
  }
  static FractionNumber diff(FractionNumber a, FractionNumber b) {
    return a - b;
  }
  static FractionNumber mult(FractionNumber a, FractionNumber b) {
    return a * b;
  }
  static FractionNumber div(FractionNumber a, FractionNumber b) {
    return a / b;
  }
  static void print(FractionNumber a) {
    std::cout << a.getNumerator() << "/" << a.getDenominator() << std::endl;
  }
};

#endif  // MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_CALCULATOR_H_
