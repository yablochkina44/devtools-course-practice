// Copyright 2023 Ermolaev Danila

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/quadrical_equal_application.h"

int main(int argc, const char** argv) {
  Quad_Application app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
