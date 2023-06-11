// Copyright 2023 Shuin Evgeniy

#include "include/MinimumSpanningTreeApp.h"
#include <sstream>
#include <vector>


MinimumSpanningTreeApp::MinimumSpanningTreeApp() {}

std::string MinimumSpanningTreeApp::processCommand(int argc, char** argv) {
    if (argc < 2) {
        return getHelpMessage();
    }

    int command = std::stoi(argv[1]);

    switch (command) {
        case 1:
            return getHelpMessage();;
        case 2:
            return processMinimumSpanningTree(argc, argv);
        case 3:
            return processMinimumSpanningTreeWeight(argc, argv);
        default:
            std::stringstream ss;
            ss << "Invalid Command\n"
               << getHelpMessage();
            return ss.str();
    }
}

std::string MinimumSpanningTreeApp::getHelpMessage() {
    std::stringstream ss;
    ss << "Usage: <command> <number of vertices> <edges>\n"
       << "Commands:\n"
       << "  1 - Help Message\n"
       << "  2 - Minimum Spanning Tree\n"
       << "  3 - Minimum Spanning Tree Weight\n\n"
       << "Input example:\n"
       << "./KruskalMST 2 5 0 1 4 0 2 2 1 2 3 2 3 1 3 4 5\n";
    return ss.str();
}

std::string MinimumSpanningTreeApp::
processMinimumSpanningTree(int argc, char** argv) {
    int V = std::stoi(argv[2]);

    std::vector<int> edges;
    for (int i = 3; i < argc; ++i) {
        edges.push_back(std::stoi(argv[i]));
    }

    if (edges.size() % 3 != 0) {
        std::stringstream ss;
        ss << "Invalid number of arguments "
           << "for minimum spanning tree command.\n";
        ss << getHelpMessage();
        return ss.str();
    }

    KruskalMST graph(V);

    for (size_t i = 0; i < edges.size(); i += 3) {
        int src = edges[i];
        int dest = edges[i + 1];
        int weight = edges[i + 2];
        graph.addEdge(src, dest, weight);
    }

    std::vector<Edge> mst = graph.getMinimumSpanningTree();

    std::stringstream ss;
    for (const auto& edge : mst) {
        ss << edge.src << " -- " << edge.dest << " : " << edge.weight << "\n";
    }
    return ss.str();
}

std::string MinimumSpanningTreeApp::
processMinimumSpanningTreeWeight(int argc, char** argv) {
    int V = std::stoi(argv[2]);

    std::vector<int> edges;
    for (int i = 3; i < argc; ++i) {
        edges.push_back(std::stoi(argv[i]));
    }

    if (edges.size() % 3 != 0) {
        std::stringstream ss;
        ss << "Invalid number of arguments "
           <<"for minimum spanning tree weight command.\n";
        ss << getHelpMessage();
        return ss.str();
    }

    KruskalMST graph(V);

    for (size_t i = 0; i < edges.size(); i += 3) {
        int src = edges[i];
        int dest = edges[i + 1];
        int weight = edges[i + 2];
        graph.addEdge(src, dest, weight);
    }

    int weight = graph.getMinimumSpanningTreeWeight();

    std::stringstream ss;
    ss << "Minimum Spanning Tree Weight: " << weight << "\n";
    return ss.str();
}
