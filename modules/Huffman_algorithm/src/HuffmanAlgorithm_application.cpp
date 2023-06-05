// Copyright 2023 Bochkarev Vladimir

#include "include/HuffmanAlgorithm_application.h"
#include "include/HuffmanAlgorithm.h"

Application::Application() : message("") {}

void Application::help(const char* app_name) {
    message.append("This program provides the ability to \n")
        .append("get the code of the entered text obtained by the")
        .append("Huffman algorithm\n")
        .append("Please provide arguments in the following format :\n")
        .append("  $ ")
        .append(app_name)
        .append("\nIf you want to encode a string then enter this string")
        .append("\nIf you want to decode the encrypted string,\n")
        .append("enter the code and the Huffman tree in the")
        .append("following format : \n")
        .append("<code> <char 1><frequency 1> <char 2><frequency 2>")
        .append(" ... <char n><frequency n>");
}

std::pair<char, int> Application::parseCode(const char* arg) {
    std::string s(arg);
    char c = s[0];
    int f = std::stoi(s.substr(1, s.size()-1));
    std::pair<char, int> p;
    p.first = c; p.second = f;
    return p;
}

int Application::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return 0;
    } else if (argc == 2) {
        return 1;
    } else {
        return argc - 1;
    }
}

std::string Application::operator()(int argc, const char** argv) {
    int val = validateNumberOfArguments(argc, argv);
    if (val == 0) {
        return message;
    } else if (val == 1) {
        HuffmanCode hc;
        return hc.encode(argv[1]);
    } else {
        std::string text;
        std::pair<char, int> p;
        for (int i = 2; i <= val; i++) {
            try {
                p = parseCode(argv[i]);
            }
            catch (std::invalid_argument& e) {
                message = "Invalid argument";
                return message;
            }
            text.append(p.second, p.first);
        }
        HuffmanCode hc;
        hc.encode(text);
        return hc.decode(argv[1], hc.getRoot());
    }
}
