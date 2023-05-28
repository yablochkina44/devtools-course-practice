// Copyright 2023 Binko Alexandr

#include "../include/KonverterFR_application.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>

#include "../include/Converter.h"

std::string KonverterApplication::help() {
  return std::string(
      "This application is designed to translate numbers from Arabic to Roman "
      "and vice versa.Enjoy");
}

bool containsOnly(const std::string& str, const std::string& alphabet) {
  for (char c : str) {
    if (alphabet.find(c) == std::string::npos) {
      return false;
    }
  }
  return true;
}

bool KonverterApplication::IsValid(int argc, const char** argv) {
  if (argc == 1) {
    validatorMessage = help();
    return false;
  }

  if (argc > 2) {
    validatorMessage = std::string("Maksimalno 2 arguments");
    return false;
  }
  std::string str = std::string(argv[1]);
  bool flag = (containsOnly(str, allowedAlphabet) ||
               containsOnly(str, allowedNumbers)) &&
              !(containsOnly(str, allowedAlphabet) &&
                containsOnly(str, allowedNumbers));
  if (!flag) {
    validatorMessage = std::string("Invalid expression");
  }
  return flag;
}

std::string KonverterApplication::operator()(int argc, const char** argv) {
  if (!IsValid(argc, argv)) return validatorMessage;

  std::string result;
  std::string values = (std::string)argv[1];

  if (containsOnly(values, allowedAlphabet)) {
    result =
        std::string("Resultat of convert in Arabic is: " + toArabic(values));
  }
  if (containsOnly(values, allowedNumbers)) {
    result = std::string("Result of convert in Roman is: " +
                         toRoman(std::stoi(values)));
  }

  return result;
}
