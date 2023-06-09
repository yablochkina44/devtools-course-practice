// Copyright Simeunovic Aleksandar 2023

#ifndef MODULES_GRAPH_COMPONENTS_INCLUDE_GRAPH_H_
#define MODULES_GRAPH_COMPONENTS_INCLUDE_GRAPH_H_
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<list>
#include<utility>

class Graph {
 public:
    explicit Graph(uint64_t num_of_nodes);
    Graph(bool** matrix_adjacency, uint64_t num_of_nodes);
    Graph(const std::unordered_map<int,
    std::list<int>>& adjacency_map, uint64_t num_of_nodes);
    void Add_Edge(uint64_t u, uint64_t w);
    void Delete_Edge(uint64_t, uint64_t w);
    bool Has_Edge(uint64_t, uint64_t w);
    uint64_t Get_Num_Of_Components();
 private:
    std::unordered_map<int, std::list<int>> adjacency_map;
    uint64_t __num_of_nodes;
    void Depth_Search(uint64_t start_node, bool* visited);
};
#endif  // MODULES_GRAPH_COMPONENTS_INCLUDE_GRAPH_H_
