// Copyright 2023 Mukhin Vadim

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/fraction_number_application.h"

#include "include/fraction_number.h"

int main(int argc, const char** argv) {
  Application app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
