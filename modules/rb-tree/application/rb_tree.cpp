// Copyright 2023 Bykova Aleksandra

#include "include/rb_tree_application.h"
#include <iostream>

int main(int argc, const char** argv) {
    RBTreeApp app;

    std::cout << app(argc, argv) << std::endl;

    return 0;
}
