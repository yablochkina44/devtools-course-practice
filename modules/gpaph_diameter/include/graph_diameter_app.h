// Copyright 2023 Khairetdinov Timur
#ifndef MODULES_GPAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_APP_H_
#define MODULES_GPAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_APP_H_

#include <stdexcept>
#include <string>
#include <vector>

class GraphApplication {
 public:
    GraphApplication();
    std::string operator()(int argc, const char** argv);
 private:
    std::string message;
    typedef struct {
        std::vector<std::vector<int>> matrix;
    } Arguments;

    void info(const char* appname, const char* message = "");
    bool validate(int argc, const char** argv);
};

#endif  // MODULES_GPAPH_DIAMETER_INCLUDE_GRAPH_DIAMETER_APP_H_
