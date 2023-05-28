// Copyright 2023 Nikitin Aleksandr

#include "../include/num_integral_application.h"

int main(int argc, const char **argv) {
  IntegralApplication app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
