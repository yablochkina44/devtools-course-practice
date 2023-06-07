//  Copyright 2023 Gosteeva Ekaterina

#include "include/Function_Eyler_Application.h"
#include <include/Function_Eyler.h>

std::string Application::help() {
    std::string message;
    message.append("This is application for Eyler Function.\n");
    message.append("Please enter a positive number.");
    message.append("The Euler function will be calculated for it");
    return message;
}

std::vector<int> Application::parseFromParam(int argc, const char** argv) {
    std::vector<int> result_args;
    int tmp;

    for (int i = 1; i < argc; i++) {
        tmp = std::atoi(argv[i]);
        result_args[i - 1] = tmp;
    }

    return result_args;
}

std::string Application::calculate(std::vector<int> numbs) {
    std::string results;
    Function_Eyler f;

    try {
        for (size_t i = 0; i < numbs.size(); i++) {
            results.append("The Euler function for ");
            results.append(std::to_string(numbs[i]));
            results.append(" = ");
            results.append(std::to_string(f.Function_Euler(numbs[i])));
            results.append("\n");
        }
    }
    catch (std::exception& exc) {
        std::cerr << exc.what();
    }

    return results;
}

std::string Application::operator()(int argc, const char** argv) {
    if (argc < 2) {
        return help();
    }

    std::vector<int> numbs = parseFromParam(argc, argv);

    return calculate(numbs);
}
