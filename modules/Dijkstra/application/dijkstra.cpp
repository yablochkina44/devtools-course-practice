// Copyright 2023 Bulgakov Daniil

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/dijkstra_application.h"

int main(int argc, const char** argv) {
    DijkstraApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
