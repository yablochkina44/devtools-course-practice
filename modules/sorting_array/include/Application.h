// Copyright 2023 Tarasova Anastasiya
#ifndef MODULES_SORTING_ARRAY_INCLUDE_APPLICATION_H_
#define MODULES_SORTING_ARRAY_INCLUDE_APPLICATION_H_

#include <string>

class Application {
 public:
  Application() = default;
  std::string operator()(int argc, const char** argv);
 private:
  void help(const char* appname);
  bool validateArguments(int argc, const char** argv);
  std::string message;
};

#endif  // MODULES_SORTING_ARRAY_INCLUDE_APPLICATION_H_
