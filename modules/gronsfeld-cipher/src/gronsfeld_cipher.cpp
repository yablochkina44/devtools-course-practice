// Copyright 2023 Mitin Roman
#include "include/gronsfeld_cipher.hpp"
#include <cassert>
#include <exception>

gronsfeld_cipher_t::gronsfeld_cipher_t(const std::vector<uint8_t> &new_key)
    : key(new_key) {
    for (size_t i = 0; i < key.size(); i++)
        if (key[i] > alphabet_size)
            throw std::exception{};
}

std::string gronsfeld_cipher_t::code_impl(const std::string& to_code,
    bool is_code) {
    size_t ksize = key.size();
    std::string res;
    res.resize(to_code.size());
    int sign = is_code ? 1 : -1;

    for (size_t i = 0; i < to_code.size(); i++) {
        char letter = to_code[i] - 'a';
        letter = (letter + sign * key[i % ksize]) % alphabet_size;
        if (letter < 0)
            letter += alphabet_size;
        assert(letter >= 0 && letter < alphabet_size);
        res[i] = letter + 'a';
    }

    return res;
}

std::string gronsfeld_cipher_t::code(const std::string& to_code) {
    return code_impl(to_code, true);
}

std::string gronsfeld_cipher_t::decode(const std::string& to_decode) {
    return code_impl(to_decode, false);
}
