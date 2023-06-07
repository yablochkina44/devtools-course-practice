// Copyright 2023 Zorin Oleg
#ifndef MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_APP_H_
#define MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_APP_H_

#include <string>
#include <exception>
#include <cctype>
#include "include/binary_tree.h"

class BTApplication {
 public:
  BTApplication();
  std::string operator()(int argc, const char **argv);
 private:
  std::string message_;
  void help(const char *appname, const char *message = "");
  static char parseOperation(const char *arg);
  BinaryTree tree;
};

#endif  //  MODULES_BINARY_TREE_INCLUDE_BINARY_TREE_APP_H_
