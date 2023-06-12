// Copyright Simeunovic Aleksandar 2023

#pragma once

#include"include/Comb_gen.h"
#include<string>
#include<vector>

class CombGenApp {
 public:
    CombGenApp();
    std::string operator()(int argc, const char** argv);

 private:
    std::string message;
    std::string help(std::string add_message = "");
    bool parseInput(int argc, const char** argv,
    int* n, int* k, std::vector<int>* VecIn);
};
