// Copyright 2023 Makarov Danila

#include "include/fraction_number.h"

#include <stdbool.h>

#include <string>

int FractionNumber::NOD(int a, int b) {
  if (a % b == 0) return b;
  if (b % a == 0) return a;
  if (a > b) return FractionNumber::NOD(a % b, b);
  return FractionNumber::NOD(a, b % a);
}

int FractionNumber::NOK(int a, int b) {
  return (a * b) / FractionNumber::NOD(a, b);
}

int FractionNumber::getDenominator() const { return denominator; }

void FractionNumber::setDenominator(const int den) { denominator = den; }

int FractionNumber::getNumerator() const { return numerator; }

void FractionNumber::setNumerator(const int num) { numerator = num; }

FractionNumber::FractionNumber() : numerator(0), denominator(1) {}

FractionNumber::FractionNumber(int numerator, int denominator)
    : numerator(numerator), denominator(denominator) {}

FractionNumber::FractionNumber(const FractionNumber& z)
    : numerator(z.getNumerator()), denominator(z.getDenominator()) {}

FractionNumber& FractionNumber::operator=(const FractionNumber& z) {
  numerator = z.getNumerator();
  denominator = z.getDenominator();

  return *this;
}

FractionNumber FractionNumber::operator+(const FractionNumber& z) const {
  FractionNumber sum;
  int nok = NOK(this->getDenominator(), z.getDenominator());

  int det = nok, num1 = this->getNumerator() * (nok / this->getDenominator()),
      num2 = z.getNumerator() * (nok / z.getDenominator());

  sum.setNumerator(num1 + num2);
  sum.setDenominator(det);

  int nod = FractionNumber::NOD(sum.getNumerator(), sum.getDenominator());

  sum.setNumerator(sum.getNumerator() / nod);
  sum.setDenominator(sum.getDenominator() / nod);

  return sum;
}

FractionNumber FractionNumber::operator-(const FractionNumber& z) const {
  FractionNumber diff;
  int nok = FractionNumber::NOK(this->getDenominator(), z.getDenominator());

  int det = nok, num1 = this->getNumerator() * (nok / this->getDenominator()),
      num2 = z.getNumerator() * (nok / z.getDenominator());

  diff.setNumerator(num1 - num2);
  diff.setDenominator(det);

  int nod = FractionNumber::NOD(diff.getNumerator(), diff.getDenominator());

  diff.setNumerator(diff.getNumerator() / nod);
  diff.setDenominator(diff.getDenominator() / nod);

  return diff;
}

FractionNumber FractionNumber::operator*(const FractionNumber& z) const {
  FractionNumber mult;

  mult.setNumerator(this->getNumerator() * z.getNumerator());
  mult.setDenominator(this->getDenominator() * z.getDenominator());

  int nod = FractionNumber::NOD(mult.getNumerator(), mult.getDenominator());

  mult.setNumerator(mult.getNumerator() / nod);
  mult.setDenominator(mult.getDenominator() / nod);

  return mult;
}

FractionNumber FractionNumber::operator/(const FractionNumber& z) const {
  FractionNumber div;

  div.setNumerator(this->getNumerator() * z.getDenominator());
  div.setDenominator(this->getDenominator() * z.getNumerator());

  int nod = FractionNumber::NOD(div.getNumerator(), div.getDenominator());

  div.setNumerator(div.getNumerator() / nod);
  div.setDenominator(div.getDenominator() / nod);

  return div;
}

bool FractionNumber::operator==(const FractionNumber& z) const {
  int nok = FractionNumber::NOK(this->getDenominator(), z.getDenominator());

  int num1 = this->getNumerator() * (nok / this->getDenominator()),
      num2 = z.getNumerator() * (nok / z.getDenominator());

  return num1 == num2;
}

bool FractionNumber::operator!=(const FractionNumber& z) const {
  int nok = FractionNumber::NOK(this->getDenominator(), z.getDenominator());

  int num1 = this->getNumerator() * (nok / this->getDenominator()),
      num2 = z.getNumerator() * (nok / z.getDenominator());

  return num1 != num2;
}
