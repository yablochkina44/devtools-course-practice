// Copyright 2023 Tarasova Anastasiya
#include <string>
#include <sstream>
#include <cstring>
#include "include/Application.h"
#include "include/sorting_array.h"

size_t parseInt(const char* arg) {
    int val = 0;
    std::stringstream s(arg);
    s >> val;
    if (s.fail() || val < 0) {
        throw std::invalid_argument("Expected unsigned integer value.");
    }

    return static_cast<size_t>(val);
}

double parseDouble(const char* arg) {
    double val = 0;
    std::stringstream s(arg);
    s >> val;
    if (s.fail()) {
        throw std::invalid_argument("Expected double value.");
    }

    return val;
}

void Application::help(const char* appname) {
    std::string sb;
    sb
        .append("This program is designed to sort array ")
        .append("Please provide arguments in the following format:\n\n")
        .append("  $ ")
        .append(appname)
        .append(" <count> <sort> <array> \n\n")
        .append("Where <count> is integer size of array\n")
        .append("<sort> is integer sort type (1-Insert, 2-Quick\n")
        .append("<array> is double array\n");

    message = std::move(sb);
}

bool Application::validateArguments(int argc, const char** argv) {
    std::string helper_str =
        std::string(" Type `$ ").append(argv[0])
        .append("` to see help message");

    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 3) {
        message =
            std::string("Not enough data!");

        return false;
    }

    size_t count;
    try {
        count = parseInt(argv[1]);
    }
    catch (const std::invalid_argument& e) {
        message =
            std::string("Wrong count format!")
            .append(e.what());
        return false;
    }
    size_t sort;
    try {
        sort = parseInt(argv[2]);
    }
    catch (const std::invalid_argument& e) {
        message =
            std::string("Wrong sort format!")
            .append(e.what());
        return false;
    }
    if (argc == 3) {
        message =
            std::string("Array is empty!");
        return false;
    }

    if (sort < 1 || sort > 2) {
        message =
            std::string("Wrong sort value!");
        return false;
    }

    if (static_cast<size_t>(argc) < (3 + count)) {
        message =
            std::string("Array is not completely filled!");
        return false;
    }

    if (static_cast<size_t>(argc) > (3 + count)) {
        message =
            std::string("Array is overwhelmed!");
        return false;
    }

    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    if (!validateArguments(argc, argv)) {
        return message;
    }

    size_t count;
    size_t sort;
    std::vector<std::vector<double>> mat;
        count = parseInt(argv[1]);
        sort = parseInt(argv[2]);
    double* array = new double[count];
    for (size_t i = 0; i < count; i++)
        try {
        array[i] = parseDouble(argv[3 + i]);
    }
    catch (const std::invalid_argument& e) {
        message =
            std::string("Wrong array data format!")
            .append(e.what());
        return message;
    }
    std::ostringstream stream;
    switch (sort) {
    case 1:
        SortInsert(array, count);
        stream << "Sorted array: ";
        for (size_t i = 0; i < count; i++)
            stream << array[i] << " ";
        break;
    case 2:
        SortQuick(array, 0, count-1);
        stream << "Sorted array: ";
        for (size_t i = 0; i < count; i++)
            stream << array[i] << " ";
        break;
    }
    message = stream.str();
    return message;
}
