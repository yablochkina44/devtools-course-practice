// Copyright 2023 Elistratov Vladimir

#include "include/odd_even_merge_app.h"

int main(int argc, const char **argv) {
  OddEvenMergeApplication app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
