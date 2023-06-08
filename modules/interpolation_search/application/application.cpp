// Copyright 2023 Nikolaev Alexander

#include <stdio.h>

#include "include/interpolation_search_app.h"

int main(int argc, const char** argv) {
    InterpolationSearchApp interpolationSearchApp;
    std::string output = interpolationSearchApp(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
