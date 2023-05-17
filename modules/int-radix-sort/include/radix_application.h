// Copyright 2023 Mikerin Ilya

#ifndef MODULES_INT_RADIX_SORT_INCLUDE_RADIX_APPLICATION_H_
#define MODULES_INT_RADIX_SORT_INCLUDE_RADIX_APPLICATION_H_

#include <string>
#include <vector>
#include <cstdlib>

class radix_application{
 public:
    radix_application();

    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        size_t size;
        std::vector<int> vec;
    } Arguments;
};


#endif  // MODULES_INT_RADIX_SORT_INCLUDE_RADIX_APPLICATION_H_
