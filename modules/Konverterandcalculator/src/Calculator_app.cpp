// Copyright 2023 Lapin Dmitriy

#include <stdlib.h>

#include <string>
#include <cstring>
#include <sstream>

#include "include/Calculator_app.h"
#include "include/Calculator.h"
#include "include/Converter.h"

BaseCalculator::BaseCalculator() : message_("") {}

void BaseCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a number with different bases calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <num1> <base1> " +
          "<num2> <base2> <operation>\n\n" +

          "Where first and third arguments are integer "+
        "numbers and second and fourth arguments are bases " +
          "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool BaseCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 6) {
        help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

double parseInt(const char* arg) {
    char* end;
    int value = static_cast<int>(strtol(arg, &end, 10));

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string BaseCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.num1      = argv[1];
        args.base1 = parseInt(argv[2]);
        args.num2      = argv[3];
        args.base2 = parseInt(argv[4]);
        args.operation    = parseOperation(argv[5]);
    }
    catch(std::string& str) {
        return str;
    }


    std::string z;
    std::ostringstream stream;
    switch (args.operation) {
     case '+':
        z = add(args.num1, args.base1, args.num2, args.base2);
        stream << "Result = " << z;
        break;
     case '-':
        z = subtract(args.num1, args.base1, args.num2, args.base2);
        stream << "Result = " << z;
        break;
     case '*':
        z = multiply(args.num1, args.base1, args.num2, args.base2);
        stream << "Result = " << z;
        break;
     case '/':
         try {
             std::string n2 = convert(args.num2, args.base2, 10);

             if (n2 == "") {
                 throw std::string("We cannot divide by zero!");
             }
             z = divide(args.num1, args.base1, args.num2, args.base2);
             stream << "Result = " << z;
         }
         catch (std::string& str) {
             return str;
         }
    }

    message_ = stream.str();

    return message_;
}



