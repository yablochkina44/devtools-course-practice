// Copyright 2017 Lapin Dmitriy

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Calculator_app.h"

int main(int argc, const char** argv) {
    BaseCalculator app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
