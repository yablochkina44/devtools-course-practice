// Copyright 2023 Pashina Alina

#ifndef MODULES_MATRIX_INCLUDE_MATRIX_APP_H_
#define MODULES_MATRIX_INCLUDE_MATRIX_APP_H_

#include "./matrix.h"

#include <iostream>
#include <string>

class MatrixAPP {
 public:
  struct arguments {
    matrix m1;
    matrix m2;
    std::string operation{""};
  };

 public:
  std::string operator()(int argc, char** argv);

 private:
  std::string helping_text(const std::string& an);
  arguments param_parsing(int argc, char** argv);
};
#endif  //  MODULES_MATRIX_INCLUDE_MATRIX_APP_H_
