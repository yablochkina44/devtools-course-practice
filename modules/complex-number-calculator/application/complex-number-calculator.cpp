// Copyright 2023 Tychinin Alexey

#include "include/complex_calculator_application.h"

int main(int argc, const char** argv) {
    ComplexCalculatorApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
