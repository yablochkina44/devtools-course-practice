// Copyright 2023 Mitin Roman
#ifndef MODULES_GRONSFELD_CIPHER_INCLUDE_GRONSFELD_CIPHER_HPP_
#define MODULES_GRONSFELD_CIPHER_INCLUDE_GRONSFELD_CIPHER_HPP_

#include <vector>
#include <string>
#include <cinttypes>

class gronsfeld_cipher_t {
    constexpr static uint8_t alphabet_size = 'z' - 'a' + 1;

    std::vector<uint8_t> key;

    std::string code_impl(const std::string& to_code, bool is_code);

 public:
    explicit gronsfeld_cipher_t(const std::vector<uint8_t>& new_key);
    std::string code(const std::string& to_code);
    std::string decode(const std::string& to_decode);
};

#endif  //  MODULES_GRONSFELD_CIPHER_INCLUDE_GRONSFELD_CIPHER_HPP_
