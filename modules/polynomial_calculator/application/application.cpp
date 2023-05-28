// Copyright 2023 Shipilov Artem

#include <iostream>
#include <string>
#include "include/polynomial_calculator_application.h"

int main(int argc, const char** argv) {
    polynomial_calculator_Application app;
    std::string output = app(argc, argv);
    printf("%s", output.c_str());
    return 0;
}
