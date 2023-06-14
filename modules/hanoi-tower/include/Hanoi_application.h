// Copyright 2023 Antonova Anastasya

#ifndef MODULES_HANOI_TOWER_INCLUDE_HANOI_APPLICATION_H_
#define MODULES_HANOI_TOWER_INCLUDE_HANOI_APPLICATION_H_

#include <iostream>
#include <cstdlib>
#include <string>

class HanoiApplication {
 public:
  std::string operator()(int argc, const char** argv);
  static int counter;
  bool IsValid(int argc, const char** argv);
  std::string validatorMessage;
};

#endif  // MODULES_HANOI_TOWER_INCLUDE_HANOI_APPLICATION_H_
