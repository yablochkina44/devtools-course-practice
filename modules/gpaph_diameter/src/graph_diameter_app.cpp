// Copyright 2023 Khairetdinov Timur

#include "include/graph_diameter_app.h"
#include "include/graph_diameter.h"

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>



void GraphApplication::info(const char* appname, const char* mes) {
    message =
        std::string(mes) +
        "calculation of the graph diameter\n" +
        "format of arguments:\n" +
        "  $ " + appname + " <vector> <vector> ... <vector>\n\n";
}

bool GraphApplication::validate(int argc, const char** argv) {
    if (argc == 1) {
        info(argv[0]);
        return false;
    } else if (argc < 3) {
        info(argv[0], "error: 1 argument is expected\n\n");
        return false;
    }
    return true;
}

std::vector<std::vector<int>> parseVector(int argc, const char** arg) {
    std::string strI = "";
    std::vector<std::vector<int>> buf_vector;
    char* end;
    int number;
    int index = -1;
    for (int i = 1; i < argc; i++) {
        std::string  strVec = arg[i];
        std::vector<int > t;
        buf_vector.push_back(t);
        index++;
        for (unsigned int i = 0; i < strVec.size(); i++) {
            if (strVec[i] == ',') {
                if (strI == "") {
                    throw std::string("Incorrect format of vector");
                }
                number = strtof(strI.c_str(), &end);
                if (end[0]) {
                    throw std::string("Incorrect format of number");
                }
                buf_vector[index].push_back(number);
                strI = "";
            } else {
                strI += strVec[i];
            }
        }

        if (strI == "") {
            throw std::string("Incorrect format of vector");
        }
        number = strtof(strI.c_str(), &end);
        if (end[0]) {
            throw std::string("Incorrect format of number");
        }
        buf_vector[index].push_back(number);
        strI = "";
    }
    return buf_vector;
}


GraphApplication::GraphApplication() {}

std::string GraphApplication::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validate(argc, argv)) {
        return message;
    }
    try {
        args.matrix = parseVector(argc, argv);
    }
    catch (std::string& str) {
        return str;
    }

    Graph v1(args.matrix);
    std::string result = std::to_string(v1.GetDiameter());
    return result;
}
