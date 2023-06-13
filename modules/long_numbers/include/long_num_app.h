// Copyright 2023 Rezchikov Dmitrii

#ifndef MODULES_LONG_NUMBERS_INCLUDE_LONG_NUM_APP_H_
#define MODULES_LONG_NUMBERS_INCLUDE_LONG_NUM_APP_H_

#include "../include/long_num.h"
#include <string>

/// @brief calculator app, docs are in .cpp file, dont have time bye
class LongCalculator{
 public:
    LongCalculator();
    std::string operator()(int argc, const char **argv);
 private:
    std::string message_;
    void help(const char *appname, const char *message = "");
    bool validateNumberOfArguments(int argc, const char **argv);
    typedef struct {
        LongNumber n1;
        LongNumber n2;
        char operation;
    } Arguments;
};

#endif  // MODULES_LONG_NUMBERS_INCLUDE_LONG_NUM_APP_H_
