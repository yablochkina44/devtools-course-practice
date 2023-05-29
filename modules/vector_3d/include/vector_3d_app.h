// Copyright 2023 Yashina Anastasia

#ifndef MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_APP_H_
#define MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_APP_H_

#include <string>

class vector3dApp {
 public:
     vector3dApp();
    std::string operator()(int argc, const char** argv);
 private:
    void info(const char* appname, const char* message = "");
    bool checkArgNumber(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double x1;
        double y1;
        double z1;
        std::string operation;
        double x2;
        double y2;
        double z2;
    } Arguments;
};

#endif  // MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_APP_H_
