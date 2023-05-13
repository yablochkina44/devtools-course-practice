// Copyright 2023 Mikerin Ilya

#include "include/Dijkstra.h"


Dijkstra::Dijkstra() {
    Matrix = std::vector<std::vector<double>>();
    Answer = std::vector<double>();
    TaskComplite = false;
}

Dijkstra::Dijkstra(const Dijkstra &object) {
    Matrix = std::vector<std::vector<double>>();
    for (const std::vector<double>& vec : object.Matrix)
        Matrix.push_back(std::vector<double>(vec));

    Start = object.Start;

    Answer = std::vector<double>(object.Answer);

    TaskComplite = object.TaskComplite;
}

std::vector<std::vector<double>> Dijkstra::getPathsMatrix() const {
    return Matrix;
}

int Dijkstra::setNewTask(const std::vector<std::vector<double>> &matrix,
                         int start) {
    if (!matrix.empty() && matrix.size() == matrix.at(0).size() &&
        start > -1 && (std::size_t)start < matrix.size()) {
        bool SizeOk = true;
        for (auto vec : matrix) {
            if (vec.size() != matrix.size()) {
                SizeOk = false;
                break;
            }
        }

        if (SizeOk) {
            Matrix = std::vector<std::vector<double>>();
            for (auto vec : matrix)
                Matrix.push_back(std::vector<double>(vec));

            Start = start;
            TaskComplite = false;
            Answer = std::vector<double>(matrix.size());

            for (int i =0; (std::size_t)i< Answer.size(); i++)
                Answer.at(i) = std::numeric_limits<double>().max();

            return 0;
        }
    }
    return -1;
}

void Dijkstra::Solve() {
    if (Answer != std::vector<double>()) {
        int vertex = Start;
        int len = 0;

        int nextVertex = -1;
        double minPath = std::numeric_limits<double>().max();

        std::vector<bool> end = std::vector<bool>(Matrix.size());
        for (int i = 0; (std::size_t)i < end.size(); i++) end.at(i) = false;


        Answer.at(vertex) = 0;

        for (int i = 0; (std::size_t)i < Matrix.size(); i++) {
            for (int j = 0; (std::size_t)j < Matrix.size(); j++) {
                if (j != vertex) {
                    if (Matrix.at(vertex).at(j) >= 0) {
                        len = Answer.at(vertex) + Matrix.at(vertex).at(j);
                        if (len < Answer.at(j))
                            Answer.at(j) = len;
                    }

                    if (minPath > Answer.at(j) && !end.at(j)) {
                        minPath = Answer.at(j);
                        nextVertex = j;
                    }
                }
            }

            end.at(vertex) = true;

            if (nextVertex == -1) {
                break;
            }

            vertex = nextVertex;
            nextVertex = -1;
            minPath = std::numeric_limits<double>().max();
        }

        for (int i = 0; (std::size_t)i < Answer.size(); i++)
            if (Answer.at(i) == std::numeric_limits<double>().max())
                Answer.at(i) = -1;

        TaskComplite = true;
    }
}

std::vector<double> Dijkstra::getAnswer() const {
    if (TaskComplite) return Answer;
    else
        return std::vector<double>();
}

double Dijkstra::getAnswer(int finish) const {
    if (finish > -1 &&
            (std::size_t)finish < Answer.size() &&
            TaskComplite) return Answer[finish];
    return -2;
}

bool Dijkstra::getTaskComplite() const {
    return TaskComplite;
}
