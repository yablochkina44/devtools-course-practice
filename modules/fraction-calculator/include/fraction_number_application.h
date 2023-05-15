// Copyright 2023 Mukhin Vadim

#ifndef MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_NUMBER_APPLICATION_H_
#define MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_NUMBER_APPLICATION_H_

#include <string>
class Application {
 public:
  Application();
  void help(const char* appname, const char* message);
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string operator()(int argc, const char** argv);
 private:
  std::string message_;
};
#endif  // MODULES_FRACTION_CALCULATOR_INCLUDE_FRACTION_NUMBER_APPLICATION_H_
