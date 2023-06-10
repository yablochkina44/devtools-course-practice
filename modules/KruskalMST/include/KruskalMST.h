// Copyright 2023 Shuin Evgeniy

#ifndef MODULES_KRUSKALMST_INCLUDE_KRUSKALMST_H_
#define MODULES_KRUSKALMST_INCLUDE_KRUSKALMST_H_

#include <vector>

struct Edge {
    int src, dest, weight;
};

class KruskalMST {
    int V;  // Number of vertices
    std::vector<Edge> edges;  // Graph edges

    int findParent(int* parent, int i);
    void unionSubsets(int* parent, int x, int y);

 public:
    explicit KruskalMST(int V);
    int getEdgesSize();
    void addEdge(int src, int dest, int weight);
    std::vector<Edge> getMinimumSpanningTree();
    int getMinimumSpanningTreeWeight();
};

#endif  // MODULES_KRUSKALMST_INCLUDE_KRUSKALMST_H_
