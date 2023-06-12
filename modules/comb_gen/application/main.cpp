// Copyright Simeunovic Aleksandar 2023

#include<iostream>
#include<string>
#include<exception>
#include"include/Comb_gen_app.h"

int main(int argc, const char** argv) {
    CombGenApp app;
    std::string out = app(argc, argv);
    std::cout << out << std::endl;
    return 0;
}
