// Copyright 2023 Kruglikova Valeriia

#include <iostream>
#include <string>

#include "include/intersections_line_and_plane_app.h"

int main(int argc, const char** argv) {
    I3DApplication app;
    std::string out = app(argc, argv);
    std::cout << out << std::endl;
    return 0;
}
