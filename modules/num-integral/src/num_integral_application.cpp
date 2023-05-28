  // Copyright 2023 Nikitin Aleksandr

#include "../include/num_integral_application.h"

#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

#include "../include/num_integral.h"

std::string IntegralApplication::help(const char* programName) {
  std::stringstream help;
  help << "Usage:" << programName << "\nFunctions:\n"
       << "  1D: integral1D [a] [b] [n]\n"
       << "  2D: integral2D [a] [b] [c] [d] [n]\n"
       << "  3D: integral3D [a] [b] [c] [d] [e] [f] [n]\n"
       << "Options:\n"
       << "  [a], [b], [c], [d], [e], [f]: Integration limits\n"
       << "  [n]: Number of segments\n";

  return help.str();
}

double IntegralApplication::ParseToDouble(const char* arg) {
  double result = 0.0;

  result = std::stod(arg);

  return result;
}

bool IntegralApplication::validateNumberOfArguments(int argc,
                                                    const char** argv) {
  if (argc == 1) {
    invalid_argument = help(argv[0]);
    return false;
  }

  if (argc == 2) {
    invalid_argument = std::string("Incorrect number of arguments!");
    return false;
  }

  if (argc == 3) {
    invalid_argument = std::string("Incorrect number of arguments!");
    return false;
  }

  if (argc == 5) {
    invalid_argument = std::string("Incorrect number of arguments!");
    return false;
  }

  if (argc == 7) {
    invalid_argument = std::string("Incorrect number of arguments!");
    return false;
  }

  if (argc > 8) {
    invalid_argument = std::string("Too many arguments!");
    return false;
  }

  return true;
}

double f1D(double x) { return x * x; }

double f2D(double x, double y) { return x * x + y * y; }

double f3D(double x, double y, double z) { return x * x + y * y + z * z; }

std::string IntegralApplication::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) return invalid_argument;

  std::string result;
  std::vector<double> values;

  for (int i = 1; i < argc; i++) {
    double value;
    value = ParseToDouble(argv[i]);
    values.push_back(value);
  }

  switch (values.size()) {
    case 3: {
      result = std::string("Integral 1D: ") +
               std::to_string(NumIntegral::integral1D(values[0], values[1],
                                                      values[2], f1D));
    } break;
    case 5: {
      result = std::string("Integral 2D: ") +
               std::to_string(NumIntegral::integral2D(
                   values[0], values[1], values[2], values[3], values[4], f2D));
    } break;
    case 7: {
      result = std::string("Integral 3D: ") +
               std::to_string(NumIntegral::integral3D(
                   values[0], values[1], values[2], values[3], values[4],
                   values[5], values[6], f3D));
    } break;
  }

  return result;
}
