// Copyright 2023 Zorin Oleg

#include <iostream>
#include <string>

#include "include/binary_tree_app.h"

int main(int argc, const char **argv) {
  BTApplication app;
  std::string out = app(argc, argv);
  std::cout << out << std::endl;
  return 0;
}
