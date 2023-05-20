// Copyright 2023 Kudryashov Nikita

#ifndef MODULES_LONGEST_COMMON_SUBSEQUENCE_INCLUDE_LONGEST_COMMON_SUBSEQUENCE_APP_H_
#define MODULES_LONGEST_COMMON_SUBSEQUENCE_INCLUDE_LONGEST_COMMON_SUBSEQUENCE_APP_H_

#include <string>

class LongestCommonSubsequenceApp {
 public:
    LongestCommonSubsequenceApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_LONGEST_COMMON_SUBSEQUENCE_INCLUDE_LONGEST_COMMON_SUBSEQUENCE_APP_H_
