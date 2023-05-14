// Copyright 2023 Ermolaev Danila

#include "../include/quadrical_equal.h"
#include "../include/quadrical_equal_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

Quad_Application::Quad_Application() : message_("") {}

void Quad_Application::help(const char* appname, const char* message) {
    message_ = std::string(message) +
            "This app is for solving quadratic equations.\n\n" +
            "Please provide arguments in the following format:\n\n" +
            "  $ " + appname + " <value_1> <value_2> <value_3> \n\n"+
            "Where all values are double.\n "+
            "Example:1 2 3 -> Result equations: 1*x^2 + 2*x + 3 = 0";
}

bool Quad_Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc != 3) {
        help(argv[0]);
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtold(arg, &end);
    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string Quad_Application::operator()(int argc, const char** argv) {
    std::vector<double> parameters;
    if (!validateNumberOfArguments(argc, argv)) {
      return message_;
    }
    try {
        for (int i = 1; i < argc; ++i) {
            double value = parseDouble(argv[i]);
            parameters.push_back(value);
        }
    } catch (std::string& str) {
        return str;
    }
    std::string result;
    try {
        Quadrical_equal z1;
        result = z1.solution(parameters[0], parameters[1], parameters[2]);
    } catch(std::string str) {
        return str;
    }
    message_ = result;
    return message_;
}

