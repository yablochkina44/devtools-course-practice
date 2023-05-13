// Copyright 2023 Mikerin Ilya

#ifndef MODULES_DIJKSTRA_INCLUDE_DIJKSTRA_H_
#define MODULES_DIJKSTRA_INCLUDE_DIJKSTRA_H_

#include <vector>
#include <limits>


class Dijkstra {
 public:
    Dijkstra();

    Dijkstra(const Dijkstra& object);

    void Solve();

    std::vector<std::vector<double>> getPathsMatrix() const;

    int setNewTask(const std::vector<std::vector<double>>& matrix, int start);

    std::vector<double> getAnswer() const;

    double getAnswer(int finish) const;

    bool getTaskComplite() const;
 private:
    std::vector<std::vector<double>> Matrix;
    int Start;
    bool TaskComplite;
    std::vector<double> Answer;
};

#endif  // MODULES_DIJKSTRA_INCLUDE_DIJKSTRA_H_
