// Copyright 2023 Shuin Evgeniy

#include <iostream>
#include "include/MinimumSpanningTreeApp.h"

int main(int argc, char** argv) {
    MinimumSpanningTreeApp app;
    std::string result = app.processCommand(argc, argv);
    printf("%s\n", result.c_str());
    return 0;
}
