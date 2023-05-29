// Copyright 2023 Tychinin Alexey

#include <stdexcept>

#pragma once

class division_by_zero_exception : public std::runtime_error {
 public:
    using std::runtime_error::runtime_error;
};
