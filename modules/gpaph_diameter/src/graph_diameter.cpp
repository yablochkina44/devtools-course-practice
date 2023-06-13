// Copyright 2023 Khairetdinov Timur
#include "include/graph_diameter.h"

#include <algorithm>
#include <queue>
#include <vector>

Graph::Graph()
    : graph_size_(0),
    weights_(Matrix(0, Vector(0))) {}

Graph::Graph(size_t size_graph)
    : graph_size_(size_graph), weights_(
        Matrix(size_graph, Vector(size_graph, 0))) {}

Graph::Graph(Matrix& matrix_weights)
    : graph_size_(matrix_weights.size()), weights_(matrix_weights) {}

size_t Graph::GetSize() const {
    return graph_size_;
}

void Graph::SetSize(size_t graph_new_size) {
    auto min_size = std::min(graph_size_, graph_new_size);
    Matrix new_weights(graph_new_size, Vector(graph_new_size, 0));
    for (size_t i = 0; i < min_size; ++i) {
        new_weights[i][i] = weights_[i][i];
        for (size_t j = i + 1; j < min_size; ++j) {
            new_weights[i][j] = new_weights[j][i] = weights_[i][j];
        }
    }
    weights_ = new_weights;
    graph_size_ = graph_new_size;
}

void Graph::SetEdge(size_t f_elem, size_t s_elem, int weight) {
    auto n = std::max(f_elem, s_elem);
    if (n >= graph_size_) {
        this->SetSize(n + 1);
    }
    weights_[f_elem][s_elem] = weights_[s_elem][f_elem] = weight;
}

int Graph::GetDiameter() {
    if (graph_size_ < 2) {
        return 0;
    }
    std::vector<int> wat_path(graph_size_, -1);
    std::queue<size_t> current_graph;

    current_graph.push(static_cast<size_t>(0));
    wat_path[0] = 0;
    while (!current_graph.empty()) {
        auto now = current_graph.front();
        current_graph.pop();
        for (size_t i = 0; i < graph_size_; ++i) {
            if (weights_[now][i]) {
                auto new_cost = wat_path[now] + weights_[now][i];
                if (wat_path[i] == -1 || new_cost < wat_path[i]) {
                    wat_path[i] = new_cost;
                    current_graph.push(i);
                }
            }
        }
    }

    int diameter = wat_path[1];
    size_t max_way_index = 1;
    for (size_t i = 2; i < graph_size_; ++i) {
        if (wat_path[i] == -1) {
            return -1;
        }
        if (wat_path[i] > diameter) {
            diameter = wat_path[i];
            max_way_index = i;
        }
    }
    for (size_t i = 0; i < graph_size_; ++i) {
        wat_path[i] = -1;
    }

    current_graph.push(max_way_index);
    wat_path[max_way_index] = 0;
    while (!current_graph.empty()) {
        auto now = current_graph.front();
        current_graph.pop();
        for (size_t i = 0; i < graph_size_; ++i) {
            if (weights_[now][i]) {
                auto new_cost = wat_path[now] + weights_[now][i];
                if (wat_path[i] == -1 || new_cost < wat_path[i]) {
                    wat_path[i] = new_cost;
                    current_graph.push(i);
                }
            }
        }
    }

    diameter = wat_path[0];
    for (size_t i = 1; i < graph_size_; ++i) {
        if (wat_path[i] > diameter) {
            diameter = wat_path[i];
        }
    }
    return diameter;
}
