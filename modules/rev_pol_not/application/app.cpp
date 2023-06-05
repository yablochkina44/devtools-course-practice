// Copyright 2023 Lebedinskiy Ilya
#include <iostream>

#include "include/rev_pol_app.h"

int main(int argc, const char* argv[]) {
    Application app;
    auto output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
