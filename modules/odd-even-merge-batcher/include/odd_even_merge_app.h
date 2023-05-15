// Copyright 2023 Elistratov Vladimir

#ifndef MODULES_ODD_EVEN_MERGE_BATCHER_INCLUDE_ODD_EVEN_MERGE_APP_H_
#define MODULES_ODD_EVEN_MERGE_BATCHER_INCLUDE_ODD_EVEN_MERGE_APP_H_

#include <string>

#include "include/odd_even_merge.h"

class OddEvenMergeApplication {
 public:
  std::string operator()(int argc, const char** argv);

 private:
  std::string Message;
  std::string printHelp(const std::string& programName);
};

#endif  // MODULES_ODD_EVEN_MERGE_BATCHER_INCLUDE_ODD_EVEN_MERGE_APP_H_
