//  Copyright 2023 Gosteeva Ekaterina

#ifndef MODULES_FUNCTION_EYLER_INCLUDE_FUNCTION_EYLER_APPLICATION_H_
#define MODULES_FUNCTION_EYLER_INCLUDE_FUNCTION_EYLER_APPLICATION_H_

#include <iostream>
#include <string>
#include <vector>

class Application {
 public:
    std::string operator()(int argc, const char** argv);
    std::string help();
    std::vector<int> parseFromParam(int argc, const char** argv);
    std::string calculate(std::vector<int> numbs);
};

#endif  //  MODULES_FUNCTION_EYLER_INCLUDE_FUNCTION_EYLER_APPLICATION_H_
