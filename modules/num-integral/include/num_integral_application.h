// Copyright 2023 Nikitin Aleksandr

#ifndef MODULES_NUM_INTEGRAL_INCLUDE_NUM_INTEGRAL_APPLICATION_H_
#define MODULES_NUM_INTEGRAL_INCLUDE_NUM_INTEGRAL_APPLICATION_H_

#include <string>

class IntegralApplication {
 private:
 public:
  std::string help(const char* programName);
  double ParseToDouble(const char* arg);
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string operator()(int argc, const char** argv);
  std::string invalid_argument;
};

#endif  // MODULES_NUM_INTEGRAL_INCLUDE_NUM_INTEGRAL_APPLICATION_H_
