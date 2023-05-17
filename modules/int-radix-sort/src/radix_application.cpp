// Copyright 2023 Mikerin Ilya

#include <sstream>
#include "include/radix_application.h"
#include "include/int_radix_sort.h"

radix_application::radix_application() {}

double parseInt(const char* arg) {
    int value;

    if (std::string(arg).find_first_not_of("0123456789-+")
        == std::string::npos) {
        value = std::atoi(arg);
    } else {
        throw std::string("Wrong number format!");
    }
    return value;
}

std::string radix_application::operator()(int argc, const char **argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.size = argc - 1;
        args.vec = std::vector<int>();
        for (int i =0; static_cast<size_t>(i)< args.size; i++) {
            args.vec.push_back(parseInt(argv[1 + i]));
        }
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;
    std::vector<int> result;
    result = IntRadixSort().get_sorted(args.vec);
    stream<< "{ ";
    for (int i=0; static_cast<size_t>(i)< result.size() - 1; i++) {
        stream << result.at(i) << ", ";
    }

    stream << result.at(result.size()-1) << "}\n";

    message_ = stream.str();

    return message_;
}

void radix_application::help(const char *appname, const char *message) {
    message_ =
            std::string(message) +
            "This is a radix sort application.\n\n" +
            "Please provide arguments in the following format:\n\n"+

            "  $ " + appname + "  <1 elsement> " +
            "<2 elsement> <... elsement>\n\n" +

            "Where all arguments are int-precision numbers.\n";
}

bool radix_application::validateNumberOfArguments(int argc, const char **argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    }
    return true;
}

