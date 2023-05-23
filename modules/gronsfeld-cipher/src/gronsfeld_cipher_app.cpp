// Copyright 2023 Ivlev Alexander

#include "include/gronsfeld_cipher.hpp"
#include "include/gronsfeld_cipher_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <cinttypes>
#include <stdexcept>

gronsfeld_cipher_app::gronsfeld_cipher_app() : message_("") {}

void gronsfeld_cipher_app::help(const char* appname, const char* message) {
    message_ = std::string(message) +
          "This is a gronsfeld cipher application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <flag> <key> <to_code>\n\n" +

          "Where <flag> 0 if code or 1 if decode, " +
          "<key> string of numbers (from 0 to 26) separated by underscores, " +
          "<to_code> string of letters for code(decode).\n";
}

bool gronsfeld_cipher_app::checkNumberArguments(int argc, const char** argv) {
    if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

bool gronsfeld_cipher_app::parse_flag(const char* arg) {
    bool flag = false;
    try {
        flag = static_cast<bool>(std::stoi(arg));
    }
    catch (std::invalid_argument const& ex) {
        throw std::string("Flag not a number! ") + std::string(ex.what());
    }
    return flag;
}

std::vector<uint8_t> gronsfeld_cipher_app::parse_key(const char* arg) {
    std::vector<uint8_t> key;
    std::string str_arg(arg);
    std::string temp_str;
    int num;

    for (size_t i = 0; i < str_arg.size(); i++) {
        if (str_arg[i] == '_' || i == str_arg.size() - 1) {
            if (i == str_arg.size() - 1) {
                temp_str.push_back(str_arg[i]);
            }

            try {
                num = std::stoi(temp_str);
            }
            catch (std::invalid_argument const& ex) {
                throw std::string("Not a number! ") + std::string(ex.what());
            }

            if (num > 'z' - 'a' + 1 || num < 0) {
                throw std::string("Wrong number!");
            } else {
                key.push_back(num);
            }

            temp_str.clear();
        } else {
            temp_str.push_back(str_arg[i]);
        }
    }

    return key;
}

std::string gronsfeld_cipher_app::parse_str(const char* arg) {
    std::string to_code = arg;
    for (size_t i = 0; i < to_code.size(); i++) {
        char letter = to_code[i] - 'a';
        if (letter < 0 || letter > 'z' - 'a' + 1) {
            throw std::string("Wrong string!");
        }
    }
    return to_code;
}

std::string gronsfeld_cipher_app::operator()(int argc, const char** argv) {
    bool flag;
    std::vector<uint8_t> key;
    std::string to_code;

    if (!checkNumberArguments(argc, argv)) {
        return message_;
    }
    try {
        flag = parse_flag(argv[1]);
        key = parse_key(argv[2]);
        to_code = parse_str(argv[3]);
    }
    catch(std::string& str) {
        return str;
    }

    std::string result;

    gronsfeld_cipher_t g_c(key);
    if (flag) {
        result = g_c.decode(to_code);
    } else {
        result = g_c.code(to_code);
    }

    message_ = result;

    return message_;
}
