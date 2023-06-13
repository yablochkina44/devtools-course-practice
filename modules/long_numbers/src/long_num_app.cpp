// Copyright 2023 Rezchikov Dmitrii

#include "../include/long_num_app.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

LongCalculator::LongCalculator() : message_("") {}

/// @brief prints helpfull messages to console
/// @param appname name of the app
/// @param message message to write to the console
void LongCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a long number calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <number1>" +
          "<number2> <operation>\n\n" +

          "Where all arguments are integer numbers, " +
          "and <operation> is one of '+', '-'\n";
}

/// @brief validates number of arguments, 3 for this particular case
/// @param argc number of cmd arguments recieved
/// @param argv arguments themselves
/// @return
bool LongCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}


/// @brief get the operation, which is the 3-rd cmd argument
/// @param arg argument to parse as argument
/// @return
char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

/// @brief main functor
/// @param argc
/// @param argv
/// @return
std::string LongCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
    args.n1 = LongNumber(argv[1]);
    args.n2 = LongNumber(argv[2]);
    args.operation = parseOperation(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    LongNumber n1(args.n1);
    LongNumber n2(args.n2);
    LongNumber n3;
    std::ostringstream stream;

    switch (args.operation) {
     case '+':
        n3 = n1 + n2;
        stream << "Result = " << n3 << "\n";
        break;
     case '-':
        n3 = n1 - n2;
        stream << "Result = " << n3 << "\n";
        break;
    }
    message_ = stream.str();
    return message_;
}
