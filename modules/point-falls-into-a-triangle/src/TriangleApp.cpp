// Copyright 2023 Kandrin Alexey

#include "include/TriangleApp.h"

#include <memory>
#include <sstream>

#include "include/triangle.h"

static const char* const triangleToken = "triangle";
static const char* const pointToken = "point";

static bool ReadDouble(const char * str, double * value) {
    std::istringstream istr(str);
    istr >> *value;
    return !istr.fail();
}

std::string TriangleApp::help() {
    return std::string("With this application you can determine") +
        " if a point falls within a triangle.\n\n" +
        "Parameters:\n" +
        triangleToken + " <x1 y1 x2 y2 x3 y3>\t\t Input coords of triangle.\n" +
        pointToken + " <x0 y0> \t\t Input coords of point.\n";
}

std::string TriangleApp::operator()(int argc, const char** argv) {
    if (argc == 1)
        return help();

    std::unique_ptr<Triangle> triangle;
    std::unique_ptr<Point> point;

    auto readPoints = [argc, argv](int& argvIndex, double* coords,
        int coordsCount) {
        for (int coordIndex = 0;
            argvIndex < argc && coordIndex < coordsCount;
            ++argvIndex, ++coordIndex) {
            if (!ReadDouble(argv[argvIndex], &coords[coordIndex]))
                return false;
        }
        --argvIndex;
        return true;
    };

    for (int i = 1; i < argc; ++i) {
        std::string key = argv[i];
        if (key == triangleToken) {
            ++i;

            const int coordsCount = 6;
            double coords[coordsCount] = {};
            if (!readPoints(i, coords, coordsCount))
                return std::string("Error: incorrect param in ") +
                  triangleToken;

            Point point1{ coords[0], coords[1] };
            Point point2{ coords[2], coords[3] };
            Point point3{ coords[4], coords[5] };
            triangle.reset(new Triangle(point1, point2, point3));
        } else if (key == pointToken) {
            ++i;

            const int coordsCount = 2;
            double coords[coordsCount] = {};
            if (!readPoints(i, coords, coordsCount))
                return std::string("Error: incorrect param in ") + pointToken;

            point.reset(new Point{ coords[0], coords[1] });
        } else {
            return "Error: unknown key " + key;
        }
    }

    if (triangle && point)
        return triangle->Consist(*point) ?
          "Triangle contains point" : "Triangle does not contain point";
    else
        return std::string("Error: missing ") +
          (!triangle ? triangleToken : pointToken) + " parameter";
}
