// Copyright 2023 Kosterin Alexey

#include "include/code_vijener.h"

#include <string>
#include <algorithm>


Code_vijener::Code_vijener() {
    code_str = "";
    key = "";
}
Code_vijener::Code_vijener(const std::string _code_str,
    const std::string _key) {
    code_str = _code_str;
    std::transform(code_str.begin(), code_str.end(),
        code_str.begin(), [](char const& c) {
            return std::toupper(c);
        });
    key = _key;
    std::transform(key.begin(), key.end(), key.begin(),
        [](char const& c) {
        return std::toupper(c);
        });
}



const std::string& Code_vijener::GetCodeStr() {
    return code_str;
}

const std::string& Code_vijener::GetKey() {
    return key;
}

Code_vijener::Code_vijener(const Code_vijener& buf) {
    code_str = buf.code_str;
    key = buf.key;
}

int Code_vijener::KeyCode(char s) {
    for (size_t i = 0; i < alphabet.length(); i++) {
        if (s == alphabet[i]) {
            return i;
        }
    }
    return -1;
}

std::string Code_vijener::Encoder() {
    std::string result;
    for (size_t i = 0; i < code_str.length(); i++) {
        result += alphabet[(KeyCode(code_str[i]) +
            KeyCode(key[i % key.length()])) % alphabet.length()];
    }
    return result;
}

std::string Code_vijener::Decoder() {
    std::string result;
    for (size_t i = 0; i < code_str.length(); i++) {
        result += alphabet[(KeyCode(code_str[i]) -
            KeyCode(key[i % key.length()])
            + alphabet.length()) % alphabet.length()];
    }
    return result;
}


void Code_vijener::SetKey(const std::string _key) {
    key = _key;
    std::transform(key.begin(), key.end(), key.begin(),
        [](char const& c) {
        return std::toupper(c);
        });
}

void Code_vijener::SetCodeStr(const std::string _code_str) {
    code_str = _code_str;
    std::transform(code_str.begin(), code_str.end(),
        code_str.begin(), [](char const& c) {
            return std::toupper(c);
        });
}
