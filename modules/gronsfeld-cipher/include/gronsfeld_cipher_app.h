// Copyright 2023 Ivlev Alexander

#ifndef MODULES_GRONSFELD_CIPHER_INCLUDE_GRONSFELD_CIPHER_APP_H_
#define MODULES_GRONSFELD_CIPHER_INCLUDE_GRONSFELD_CIPHER_APP_H_

#include <stdint.h>
#include <string>
#include <vector>
#include <cinttypes>

class gronsfeld_cipher_app {
 public:
    gronsfeld_cipher_app();
    std::string operator()(int argc, const char** argv);
 private:
    void help(const char* appname, const char* message = "");
    bool checkNumberArguments(int argc, const char** argv);
    bool parse_flag(const char* arg);
    std::string parse_str(const char* arg);
    std::vector<uint8_t> parse_key(const char* arg);
    std::string message_;
};

#endif  //  MODULES_GRONSFELD_CIPHER_INCLUDE_GRONSFELD_CIPHER_APP_H_
