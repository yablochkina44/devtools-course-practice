// Copyright 2023 Terina Alina

#include "include/basic_param_tr.h"

#include <iostream>
#include <stdexcept>
#include <string>

#include "include/lebedinskiy_ilya_triangle_basic_params.h"

std::string application::operator()(int argc, char** argv) {
    float result = -1.f;
    if (argc == 1) {
        return help(argv[0]);
    }
    if (argc < 5) {
        return "Text of error: arguments not enough";
    }
    if (argc > 6) {
        return "Text of error: arguments more than its needed";
    }
    arguments args;
    if (validate(argv[0])) args = arg_parse(argc, argv);
    Triangle triangle(args.a, args.b, args.c);
    if (args.operation == "perimeter") result = triangle.get_perimeter();
    if (args.operation == "square") result = triangle.get_square();
    if (args.operation == "height") result = triangle.get_height(args.side);
    return std::to_string(result);
}

std::string application::help(const std::string& an) {
    return "App was created to show coordinates points of verts "
        "and calculation of the main parameters of a triangle "
        "the triangle\n how use :\n" +
        an +
        "(x1,y1) (x2,y2) (x3,y3) <operation> <side for height "
        "operation>\n Where <operation> is:\n1. "
        "perimeter\n2. "
        "square\n3. height";
}

bool application::validate(const std::string& str) { return true; }

application::arguments application::arg_parse(int argc, char** argv) {
    arguments args;
    for (int i = 1; i <= 3; i++) {
        std::string dot = argv[i];
        auto delimeter = dot.find(",");
        float d = std::stof(dot.substr(0, delimeter));
        float g = std::stof(dot.substr(delimeter + 1));
        if (i == 1) args.a = { d, g };
        if (i == 2) args.b = { d, g };
        if (i == 3) args.c = { d, g };
    }
    args.operation = argv[4];
    if (argc > 5) args.side = std::stoi(argv[5]);
    return args;
}
