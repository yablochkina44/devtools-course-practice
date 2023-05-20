// Copyright 2023 Binko Alexandr

#include "include/hanoi_tower.h"

#include <iostream>

static int counter = 1;

void hanoi(int n, int from_rod, int to_rod, int aux_rod) {
  if (from_rod < 4 && from_rod > 0 && to_rod < 4 && to_rod > 0 && aux_rod < 4 &&
      aux_rod > 0) {
    if (from_rod == to_rod) {
      throw std::string("'from rod' and 'to rod' is equal");
    }
    if (from_rod == aux_rod) {
      throw std::string("'from rod' and 'aux rod' is equal");
    }
    if (to_rod == aux_rod) {
      throw std::string("'aux rod' and 'to rod' is equal");
    }
    if (n == 1) {
      return;
    }
    counter++;
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    counter++;
    hanoi(n - 1, aux_rod, to_rod, from_rod);
  } else {
    throw std::string(
        "'from rod'/'to rod'/'aux rod' - must be in the range from 1 to 3");
  }
}

int tower_solve(int n, int from_rod, int to_rod, int aux_rod) {
  try {
    hanoi(n, from_rod, to_rod, aux_rod);
  } catch (std::string str) {
    throw std::string(str);
  }
  int result = counter;
  counter = 1;
  return result;
}
