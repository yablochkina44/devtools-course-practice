// Copyright 2023 Mikerin Ilya

#include <gtest/gtest.h>

#include "include/Dijkstra.h"

TEST(Dijkstra, TEST_alghorithm) {
  Dijkstra d = Dijkstra();
  std::vector<std::vector<double>> path = {{0 ,  7,  9, -1, -1, 14},
                                           {7 ,  0, 10, 15, -1, -1},
                                           {9 , 10,  0, 11, -1,  2},
                                           {-1, 15, 11,  0,  6, -1},
                                           {-1, -1, -1,  6,  0,  9},
                                           {14, -1,  2, -1,  9,  0}};
  int ans = d.setNewTask(path, 0);

    ASSERT_EQ(d.getTaskComplite(), false);
  d.Solve();
    ASSERT_EQ(d.getTaskComplite(), true);

    ASSERT_EQ(ans, 0);
    ASSERT_EQ(d.getAnswer(), std::vector<double>({0, 7, 9, 20, 20, 11}));
}

TEST(Dijkstra, TEST_GetAnswer) {
    Dijkstra d = Dijkstra();
    std::vector<std::vector<double>> path = {{0 ,  7,  9, -1, -1, 14},
                                             {7 ,  0, 10, 15, -1, -1},
                                             {9 , 10,  0, 11, -1,  2},
                                             {-1, 15, 11,  0,  6, -1},
                                             {-1, -1, -1,  6,  0,  9},
                                             {14, -1,  2, -1,  9,  0}};
    d.setNewTask(path, 0);

    d.Solve();

    ASSERT_EQ(d.getAnswer(0), 0);
    ASSERT_EQ(d.getAnswer(-1), -2);
    ASSERT_EQ(d.getAnswer(5), 11);
    ASSERT_EQ(d.getAnswer(6), -2);
}

TEST(Dijkstra, TEST_GetEmptyAnswer1) {
    Dijkstra d = Dijkstra();

    ASSERT_EQ(d.getAnswer() , std::vector<double>());
}

TEST(Dijkstra, TEST_GetEmptyPath) {
    Dijkstra d = Dijkstra();

    ASSERT_EQ(d.getPathsMatrix() , std::vector<std::vector<double>>());
}

TEST(Dijkstra, TEST_GetEmptyAnswer2) {
    Dijkstra d = Dijkstra();

    ASSERT_EQ(d.getAnswer(0) , -2);
    ASSERT_EQ(d.getAnswer(-1) , -2);
    ASSERT_EQ(d.getAnswer(3) , -2);
}

TEST(Dijkstra, TEST_GetEmptyMatrix) {
    Dijkstra d = Dijkstra();

    ASSERT_EQ(d.getPathsMatrix() , std::vector<std::vector<double>>());
}

TEST(Dijkstra, TEST_WrongMatrix) {
    Dijkstra d = Dijkstra();
    std::vector<std::vector<double>> path = {{0 ,  7,  9, -1, -1, 14},
                                             {7 ,  0, 10, 15, -1, -1},
                                             {9 , 10,  0, 11, -1,  2},
                                             {-1, 15, 11,  0,  6, -1},
                                             {-1, -1, -1,  6,  0,  9, 14},
                                             {14, -1,  2, -1,  9,  0}};
    int ans = d.setNewTask(path, 0);

    ASSERT_EQ(ans, -1);
    ASSERT_EQ(d.getPathsMatrix(), std::vector<std::vector<double>>());
}

TEST(Dijkstra, TEST_getPath) {
    Dijkstra d = Dijkstra();
    std::vector<std::vector<double>> path = {{0,  7,  9,  -1, -1, 14},
                                             {7,  0,  10, 15, -1, -1},
                                             {9,  10, 0,  11, -1, 2},
                                             {-1, 15, 11, 0,  6,  -1},
                                             {-1, -1, -1, 6,  0,  9},
                                             {14, -1, 2,  -1, 9,  0}};
    d.setNewTask(path, 0);

    ASSERT_EQ(d.getPathsMatrix(), path);
}

TEST(Dijkstra, TEST_Copy) {
    Dijkstra d = Dijkstra();
    std::vector<std::vector<double>> path = {{0,  7,  9,  -1, -1, 14},
                                             {7,  0,  10, 15, -1, -1},
                                             {9,  10, 0,  11, -1, 2},
                                             {-1, 15, 11, 0,  6,  -1},
                                             {-1, -1, -1, 6,  0,  9},
                                             {14, -1, 2,  -1, 9,  0}};
    d.setNewTask(path, 0);
    Dijkstra dClone = Dijkstra(d);
    ASSERT_EQ(dClone.getPathsMatrix(), d.getPathsMatrix());
    ASSERT_EQ(dClone.getAnswer(), d.getAnswer());
    ASSERT_EQ(dClone.getTaskComplite(), d.getTaskComplite());
    d.Solve();
    ASSERT_NE(d.getAnswer(), dClone.getAnswer());
}

TEST(Dijkstra, TEST_NoWay) {
    Dijkstra d = Dijkstra();
    std::vector<std::vector<double>> path = {{0 ,  -1,  -1, -1, -1, -1},
                                             {-1 ,  0, 10, 15, -1, -1},
                                             {-1 , 10,  0, 11, -1,  2},
                                             {-1, 15, 11,  0,  6, -1},
                                             {-1, -1, -1,  6,  0,  9},
                                             {-1, -1,  2, -1,  9,  0}};
    int ans = d.setNewTask(path, 0);

    ASSERT_EQ(d.getTaskComplite(), false);
    d.Solve();
    ASSERT_EQ(d.getTaskComplite(), true);

    ASSERT_EQ(ans, 0);
    ASSERT_EQ(d.getAnswer(), std::vector<double>({0, -1, -1, -1, -1, -1}));
}
