// Copyright 2023 Yashina Anastasia

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

#include "include/vector_3d.h"
#include "include/vector_3d_app.h"

vector3dApp::vector3dApp() : message_("") {}

void vector3dApp::info(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This application can do operations with 3d vectors\n" +
        "Format of arguments:\n" +
        "  $ " + appname + " x1 y1 z1 " +
        "<operation> x2 y2 z2 \n" +
        "All arguments must be double-precision numbers.\n" +
        "List of operations:\n 'get_norma'\n 'get_normalization'\n"+
        "'scalar_mult'\n 'vector_mult' \n";
}

double checkFormat(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong format of number");
    }

    return value;
}

std::string checkOperation(const char* arg) {
    std::string op;
    if (strcmp(arg, "get_norma") == 0) {
        op = "get_norma";
    } else {
        if (strcmp(arg, "get_normalization") == 0) {
            op = "get_normalization";
        } else {
            if (strcmp(arg, "scalar_mult") == 0) {
                op = "scalar_mult";
            } else {
                if (strcmp(arg, "vector_mult") == 0) {
                    op = "vector_mult";
                } else {
                    throw std::string("Wrong format of operation");
                }
            }
        }
    }
         return op;}

bool  vector3dApp::checkArgNumber(int argc, const char** argv) {
    if (argc == 1) {
        info(argv[0]);
        return false;
    }
    if ((argc != 5) && (argc != 8)) {
        info(argv[0], "Wrong number of arguments.\n\n");
        return false;
    }
    return true;
}

std::string vector3dApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!checkArgNumber(argc, argv)) {
        return message_;
    }
    try {
        args.x1 = checkFormat(argv[1]);
        args.y1 = checkFormat(argv[2]);
        args.z1 = checkFormat(argv[3]);
        args.operation = checkOperation(argv[4]);
        if (argc > 5)
            args.x2 = checkFormat(argv[5]);
        else
            args.x2 = 0;
        if (argc > 6)
            args.y2 = checkFormat(argv[6]);
        else
            args.y2 = 0;
        if (argc > 7)
            args.z2 = checkFormat(argv[7]);
        else
            args.z2 = 0;
    }
    catch (std::string& str) {
        return str;
    }
    Vector3d vec1(args.x1, args.y1, args.z1);
    Vector3d vec2(args.x2, args.y2, args.z2);
    Vector3d ans;
    double res;
    std::ostringstream stream;
    if (args.operation == "get_norma") {
        res = vec1.get_norma();
        stream << "Norm = " << res;
    }
    if (args.operation == "get_normalization") {
        try {
            ans = vec1.get_normalization();
            stream << "V = (" << ans[0] << "," << ans[1]
                << "," << ans[2] << ")";
        }
        catch (const std::exception& e) {
            return e.what();
        }
    }
    if (args.operation == "scalar_mult") {
        res = vec1.scalar_mult(vec1, vec2);
        stream << "Scalar_mult = " << res;
    }
    if (args.operation == "vector_mult") {
        ans = vec1.vector_mult(vec1, vec2);
        stream << "V = (" << ans[0] << "," << ans[1]
            << "," << ans[2] << ")";
    }
    message_ = stream.str();

    return message_;
}
