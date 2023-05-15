// Copyright 2023 Bulgakov Daniil

#pragma once

#include <string>

/**
 * @brief Application class for dijkstra algorithm.
 * @author Daniil Bulgakov
 */
class DijkstraApplication {
 public:
    DijkstraApplication() = default;

    /**
     * @brief Functor override
     *
     * @param argc Number of command line arguments
     * @param argv Command line arguments
     * @return Output expression
     */
    std::string operator()(int argc, const char** argv);

 private:
    /**
     * @brief Set resp_message field to default help message
     *
     * @param appname Application name
     */
    void help(const char* appname);

    /**
     * @brief Validate command line arguments
     *
     * @param argc Number of command line arguments
     * @param argv Command line arguments
     * @return true Validation success
     * @return false Validation error
     */
    bool validateArguments(int argc, const char** argv);

    /**
     * @brief Response message string
     */
    std::string resp_message;
};
