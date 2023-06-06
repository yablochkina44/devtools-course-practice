// Copyright 2023 Pashina Alina

#include "../include/matrix_app.h"

#include <math.h>

#include <iostream>
#include <stdexcept>
#include <string>

std::string MatrixAPP::operator()(int argc, char** argv) {
  if (argc == 1) {
    return helping_text(argv[0]);
  }
  if (argc < 5) {
    return "Need more arguments";
  }
  std::string str_result = "";
  arguments args = param_parsing(argc, argv);
  matrix res;
  if (args.operation == "plus") {
    res = args.m1 + args.m2;
    for (int i = 0; i < res.getRows(); i++) {
      for (int j = 0; j < res.getColumns(); j++) {
        str_result = str_result + std::to_string(res.getMatrix()[i][j]);
      }
    }
  }
  return str_result;
}

std::string MatrixAPP::helping_text(const std::string& an) {
  return "This app for actions with matrix";
}

MatrixAPP::arguments MatrixAPP::param_parsing(int argc, char** argv) {
  arguments args;
  int size1 = std::stoi(argv[1]);
  int size2 = std::stoi(argv[2]);
  double** mm1 = new double*[size1];
  double** mm2 = new double*[size2];

  std::string dot = argv[3];
  auto delimeter = dot.find(",");
  for (int i = 0; i < size1 * size1 - 1; i++) {
    delimeter = dot.find(",");
    mm1[static_cast<int>(i / size1)][static_cast<int>(i % size1)] =
        std::stof(dot.substr(0, delimeter));
  }
  mm1[size1 - 1][size1 - 1] = std::stoi(dot.substr(delimeter + 1));
  args.m1 = matrix(mm1, size1, size1);
  std::cout << "was in parsing" << std::endl;
  std::string dot2 = argv[4];
  for (int i = 0; i < size2 * size2 - 1; i++) {
    delimeter = dot2.find(",");
    mm2[static_cast<int>(i / size2)][static_cast<int>(i % size2)] =
        std::stof(dot2.substr(0, delimeter));
  }
  mm2[size2 - 1][size2 - 1] = std::stoi(dot2.substr(delimeter + 1));
  args.m2 = matrix(mm2, size2, size2);

  args.operation = argv[5];

  return args;
}
