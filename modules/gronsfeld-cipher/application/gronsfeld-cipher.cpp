// Copyright 2023 Ivlev Alexander

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "include/gronsfeld_cipher_app.h"

int main(int argc, const char** argv) {
    gronsfeld_cipher_app app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
