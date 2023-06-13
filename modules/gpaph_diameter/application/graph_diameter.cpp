// Copyright 2023 Khairetdinov Timur

#include "include/graph_diameter_app.h"

#include <iostream>
#include <string>

int main(int argc, const char** argv) {
    GraphApplication app;
    auto result = app(argc, argv);
    std::cout << result << std::endl;
    return 0;
}
