// Copyright 2023 Shokurov Daniil

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/longest_inc_subseq_application.h"

int main(int argc, const char** argv) {
  Application app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
