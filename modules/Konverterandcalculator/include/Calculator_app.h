// Copyright 2023 Lapin Dmitriy

#ifndef MODULES_KONVERTERANDCALCULATOR_INCLUDE_CALCULATOR_APP_H_
#define MODULES_KONVERTERANDCALCULATOR_INCLUDE_CALCULATOR_APP_H_

#include <string>

class BaseCalculator {
 public:
    BaseCalculator();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::string num1;
        int base1;
        std::string num2;
        int base2;
        char operation;
    } Arguments;
};
#endif  // MODULES_KONVERTERANDCALCULATOR_INCLUDE_CALCULATOR_APP_H_
