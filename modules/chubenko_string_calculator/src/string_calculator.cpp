// Copyright 2023 CHUBENKO ANDREY

#include "../include/string_calculator.h"

#include <math.h>

#include <iostream>
#include <string>

void CalcStringCalculator::set_Calc_infix(const std::string str) {
    Calc_infix_ = str;
}

std::string CalcStringCalculator::get_Calc_infix() {
    return Calc_infix_;
}

std::string CalcStringCalculator::get_Calc_postfix() {
    return Calc_postfix_;
}

bool CalcStringCalculator::CalcCheck() {
    while (!Calc_charStack_.empty()) {
        Calc_charStack_.pop();
    }
    int sizeOfInfix = static_cast<int>(Calc_infix_.size());
    for (int i = 0; i < sizeOfInfix; i++) {
        switch (Calc_infix_[i]) {
        case '(':
        {
            Calc_charStack_.push(Calc_infix_[i]);
            break;
        }
        case ')':
        {
            if (Calc_charStack_.empty()) {
                return false;
            } else {
                Calc_charStack_.pop();
                break;
            }
        }
        case '+':
        {
            if (i == 0 || i == sizeOfInfix - 1)
                return false;
            if (Calc_infix_[i - 1] == '-' || Calc_infix_[i - 1] == '+')
                return false;
            else if (Calc_infix_[i - 1] == '*' || Calc_infix_[i - 1] == '/')
                return false;
            else if (Calc_infix_[i - 1] == '^')
                return false;
            break;
        }
        case '-':
        {
            if (i == 0 || i == sizeOfInfix - 1)
                return false;
            if (Calc_infix_[i - 1] == '-' || Calc_infix_[i - 1] == '+')
                return false;
            else if (Calc_infix_[i - 1] == '*' || Calc_infix_[i - 1] == '/')
                return false;
            else if (Calc_infix_[i - 1] == '^')
                return false;
            break;
        }
        case '*':
        {
            if (i == 0 || i == sizeOfInfix - 1)
                return false;
            if (Calc_infix_[i - 1] == '-' || Calc_infix_[i - 1] == '+')
                return false;
            else if (Calc_infix_[i - 1] == '*' || Calc_infix_[i - 1] == '/')
                return false;
            else if (Calc_infix_[i - 1] == '^')
                return false;
            break;
        }
        case '/':
        {
            if (i == 0 || i == sizeOfInfix - 1)
                return false;
            if (Calc_infix_[i - 1] == '-' || Calc_infix_[i - 1] == '+')
                return false;
            else if (Calc_infix_[i - 1] == '*' || Calc_infix_[i - 1] == '/')
                return false;
            else if (Calc_infix_[i - 1] == '^')
                return false;
            break;
        }
        case '^':
        {
            if (i == 0 || i == sizeOfInfix - 1)
                return false;
            if (Calc_infix_[i - 1] == '-' || Calc_infix_[i - 1] == '+')
                return false;
            else if (Calc_infix_[i - 1] == '*' || Calc_infix_[i - 1] == '/')
                return false;
            else if (Calc_infix_[i - 1] == '^')
                return false;
            break;
        }
        }
    }
    if (Calc_charStack_.empty()) {
        return true;
    } else {
        return false;
    }
}

int CalcStringCalculator::CalcPriority(const char& el) {
    switch (el) {
    case '(':
    {
        return 0;
    }
    case '+':
    {
        return 1;
    }
    case '-':
    {
        return 1;
    }
    case '*':
    {
        return 2;
    }
    case '/':
    {
        return 2;
    }
    case '^':
    {
        return 3;
    }
    }
    return -1;
}

int CalcStringCalculator::get_Calc_priority(const char& el) {
    return CalcPriority(el);
}

void CalcStringCalculator::CalcToPostfix() {
    if (CalcCheck()) {
        std::string tmp = '(' + Calc_infix_ + ')';
        int sizeOfTmp = static_cast<int>(tmp.size());
        for (int i = 0; i < sizeOfTmp; i++) {
            if (tmp[i] == '(') {
                Calc_charStack_.push(tmp[i]);
            }
            if ((tmp[i] >= '0' && tmp[i] <= '9') || (tmp[i] == '.')) {
                Calc_postfix_ += tmp[i];
            }
            if (tmp[i] == ')') {
                char el = Calc_charStack_.top();
                Calc_charStack_.pop();
                while (el != '(') {
                    Calc_postfix_ += el;
                    el = Calc_charStack_.top();
                    Calc_charStack_.pop();
                }
            }
            if ((tmp[i] == '+') || (tmp[i] == '-') || (tmp[i] == '*') ||
                (tmp[i] == '/') || (tmp[i] == '^')) {
                Calc_postfix_ += " ";
                while (CalcPriority(tmp[i])
                    <= CalcPriority(Calc_charStack_.top())) {
                    Calc_postfix_ += Calc_charStack_.top();
                    Calc_charStack_.pop();
                }
                Calc_charStack_.push(tmp[i]);
            }
        }
    } else {
        throw std::invalid_argument("Incorrect data");
    }
}

double CalcStringCalculator::CalcCalculate() {
    while (!Calc_doubleStack_.empty()) {
        Calc_doubleStack_.pop();
    }
    CalcToPostfix();
    int sizeOfPostfix = static_cast<int>(Calc_postfix_.size());
    for (int i = 0; i < sizeOfPostfix; i++) {
        if (Calc_postfix_[i] == '+' || Calc_postfix_[i] == '-'
                || Calc_postfix_[i] == '*' ||
            Calc_postfix_[i] == '/' || Calc_postfix_[i] == '^') {
            double res, op1, op2 = Calc_doubleStack_.top();
            Calc_doubleStack_.pop();
            if (Calc_doubleStack_.empty()) {
                throw std::invalid_argument("Error - Incorrect Data");
            }
            op1 = Calc_doubleStack_.top();
            Calc_doubleStack_.pop();
            switch (Calc_postfix_[i]) {
            case '+':
            {
                res = op1 + op2;
                break;
            }
            case '-':
            {
                res = op1 - op2;
                break;
            }
            case '*':
            {
                res = op1 * op2;
                break;
            }
            case '/':
            {
                if (op2 == 0) {
                    throw std::invalid_argument("Error - division by zero");
                }
                res = op1 / op2;
                break;
            }
            case '^':
            {
                res = pow(op1, op2);
                break;
            }
            }
            Calc_doubleStack_.push(res);
        }
        if ((Calc_postfix_[i] >= '0' && Calc_postfix_[i] <= '9')
                    || Calc_postfix_[i] == '.') {
            char* tmp;
            double res;
            res = strtod(&Calc_postfix_[i], &tmp);
            int j = tmp - &Calc_postfix_[i];
            i += j - 1;
            Calc_doubleStack_.push(res);
        }
    }
    return Calc_doubleStack_.top();
}

void CalcStringCalculator::set_Calc_stacks(int n) {
    for (int i = 0; i < n; i++) {
        Calc_charStack_.push('+');
        Calc_doubleStack_.push(2.5);
    }
}

void CalcStringCalculator::set_Calc_postfix(const std::string str) {
    Calc_postfix_ = str;
}
