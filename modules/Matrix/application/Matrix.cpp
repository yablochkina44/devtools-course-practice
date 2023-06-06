// Copyright 2023 Pashina Alina
#include <stdio.h>
#include <stdlib.h>

#include <string>

#include "../include/matrix_app.h"

int main(int argc, char** argv) {
  MatrixAPP m;
  std::string output = m(argc, argv);
  std::cout << output;
  return 0;
}
