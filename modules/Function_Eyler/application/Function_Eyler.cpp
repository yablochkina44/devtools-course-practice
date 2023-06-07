//  Copyright 2023 Gosteeva Ekaterina

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "../include/Function_Eyler_Application.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    std::cout << output;
    return 0;
}
