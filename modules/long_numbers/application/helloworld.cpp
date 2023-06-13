// Copyright 2023 Rezchikov Dmitrii

#include "../include/long_num_app.h"


int main(int argc, const char** argv) {
    LongCalculator app;
    std::string output = app(argc, argv);
    std::cout << output;
    return 0;
}
