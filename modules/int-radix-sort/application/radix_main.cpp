// Copyright 2023 Mikerin Ilya

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/radix_application.h"

int main(int argc, const char** argv) {
    radix_application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
