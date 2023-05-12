// Copyright 2023 Shokurov Daniil

#ifndef MODULES_LONGEST_INCREASING_SUBSEQUENCE_INCLUDE_LONGEST_INC_SUBSEQ_APPLICATION_H_
#define MODULES_LONGEST_INCREASING_SUBSEQUENCE_INCLUDE_LONGEST_INC_SUBSEQ_APPLICATION_H_

#include <string>

class Application {
 public:
  Application();
  std::string operator()(int argc, const char** argv);

 private:
  void help(const char* appname, const char* message = "");
  bool validateNumberOfArguments(int argc, const char** argv);
  std::string message_;
};

#endif  // MODULES_LONGEST_INCREASING_SUBSEQUENCE_INCLUDE_LONGEST_INC_SUBSEQ_APPLICATION_H_
