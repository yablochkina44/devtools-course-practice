// Copyright 2023 Nikolaev Alexander

#include "include/interpolation_search_app.h"

void InterpolationSearchApp::help() {
    message.append("This is application for interpolation search.\n")
    .append("Please provide arguments in the following format:\n")
    .append("<1 element> <2 element> ... <n element> <target_element>\n")
    .append("All elements must be integer!");
}

std::string calc(std::vector<int> vec, int target) {
    std::string res;

    interpolationSearch interpolationSearch(vec);

    return std::to_string(interpolationSearch.search(target));
}

bool checkIsNumber(const char* elem) {
    std::string str(elem);
    const int size_str = str.length();

    if (str[0] == '-') {
        for (int i = 1; i < size_str; i++) {
            if (std::isdigit(str[i])) {
                continue;
            } else {
                return false;
            }
        }
    } else {
        for (int i = 0; i < size_str; i++) {
            if (std::isdigit(str[i])) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

std::string InterpolationSearchApp::operator() (int argc, const char** argv) {
    if (argc <= 1) {
        help();
        return message;
    }

    std::vector<int> search_vector;
    int target;
    std::string result;

    for (int i = 1; i < argc - 1; i++) {
        if (checkIsNumber(argv[i])) {
            search_vector.push_back(std::atoi(argv[i]));
        } else {
            return "Not a number!";
        }
    }

    if (checkIsNumber(argv[argc - 1])) {
        target = std::atoi(argv[argc - 1]);
    } else {
        return "Not a number!";
    }

    message = calc(search_vector, target);

    return message;
}
