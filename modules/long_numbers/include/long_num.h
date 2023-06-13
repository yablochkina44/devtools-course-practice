// Copyright 2023 Rezchikov Dmitrii

#ifndef MODULES_LONG_NUMBERS_INCLUDE_LONG_NUM_H_
#define MODULES_LONG_NUMBERS_INCLUDE_LONG_NUM_H_

#include <stdlib.h>
#include <string>
#include <iostream>
#include <algorithm>


class LongNumber{
 private:
    std::string number;
    bool positive = true;
    std::string getStr() const;

 public:
    /// @brief string constructor
    /// @param src String representing a number
    LongNumber(const LongNumber & src);
    /// @brief default constructor
    LongNumber();
    /// @brief copy constructor
    /// @param src
    explicit LongNumber(std::string src);
    /// @brief unary minus operator
    /// @return number with opposite sign
    LongNumber operator-() const;
    /// @brief less by absoulute value
    /// @param rhs value to compare with
    /// @return true = less, false = not less
    bool absLess(const LongNumber & rhs) const;
    /// @brief operator<
    /// @param rhs
    /// @return
    bool operator<(const LongNumber & rhs) const;
    /// @brief operator+ for long numbers
    /// @param rhs
    /// @return
    LongNumber operator+(const LongNumber & rhs) const;
    /// @brief
    /// @param rhs
    /// @return
    LongNumber operator+=(const LongNumber & rhs);
    /// @brief
    /// @param rhs
    /// @return
    LongNumber operator-(const LongNumber & rhs) const;
    /// @brief binary minus
    /// @param rhs
    /// @return
    LongNumber operator-=(const LongNumber & rhs);
    /// @brief multiplication (plsplspls)
    /// @param rhs
    /// @return
    LongNumber operator*(const LongNumber & rhs) const;
    // LongNumber operator*=(const LongNumber & rhs);
    /// @brief division (plsplspls)
    /// @param rhs
    /// @return
    LongNumber operator/(const LongNumber & rhs) const;
    // LongNumber operator/=(const LongNumber & rhs);
    /// @brief classic equals
    /// @param rhs
    /// @return
    bool operator==(const LongNumber & rhs) const;
    /// @brief classic not equals
    /// @param rhs
    /// @return
    bool operator!=(const LongNumber & rhs) const;
    /// @brief stream write
    /// @param os output stream
    /// @param n object to write to stream
    /// @return modified stream
    friend std::ostream& operator<<(std::ostream & os, const LongNumber & n);
    /// @brief make a number of opposite sign
    void changeSign();
};

#endif  // MODULES_LONG_NUMBERS_INCLUDE_LONG_NUM_H_
