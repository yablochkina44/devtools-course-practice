// Copyright Simeunovic Aleksandar 2023

#include"include/graph.h"

Graph::Graph(uint64_t num_of_nodes = 10) {
    if (num_of_nodes == 0)throw "Size can't be zero";
    __num_of_nodes = num_of_nodes;
}

Graph::Graph(bool** matrix_adjacency, uint64_t num_of_nodes) {
    if (num_of_nodes == 0)throw "Size can't be zero";
    __num_of_nodes = num_of_nodes;
    for (uint64_t i = 0; i < num_of_nodes; i++) {
        for (uint64_t j = i; j < num_of_nodes; j++) {
            if (matrix_adjacency[i][j]) {
                adjacency_map[i].push_back(j);
                adjacency_map[j].push_back(i);
            }
        }
    }
}

Graph::Graph(const std::unordered_map<int,
std::list<int>>& adjacency_map, uint64_t num_of_nodes) {
    if (num_of_nodes == 0)throw "Size can't be zero";
    __num_of_nodes = num_of_nodes;
    this->adjacency_map = adjacency_map;
}

bool Graph::Has_Edge(uint64_t u, uint64_t w) {
    auto find = std::find(adjacency_map[u].begin(), adjacency_map[u].end(), w);
    return (find != adjacency_map[u].end()) ? true : false;
}

void Graph::Add_Edge(uint64_t u, uint64_t w) {
    if (u < 0 || u >= __num_of_nodes || w < 0 ||
    w >= __num_of_nodes)throw
    "Nodes are numbered from 0 to __num_of_nodes-1!!!";
    if (!Has_Edge(u, w)) {
        adjacency_map[u].push_back(w);
        adjacency_map[w].push_back(u);
    }
}

void Graph::Delete_Edge(uint64_t u, uint64_t w) {
    if (u < 0 || u >= __num_of_nodes || w < 0 ||
    w >= __num_of_nodes)throw
    "Nodes are numbered from 0 to __num_of_nodes-1!!!";
    if (Has_Edge(u, w)) {
        adjacency_map[u].remove(w);
        adjacency_map[w].remove(u);
    }
}

void Graph::Depth_Search(uint64_t start_node, bool* visited) {
    visited[start_node] = true;
    for (auto it = adjacency_map[start_node].begin();
    it != adjacency_map[start_node].end(); ++it) {
        if (!visited[*it])Depth_Search(*it, visited);
    }
}

uint64_t Graph::Get_Num_Of_Components() {
    bool* visited = new bool[__num_of_nodes];
    for (uint64_t i = 0; i < __num_of_nodes; i++) {
        visited[i] = false;
    }
    uint64_t num_of_components = 0;
    for (uint64_t i = 0; i < __num_of_nodes; i++) {
        if (!visited[i]) {
            num_of_components++;
            Depth_Search(i, visited);
        }
    }
    return num_of_components;
}
