// Copyright 2023 Kruglikova Valeriia

#include <cstring>
#include <stdexcept>
#include "include/intersections_line_and_plane_app.h"

I3DApplication::I3DApplication() = default;

void I3DApplication::help(const char* appname) {
    std::string mes = "";
    message_ = mes +
        "This is application that finds intersection of inputs" +
        "of lines and planes.\n\n" +
        "  $ " +
        appname +
        " <plane values> <dot values> <direction values> \n\n" +
        "Where <plane values> are four arguments for A B C and D" +
        "coefficients defining the plane \n\n" +
        "Where <dot values> are three arguments for A B C"
        "coefficients defining the dot \n\n" +
        "Where <direction values> are three arguments for A B C" +
        "coefficients defining the direction\n\n";
}

std::string I3DApplication::operator()(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
    } else {
        char* ptr;
        std::vector<double>plane = {
                    static_cast<double>(strtol(argv[1], &ptr, 10)),
                    static_cast<double>(strtol(argv[2], &ptr, 10)),
                    static_cast<double>(strtol(argv[3], &ptr, 10)),
                    static_cast<double>(strtol(argv[4], &ptr, 10)) };
        std::vector<double>dot = {
            static_cast<double>(strtol(argv[5], &ptr, 10)),
            static_cast<double>(strtol(argv[6], &ptr, 10)),
            static_cast<double>(strtol(argv[7], &ptr, 10)) };
        std::vector<double>dir = {
            static_cast<double>(strtol(argv[8], &ptr, 10)),
            static_cast<double>(strtol(argv[9], &ptr, 10)),
            static_cast<double>(strtol(argv[10], &ptr, 10)) };
        if (isIntersection(plane, dot, dir).first == 0)
            message_ = "A straight line intersects a plane.";
        else if (isIntersection(plane, dot, dir).first == 1)
            message_ = "A straight line belongs a plane";
        else
            message_ = "A straight line parallel a plane";
    }
    return message_;
}
