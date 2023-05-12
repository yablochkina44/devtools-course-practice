// Copyright 2023 Kudryashov Nikita
#include "include/Encoder.h"


string Base64Encoder::strToBase64(string str) {
    string binaryString, res;
    char symbols[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int equalsCount = 0;

    for (char c : str) {
        string binChar = intToBin(static_cast<int>(c));
        while (binChar.length() < 8) {
            binChar = "0" + binChar;
        }
        binaryString += binChar;
    }

    while (binaryString.length() % 6 != 0) {
        binaryString += "00000000";
        equalsCount++;
    }

    int index = 0;
    int blockNum = binaryString.length() / 6;
    while (index != blockNum - equalsCount) {
        string subStr = binaryString.substr(index * 6, 6);
        int newChar = binToInt(subStr);

        res += symbols[newChar];
        index++;
    }
    for (int i = 0; i < equalsCount; i++) {
        res += "=";
    }

    return res;
}

string Base64Encoder::base64ToStr(string str) {
    string binaryString, res;
    char symbols[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int equalsCount = 0;

    for (char c : str) {
        if (c != '=') {
            int index = findIndex(symbols, c);
            string binChar = intToBin(static_cast<int>(index));

            while (binChar.length() < 6) {
                binChar = "0" + binChar;
            }
            binaryString += binChar;
        } else {
            equalsCount++;
            binaryString += "000000";
        }
    }

    binaryString = binaryString.substr(0, binaryString.length()
        - equalsCount * 8);
    int index = 0;
    int blockNum = binaryString.length() / 8;
    while (index != blockNum) {
        string subStr = binaryString.substr(index * 8, 8);
        int newChar = binToInt(subStr);
        res += static_cast<char>(newChar);
        index++;
    }

    return res;
}

int Base64Encoder::findIndex(char str[], char c) {
    int res = -1;
    for (int i = 0; i < 64; i++) {
        if (c == str[i]) {
            res = i;
            break;
        }
    }
    return res;
}

string Base64Encoder::reverseString(std::string str) {
    std::string res;
    for (char c : str) {
        res = c + res;
    }
    return res;
}

string Base64Encoder::intToBin(int num) {
    string res;
    while (num > 0) {
        int ost = num % 2;
        res += std::to_string(ost);
        num /= 2;
    }

    return reverseString(res);
}

int Base64Encoder::binToInt(string num) {
    int res = 0;
    num = reverseString(num);
    for (int i = 0; i < static_cast<int>(num.length()); i++) {
        if (num[i] == '1') {
            res += pow(2, i);
        }
    }
    return res;
}
