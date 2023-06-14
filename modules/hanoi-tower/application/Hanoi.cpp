// Copyright 2023 Antonova Anastasya

#include "../include/Hanoi_application.h"

int main(int argc, const char** argv) {
  HanoiApplication app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
