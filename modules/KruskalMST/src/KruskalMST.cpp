// Copyright 2023 Shuin Evgeniy

#include "include/KruskalMST.h"
#include <algorithm>

KruskalMST::KruskalMST(int V) {
    this->V = V;
}

// Get the length of the graph
int KruskalMST::getEdgesSize() {
    return edges.size();
}

// Add an edge to the graph
void KruskalMST::addEdge(int src, int dest, int weight) {
    Edge edge;
    edge.src = src;
    edge.dest = dest;
    edge.weight = weight;
    edges.push_back(edge);
}

// Find the parent of a vertex
int KruskalMST::findParent(int* parent, int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

// Union of two subsets
void KruskalMST::unionSubsets(int* parent, int x, int y) {
    int xset = findParent(parent, x);
    int yset = findParent(parent, y);
    parent[xset] = yset;
}

// Get the minimum spanning tree as a vector of edge
std::vector<Edge> KruskalMST::getMinimumSpanningTree() {
    std::vector<Edge> result;
    std::sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
        });

    int* parent = new int[V];
    std::fill(parent, parent + V, -1);

    for (const auto& edge : edges) {
        int x = findParent(parent, edge.src);
        int y = findParent(parent, edge.dest);

        if (x != y) {
            result.push_back(edge);
            unionSubsets(parent, x, y);
        }
    }

    delete[] parent;

    return result;
}


// Get the weight of the minimum spanning tree
int KruskalMST::getMinimumSpanningTreeWeight() {
    int weight = 0;
    std::vector<Edge> mst = getMinimumSpanningTree();
    for (const auto& edge : mst)
        weight += edge.weight;
    return weight;
}
