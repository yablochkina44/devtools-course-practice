// Copyright 2023 Lebedinskiy Ilya

#ifndef  MODULES_REV_POL_NOT_INCLUDE_REV_POL_APP_H_
#define  MODULES_REV_POL_NOT_INCLUDE_REV_POL_APP_H_

#include <string>

class Application {
 public:
    std::string operator()(int argc, const char* argv[]);
 private:
    static inline std::string help(const char* appname);
};

#endif  //  MODULES_REV_POL_NOT_INCLUDE_REV_POL_APP_H_
