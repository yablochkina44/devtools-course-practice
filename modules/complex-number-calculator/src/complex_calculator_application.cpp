// Copyright 2023 Tychinin Alexey

#include <cassert>
#include <stdexcept>

#include "include/complex_calculator_application.h"
#include "include/complex_calculator.h"
#include "include/division_by_zero_exception.h"

using std::string;
using std::to_string;

string ComplexCalculatorApplication::help() {
    return (string)"This is a complex number calculator application.\n\n" +
           "Please provide arguments in the following format:\n\n" +

           "$ ./complex-number-calculator <z1_real> <z1_imaginary> "
           "<z2_real> <z2_imaginary> <operation>\n\n"

           "Where all arguments are double-precision numbers, "
           "and <operation> is one of '+', '-', '*', '/'.\n";
}

std::string ComplexCalculatorApplication::operator()(int argc,
                                                     const char** argv) {
    if (!validateArguments(argc, argv)) {
        return message_ + "\n" + help();
    }

    evaluate(argc, argv);
    return message_;
}

bool ComplexCalculatorApplication::validateArguments(int argc,
                                                     const char** argv) {
    assert(argv && *argv);
    if (!validateNumberOfArgs(argc)) {
        generateFaultyMessOnInvalidNumberOfArgs(argc);
        return false;
    }

    return true;
}

bool ComplexCalculatorApplication::validateNumberOfArgs(int argc) {
    return argc == expected_argc;
}

void ComplexCalculatorApplication::
generateFaultyMessOnInvalidNumberOfArgs(int actual_argc) {
    message_ = string("Error: got ") +
               to_string(actual_argc) +
               " arguments but expected " +
               to_string(ComplexCalculatorApplication::expected_argc);
}

bool ComplexCalculatorApplication::parseArguments(int argc,
                                                  const char** argv,
                                                  Arguments* args) {
    assert(argv && *argv);
    assert(args);
    message_.clear();

    if (!parseDouble(argv[1], &args->z1_real)) {
        message_ += " (z1_real)\n";
    }
    if (!parseDouble(argv[2], &args->z1_imaginary)) {
        message_ += " (z1_imaginary)\n";
    }
    if (!parseDouble(argv[3], &args->z2_real)) {
        message_ += " (z2_real)\n";
    }
    if (!parseDouble(argv[4], &args->z2_imaginary)) {
        message_ += " (z2_imaginary)\n";
    }
    if (!parseOP(argv[5], &args->operation)) {
        message_ += " (operation)\n";
    }

    if (!message_.empty()) {
        return false;
    }

    return true;
}

bool ComplexCalculatorApplication::parseDouble(const char* str, double* val) {
    assert(str);
    assert(val);
    try {
        *val = std::stod(str);
    } catch(std::invalid_argument& ex) {
        message_ += (string)"Error: unable to parse " + str +
                " into double value";
        return false;
    }
    return true;
}

bool ComplexCalculatorApplication::parseOP(const char* str, OpType* val) {
    assert(str);
    assert(val);
    if (str[0] == '+') {
        *val = OpType::add;
    } else if (str[0] == '-') {
        *val = OpType::sub;
    } else if (str[0] == '*') {
        *val = OpType::mul;
    } else if (str[0] == '/') {
        *val = OpType::div;
    } else {
        message_ += (string)"Error: unknown operation: " + str[0];
        return false;
    }
    return true;
}

void ComplexCalculatorApplication::evaluate(int argc, const char** argv) {
    assert(argv && *argv);
    Arguments args{};
    if (!parseArguments(argc, argv, &args)) {
        return;
    }
    ComplexNumber z1{args.z1_real, args.z1_imaginary};
    ComplexNumber z2{args.z2_real, args.z2_imaginary};
    ComplexNumber res;
    switch (args.operation) {
        case OpType::add:
            res = z1 + z2;
            break;
        case OpType::sub:
            res = z1 - z2;
            break;
        case OpType::mul:
            res = z1 * z2;
            break;
        case OpType::div:
            try {
                res = z1 / z2;
                break;
            } catch (division_by_zero_exception& ex) {
                message_ = (string)"Error: got exception with message: "
                           + ex.what();
                return;
            }
    }
    message_ = "Result: { Real = " +
               to_string(res.getRe()) +
               "; Imaginary = " + to_string(res.getIm()) + " }";
}
