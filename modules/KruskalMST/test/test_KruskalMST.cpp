// Copyright 2023 Shuin Evgeniy

#include <gtest/gtest.h>
#include <vector>
#include "include/KruskalMST.h"

// Test case for adding edges to the graph
TEST(KruskalMSTTest, AddEdge) {
    KruskalMST graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    EXPECT_EQ(5, graph.getEdgesSize());
}

// Test case for getting the minimum spanning tree
TEST(KruskalMSTTest, GetMinimumSpanningTree) {
    KruskalMST graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    std::vector<Edge> mst = graph.getMinimumSpanningTree();
    int size = static_cast<int>(mst.size());

    EXPECT_EQ(3, size);
}

// Test case for getting the weight of the minimum spanning tree
TEST(KruskalMSTTest, GetMinimumSpanningTreeWeight) {
    KruskalMST graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    int weight = graph.getMinimumSpanningTreeWeight();

    EXPECT_EQ(19, weight);
}

// Test case for an empty graph
TEST(KruskalMSTTest, EmptyGraph) {
    KruskalMST graph(0);

    std::vector<Edge> mst = graph.getMinimumSpanningTree();
    int weight = graph.getMinimumSpanningTreeWeight();

    EXPECT_TRUE(mst.empty());
    EXPECT_EQ(0, weight);
}

// Test case for a graph with a single vertex
TEST(KruskalMSTTest, SingleVertexGraph) {
    KruskalMST graph(1);

    std::vector<Edge> mst = graph.getMinimumSpanningTree();
    int weight = graph.getMinimumSpanningTreeWeight();

    EXPECT_TRUE(mst.empty());
    EXPECT_EQ(0, weight);
}

// Test case for a disconnected graph
TEST(KruskalMSTTest, DisconnectedGraph) {
    KruskalMST graph(5);

    graph.addEdge(0, 1, 4);
    graph.addEdge(1, 2, 2);
    graph.addEdge(2, 0, 1);
    graph.addEdge(3, 4, 5);

    std::vector<Edge> mst = graph.getMinimumSpanningTree();
    int weight = graph.getMinimumSpanningTreeWeight();
    int size = static_cast<int>(mst.size());

    EXPECT_EQ(3, size);
    EXPECT_EQ(8, weight);
}

// Test case for a graph with duplicate edges
TEST(KruskalMSTTest, DuplicateEdges) {
    KruskalMST graph(4);

    graph.addEdge(0, 1, 5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 3, 6);

    std::vector<Edge> mst = graph.getMinimumSpanningTree();
    int weight = graph.getMinimumSpanningTreeWeight();
    int size = static_cast<int>(mst.size());

    EXPECT_EQ(3, size);
    EXPECT_EQ(14, weight);
}
