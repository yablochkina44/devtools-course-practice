// Copyright 2023 Yurin Evgeny

#include "../include/encoder_application.h"

int main(int argc, const char **argv) {
    EncoderApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
