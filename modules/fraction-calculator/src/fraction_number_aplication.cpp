// Copyright 2023 Mukhin Vadim

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../include/fraction_number.h"
#include "../include/fraction_number_application.h"

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
  message_ = std::string(message) +
             "This app performs basic operations with fractions.\n\n" +
             "Please provide arguments in the following format:\n\n" + "  $ " +
             appname + " <fraction_1> <operation> <fraction_2>\n\n" +
             "Where <fraction_1> and <fraction_2> are in the format a/b,\n" +
             "and <operation> is one of the following: +, -, *, /, ==, !=.\n";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
  if (argc != 4) {
    help(argv[0], "");
    return false;
  }
  return true;
}

FractionNumber parseFraction(const std::string& str) {
  std::stringstream ss(str);
  std::string token;
  std::vector<int> nums;

  while (std::getline(ss, token, '/')) {
    nums.push_back(std::stoi(token));
  }

  if (nums.size() != 2) {
    throw std::string("Wrong fraction format!");
  }

  return FractionNumber(nums[0], nums[1]);
}

std::string Application::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    help(argv[0], "");
    return message_;
  }

  FractionNumber num1, num2;
  std::string operation = argv[2];

  try {
    num1 = parseFraction(argv[1]);
    num2 = parseFraction(argv[3]);
  } catch (std::string& str) {
    return str;
  }

  FractionNumber result;

  if (operation == "+") {
    result = num1 + num2;
  } else if (operation == "-") {
    result = num1 - num2;
  } else if (operation == "*") {
    result = num1 * num2;
  } else if (operation == "/") {
    result = num1 / num2;
  } else if (operation == "==") {
    message_ = (num1 == num2) ? "true" : "false";
    return message_;
  } else if (operation == "!=") {
    message_ = (num1 != num2) ? "true" : "false";
    return message_;
  } else {
    return "Invalid operation";
  }

  message_ = std::to_string(result.getNumerator()) + "/" +
             std::to_string(result.getDenominator());

  return message_;
}
