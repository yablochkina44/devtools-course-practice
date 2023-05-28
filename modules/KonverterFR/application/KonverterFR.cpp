// Copyright 2023 Binko Alexandr

#include "../include/KonverterFR_application.h"

int main(int argc, const char **argv) {
  KonverterApplication app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
