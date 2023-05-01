// Copyright 2023 Kandrin Alexey

#pragma once

#include <string>

#include "include/triangle.h"

class TriangleApp {
 public:
  std::string operator()(int argc, const char** argv);

 private:
  std::string help();
};
