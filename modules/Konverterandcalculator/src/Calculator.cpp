// Copyright 2023 Mukhin Vadim
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <cstdint>
#include <cstddef>
std::string add(std::string num1, int base1, std::string num2, int base2) {
    // Преобразуем числа из их систем счисления в десятичную систему
    int decimal1 = 0, decimal2 = 0;
    for (std::string::size_type i = 0; i < num1.length(); i++) {
        int digit = 0;
        if (num1[i] >= '0' && num1[i] <= '9') {
            digit = num1[i] - '0';
        } else if (num1[i] >= 'A' && num1[i] <= 'F') {
            digit = num1[i] - 'A' + 10;
        } else if (num1[i] >= 'a' && num1[i] <= 'f') {
            digit = num1[i] - 'a' + 10;
        }
        decimal1 += digit * pow(base1, num1.length() - 1 - i);
    }
    for (std::string::size_type i = 0; i < num2.length(); i++) {
        int digit = 0;
        if (num2[i] >= '0' && num2[i] <= '9') {
            digit = num2[i] - '0';
        } else if (num2[i] >= 'A' && num2[i] <= 'F') {
            digit = num2[i] - 'A' + 10;
        } else if (num2[i] >= 'a' && num2[i] <= 'f') {
            digit = num2[i] - 'a' + 10;
        }
        decimal2 += digit * pow(base2, num2.length() - 1 - i);
    }

    // Складываем числа в десятичной системе счисления
    int sumDecimal = decimal1 + decimal2;
    int base = std::max(base1, base2);
    std::string sum = "";
    while (sumDecimal > 0) {
        int digit = sumDecimal % base;
        char c = digit < 10 ? digit + '0' : digit - 10 + 'A';
        sum = c + sum;
        sumDecimal /= base;
    }

    // Если результат сложения пустой, то возвращаем "0"
    if (sum.empty()) {
        return "0";
    }

    return sum;
}

std::string subtract(std::string num1, int base1, std::string num2, int base2) {
    int decimal1 = 0, decimal2 = 0;

    for (int i = num1.length() - 1; i >= 0; i--) {
        int digit;
        if (num1[i] >= '0' && num1[i] <= '9') {
            digit = num1[i] - '0';
        } else if (num1[i] >= 'A' && num1[i] <= 'F') {
            digit = num1[i] - 'A' + 10;
        } else if (num1[i] >= 'a' && num1[i] <= 'f') {
            digit = num1[i] - 'a' + 10;
        }
        decimal1 += digit * pow(base1, num1.length() - 1 - i);
    }

    for (int i = num2.length() - 1; i >= 0; i--) {
        int digit;
        if (num2[i] >= '0' && num2[i] <= '9') {
            digit = num2[i] - '0';
        } else if (num2[i] >= 'A' && num2[i] <= 'F') {
            digit = num2[i] - 'A' + 10;
        } else if (num2[i] >= 'a' && num2[i] <= 'f') {
            digit = num2[i] - 'a' + 10;
        }
        decimal2 += digit * pow(base2, num2.length() - 1 - i);
    }

    int diffDecimal = decimal1 - decimal2;

    if (diffDecimal < 0) {
        return "-" + subtract(num2, base2, num1, base1);
    }

    std::string diff = "";

    while (diffDecimal > 0) {
        int digit = diffDecimal % base1;
        char c;
        if (digit >= 0 && digit <= 9) {
            c = digit + '0';
        } else {
            c = digit - 10 + 'A';
        }

        diff = c + diff;
        diffDecimal /= base1;
    }

    if (diff.empty()) {
        return "0";
    }

    return diff;
}

std::string multiply(std::string num1, int base1, std::string num2, int base2) {
    std::vector<int64_t> product(num1.length() + num2.length(), 0);

    for (int i = num1.length() - 1; i >= 0; i--) {
        int64_t carry = 0;
        int64_t digit1;
        if (num1[i] >= '0' && num1[i] <= '9') {
            digit1 = num1[i] - '0';
        } else {
            digit1 = num1[i] - 'A' + 10;
        }

        for (int j = num2.length() - 1; j >= 0; j--) {
            int64_t digit2;
            if (num2[j] >= '0' && num2[j] <= '9') {
                digit2 = num2[j] - '0';
            } else {
                digit2 = num2[j] - 'A' + 10;
            }
            int64_t productDigit = digit1 * digit2 + carry + product[i + j + 1];
            carry = productDigit / base1;
            product[i + j + 1] = productDigit % base1;
        }

        product[i] += carry;
    }

    int i = 0;
    while (i < static_cast<int>(product.size()) && product[i] == 0) {
        i++;
    }

    if (i == static_cast<int>(product.size())) {
        return "0";
    }

    std::string result = "";
    while (i < static_cast<int>(product.size())) {
        char c;
        if (product[i] >= 0 && product[i] <= 9) {
            c = product[i] + '0';
        } else {
            c = product[i] - 10 + 'A';
        }
        result += c;
        i++;
    }

    return result;
}

std::string divide(std::string num1, int base1, std::string num2, int base2) {
    int sign = 1;
    if (num1[0] == '-') {
        sign *= -1;
        num1 = num1.substr(1);
    }
    if (num2[0] == '-') {
        sign *= -1;
        num2 = num2.substr(1);
    }

    int decimal1 = 0, decimal2 = 0;

    for (size_t i = 0; i < num1.length(); i++) {
        int digit;
        if (num1[i] >= '0' && num1[i] <= '9') {
            digit = num1[i] - '0';
        } else if (num1[i] >= 'A' && num1[i] <= 'F') {
            digit = num1[i] - 'A' + 10;
        } else if (num1[i] >= 'a' && num1[i] <= 'f') {
            digit = num1[i] - 'a' + 10;
        }
        decimal1 = decimal1 * base1 + digit;
    }

    for (size_t i = 0; i < num2.length(); i++) {
        int digit;
        if (num2[i] >= '0' && num2[i] <= '9') {
            digit = num2[i] - '0';
        } else if (num2[i] >= 'A' && num2[i] <= 'F') {
            digit = num2[i] - 'A' + 10;
        } else if (num2[i] >= 'a' && num2[i] <= 'f') {
            digit = num2[i] - 'a' + 10;
        }
        decimal2 = decimal2 * base2 + digit;
    }

    int quotientDecimal = decimal1 / decimal2;

    std::string quotient = "";
    if (quotientDecimal == 0) {
        quotient = "0";
    } else {
        while (quotientDecimal > 0) {
            int digit = quotientDecimal % base1;
            char c;
            if (digit >= 0 && digit <= 9) {
                c = digit + '0';
            } else {
                c = digit - 10 + 'A';
            }
            quotient = c + quotient;
            quotientDecimal /= base1;
        }
    }

    if (sign == -1) {
        quotient = "-" + quotient;
    }

    return quotient;
}
