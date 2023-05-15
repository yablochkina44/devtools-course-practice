// Copyright 2023 Bulgakov Daniil

#include <string>
#include <sstream>
#include <vector>

#include "include/dijkstra_application.h"
#include "include/Dijkstra.h"

int parseInt(const char* arg) {
    int value = 0;
    std::stringstream s(arg);
    s >> value;
    if (s.fail()) {
        throw std::invalid_argument("Expected integer value.");
    }

    return value;
}

size_t parseUInt(const char* arg) {
    int value = 0;
    std::stringstream s(arg);
    s >> value;
    if (s.fail() || value < 0) {
        throw std::invalid_argument("Expected unsigned integer value.");
    }

    return static_cast<size_t>(value);
}

double parseDouble(const char* arg) {
    double value = 0;
    std::stringstream s(arg);
    s >> value;
    if (s.fail()) {
        throw std::invalid_argument("Expected double value.");
    }

    return value;
}

void DijkstraApplication::help(const char *appname) {
    std::string sb;
    sb
    .append("This program is designed to find the shortest ")
    .append("distance in graphs from one of the vertices ")
    .append("to all the others or to some specific vertex \n")
    .append("Please provide arguments in the following format:\n\n")
    .append("  $ ")
    .append(appname)
    .append(" <start vert> <find vert> <matrix size> <adjacency matrix> \n\n")
    .append("Where <start vert> is an unsigned integer of a starting vertex\n")
    .append("<find vert> is an unsigned integer of vertex to find ")
    .append(" or negative if all distances should be found\n")
    .append("<vert amount> is an unsigned integer number of vertices\n")
    .append("<adjacency matrix> is a sequence of unsigned integers \n");

    resp_message = std::move(sb);
}

bool DijkstraApplication::validateArguments(int argc, const char **argv) {
    std::string helper_str =
            std::string(" Type `$ ").append(argv[0])
                .append("` to see help message");

    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 4) {
        resp_message =
                std::string("ERROR: Input parameters amount mismatch.");

        return false;
    }

    // Check if input matrix contains fewer digits than it should
    size_t vert_num;

    try {
        vert_num = parseUInt(argv[3]);
    } catch (const std::invalid_argument& e) {
        resp_message =
                std::string("ERROR: Cant parse <matrix size>. ")
                    .append(e.what());
        return false;
    }

    if (argc == 4) {
        resp_message =
                std::string("ERROR: Adjacency matrix is empty");
        return false;
    }

    if (static_cast<size_t>(argc) < (4 + vert_num * vert_num)) {
        resp_message =
                std::string("ERROR: Adjacency matrix "
                    "is not completely filled");
        return false;
    }

    return true;
}

std::string DijkstraApplication::operator()(int argc, const char **argv) {
    if (!validateArguments(argc, argv)) {
        return resp_message;
    }

    size_t vert_num, start;
    int end;
    std::vector<std::vector<double>> mat;

    try {
        start = parseUInt(argv[1]);
    } catch (const std::invalid_argument& e) {
        resp_message =
                std::string("ERROR: Cant parse <start vert>. ")
                    .append(e.what());
        return resp_message;
    }

    try {
        end = parseInt(argv[2]);
    } catch (const std::invalid_argument& e) {
        resp_message =
                std::string("ERROR: Cant parse <end vert>. ")
                    .append(e.what());
        return resp_message;
    }

    vert_num = parseUInt(argv[3]);

    for (size_t i = 0; i < vert_num; i++) {
        std::vector<double> row;
        for (size_t j = 0; j < vert_num; j++) {
            double value;
            try {
                value = parseDouble(argv[4 + (i * vert_num) + j]);
            } catch (const std::invalid_argument& e) {
                resp_message =
                        std::string("ERROR: Cant parse matrix at index ")
                            .append("[")
                            .append(std::to_string((i * vert_num) + j))
                            .append("]. ")
                            .append(e.what());
                return resp_message;
            }
            row.push_back(value);
        }
        mat.push_back(row);
    }

    Dijkstra d = Dijkstra();
    d.setNewTask(mat, static_cast<int>(start));
    d.Solve();

    if (end >= 0) {
        std::string val;
        if (d.getAnswer(end) < 0) val = "NaN";
        else
            val = std::to_string(d.getAnswer(end));
        return std::string("The shortest distance from ")
            .append(std::to_string(start))
            .append(" to ")
            .append(std::to_string(end))
            .append(" is equals to : ")
            .append(val);
    } else {
        std::vector<double> result = d.getAnswer();
        std::string sb;
        sb.append("The shortest distance from ")
        .append(std::to_string(start))
        .append(" to other vertices \n");
        for (size_t i = 0; i < vert_num; i++) {
            double res = result[i];
            if (res < 0) sb.append("NaN").append(" ");
            else
                sb.append(std::to_string(result[i])).append(" ");
        }
        return sb;
    }

    return std::string();
}
