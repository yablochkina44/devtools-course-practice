// Copyright 2023 Mukhin Vadim
#include <iostream>
#include <string>
#include <cmath>

std::string convert(std::string num, int base1, int base2) {
    int decimal = 0;

    if (base1 == 10) {
        decimal = stoi(num);
    } else {
        for (int i = num.length() - 1; i >= 0; i--) {
            int digit;
            if (num[i] >= '0' && num[i] <= '9') digit = num[i] - '0';
            else if (num[i] >= 'A' && num[i] <= 'F') digit = num[i] - 'A' + 10;
            else if (num[i] >= 'a' && num[i] <= 'f') digit = num[i] - 'a' + 10;
            decimal += digit * pow(base1, num.length() - 1 - i);
        }
    }

    std::string result = "";

    while (decimal > 0) {
        int digit = decimal % base2;
        char c;
        if (digit >= 0 && digit <= 9) c = digit + '0';
        else
        c = digit - 10 + 'A';

        result = c + result;
        decimal /= base2;
    }

    return result;
}
