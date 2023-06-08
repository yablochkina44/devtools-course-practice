// Copyright 2023 Nikolaev Alexander

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_APP_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_APP_H_

#include <vector>
#include <string>

#include "include/interpolation_search.h"

class InterpolationSearchApp {
 public:
    void help();
    std::string operator()(int argc, const char** argv);

 private:
    std::string message;
};

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATION_SEARCH_APP_H_
