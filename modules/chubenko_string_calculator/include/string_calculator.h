// Copyright 2023 CHUBENKO ANDREY

#ifndef MODULES_CHUBENKO_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_
#define MODULES_CHUBENKO_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_

#include <stack>
#include <string>

class CalcStringCalculator {
 private:
    std::string Calc_infix_, Calc_postfix_;
    std::stack<char> Calc_charStack_;
    std::stack<double> Calc_doubleStack_;

    bool CalcCheck();
    int CalcPriority(const char& el);
    void CalcToPostfix();

 public:
    void set_Calc_infix(const std::string str);
    void set_Calc_postfix(const std::string str);
    void set_Calc_stacks(int n);
    std::string get_Calc_infix();
    std::string get_Calc_postfix();
    int get_Calc_priority(const char& el);
    double CalcCalculate();
};

#endif  // MODULES_CHUBENKO_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_
