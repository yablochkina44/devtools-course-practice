// Copyright 2023 Ivlev Alexander

#pragma once

#include <vector>
#include <iostream>
#include <random>

// The function finds the greatest common divisor of two numbers.
int gcd(int a, int b);
// The function finds the product of two numbers (a, b) modulo (M).
unsigned int ModMul(unsigned int a, unsigned int b, unsigned int M);
// The function raises a number (x) to a power (n) modulo (M).
unsigned int ModExp(unsigned int x, unsigned int n, unsigned int M);

// Ferma primality test
bool Ferma_primality_test(unsigned int N);
// Ferma primality test of all the numbers in the interval [a, b].
std::vector<unsigned int> primality_test_interval(unsigned int a,
    unsigned int b);
