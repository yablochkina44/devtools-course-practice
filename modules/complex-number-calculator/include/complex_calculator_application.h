// Copyright 2023 Tychinin Alexey

#ifndef MODULES_COMPLEX_NUMBER_CALCULATOR_INCLUDE_COMPLEX_CALCULATOR_APPLICATION_H_
#define MODULES_COMPLEX_NUMBER_CALCULATOR_INCLUDE_COMPLEX_CALCULATOR_APPLICATION_H_

#include <string>

class ComplexCalculatorApplication {
 public:
    ComplexCalculatorApplication() = default;

    std::string operator()(int argc, const char** argv);

    static constexpr int expected_argc = 6;  // including executable's filename

    enum class OpType {
        add,
        sub,
        mul,
        div
    };

 private:
    static std::string help();

    static bool validateNumberOfArgs(int argc);

    bool validateArguments(int argc, const char** argv);

    void generateFaultyMessOnInvalidNumberOfArgs(int actual_argc);

    struct Arguments {
        double z1_real;
        double z1_imaginary;
        double z2_real;
        double z2_imaginary;
        OpType operation;
    };

    bool parseArguments(int argc, const char** argv, Arguments*);

    bool parseDouble(const char* str, double* val);

    bool parseOP(const char* str, OpType* val);

    void evaluate(int argc, const char** argv);

 private:
    std::string message_;
};


#endif  // MODULES_COMPLEX_NUMBER_CALCULATOR_INCLUDE_COMPLEX_CALCULATOR_APPLICATION_H_
