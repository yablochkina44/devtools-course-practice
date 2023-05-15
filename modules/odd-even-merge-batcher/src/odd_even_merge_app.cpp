// Copyright 2023 Elistratov Vladimir

#include "include/odd_even_merge_app.h"

#include <iostream>
#include <sstream>
#include <string>

#include "include/odd_even_merge.h"

std::string OddEvenMergeApplication::operator()(int argc, const char** argv) {
  if (argc <= 1 || std::string(argv[1]).empty()) return printHelp(argv[0]);

  const int sizeArray = std::stoi(argv[1]);
  std::vector<int> array = OddEvenMerge::getRandomArray(sizeArray);

  Message += "Original array:\n";
  for (int i = 0; i < sizeArray; i++) {
    Message += std::to_string(array[i]);
    Message += " ";
  }
  Message += "\n";

  OddEvenMerge::OddEvenMergeBatcherSort(&array);

  Message += "Sorted array:\n";
  for (int i = 0; i < sizeArray; i++) {
    Message += std::to_string(array[i]);
    Message += " ";
  }
  Message += "\n";

  return Message;
}

std::string OddEvenMergeApplication::printHelp(const std::string& programName) {
  std::stringstream ss;
  ss << "Usage:" << programName << " sizeArray" << std::endl;
  return ss.str();
}
