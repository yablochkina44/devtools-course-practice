// Copyright 2023 Makarov Danila

#ifndef MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_NUMBER_H_
#define MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_NUMBER_H_

class FractionNumber {
 public:
  FractionNumber();

  FractionNumber(int numerator, int denominator);

  FractionNumber(const FractionNumber& z);

  int getDenominator() const;

  void setDenominator(const int den);

  int getNumerator() const;

  void setNumerator(const int num);

  static int NOD(int a, int b);

  static int NOK(int a, int b);

  FractionNumber& operator=(const FractionNumber& z);

  FractionNumber operator+(const FractionNumber& z) const;

  FractionNumber operator-(const FractionNumber& z) const;

  FractionNumber operator*(const FractionNumber& z) const;

  FractionNumber operator/(const FractionNumber& z) const;

  bool operator==(const FractionNumber& z) const;

  bool operator!=(const FractionNumber& z) const;

 private:
  int numerator, denominator;
};

#endif  //  MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_NUMBER_H_
