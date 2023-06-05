// Copyright 2023 Bochkarev Vladimir

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iomanip>

#ifndef MODULES_HUFFMAN_ALGORITHM_INCLUDE_HUFFMANALGORITHM_APPLICATION_H_
#define MODULES_HUFFMAN_ALGORITHM_INCLUDE_HUFFMANALGORITHM_APPLICATION_H_

class Application {
 public:
    std::string operator()(int argc, const char** argv);
    Application();
    std::pair<char, int> parseCode(const char* arg);
 private:
    std::string message;
    int validateNumberOfArguments(int argc, const char** argv);
    void help(const char* app_name);
};

#endif  //  MODULES_HUFFMAN_ALGORITHM_INCLUDE_HUFFMANALGORITHM_APPLICATION_H_
