// Copyright 2023 Antonova Anastasya

#include "../include/Hanoi_application.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>

#include "../include/hanoi_tower.h"

std::string HanoiApplication::operator()(int argc, const char** argv) {
  if (!IsValid(argc, argv)) return validatorMessage;

  int n = atoi(argv[1]);
  int from_rod = atoi(argv[2]);
  int to_rod = atoi(argv[3]);
  int aux_rod = atoi(argv[4]);

  std::string result;

  result = std::string("Result is: " +
      tower_solve(n, from_rod, to_rod, aux_rod));
  return result;
}

bool HanoiApplication::IsValid(int argc, const char** argv) {
  if (argc != 5) {
    validatorMessage = "Invalid number of arguments";
    return false;
  }
  for (int i = 1; i <= 4; i++) {
    int value = atoi(argv[i]);
    if (value < 1 || value > 3) {
        validatorMessage =
        "'from rod'/'to rod'/'aux rod' - must be in the range from 1 to 3";
        return false;
    }
  }
  return true;
}

int HanoiApplication::counter = 1;
