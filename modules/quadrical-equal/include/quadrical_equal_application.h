// Copyright 2023 Ermolaev Danila

#ifndef MODULES_QUADRICAL_EQUAL_INCLUDE_QUADRICAL_EQUAL_APPLICATION_H_
#define MODULES_QUADRICAL_EQUAL_INCLUDE_QUADRICAL_EQUAL_APPLICATION_H_

#include <string>

class Quad_Application {
 public:
    Quad_Application();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};


#endif  // MODULES_QUADRICAL_EQUAL_INCLUDE_QUADRICAL_EQUAL_APPLICATION_H_
