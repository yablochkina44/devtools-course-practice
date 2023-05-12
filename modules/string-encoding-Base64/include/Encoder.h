// Copyright 2023 Kudryashov Nikita

#ifndef MODULES_STRING_ENCODING_BASE64_INCLUDE_ENCODER_H_
#define MODULES_STRING_ENCODING_BASE64_INCLUDE_ENCODER_H_

#include <string>
#include <iostream>
#include <cmath>

using std::string;

class Base64Encoder {
 public:
    static string strToBase64(string);
    static string base64ToStr(string);
 private:
    static int findIndex(char str[], char c);
    static string reverseString(string str);
    static string intToBin(int num);
    static int binToInt(string num);
};
#endif  // MODULES_STRING_ENCODING_BASE64_INCLUDE_ENCODER_H_
