// Copyright 2023 Popov Andrey

#include "include/quadrical_equal.h"

#include <stdbool.h>
#include<string>
#include <cmath>
#include <limits>

Quadrical_equal::Quadrical_equal() {
  x1 = 0;
  x2 = 0;
  this->a = 0;
  this->b = 0;
  this->c = 0;
}

std::string Quadrical_equal::solution(double a, double b, double c) {
  this->a = a;
  this->b = b;
  this->c = c;
  D = b * b - 4 * a * c;
  if (D > 0) {
    x1 = ((-b) + sqrt(D)) / (2 * a);
    x2 = ((-b) - sqrt(D)) / (2 * a);
    std::string ans = std::to_string(x1)+"_"+std::to_string(x2);
    return ans;
  } else if (D == 0) {
    x1 = -(b / (2 * a));
    std::string ans = std::to_string(x1);
    return ans;
  } else {
    std::string ans = "No solution";
    return ans;
  }
}
