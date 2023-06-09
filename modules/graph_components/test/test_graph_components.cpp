// Copyright Simeunovic Aleksandar 2023

#include<gtest/gtest.h>
#include<random>
#include"include/graph.h"


TEST(Simeunovic_Aleksandar_Graph_Components, default_constructor_test) {
    Graph g();
    ASSERT_NO_THROW();
}

TEST(Simeunovic_Aleksandar_Graph_Components, zero_size_test) {
    EXPECT_ANY_THROW({ Graph g(0); });
}

TEST(Simeunovic_Aleksandar_Graph_Components, matrix_adjacency_test1) {
    bool** matrix;
    matrix = new bool* [3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new bool[3];
        for (int j = 0; j < 3; j++) {
            if (i == j)matrix[i][j] = false;
            else
            matrix[i][j] = true;
        }
    }
    Graph g(matrix, 3);
    ASSERT_NO_THROW();
}

TEST(Simeunovic_Aleksandar_Graph_Components, matrix_adjacency_test2) {
    bool** matrix;
    matrix = new bool* [3];
    for (int i = 0; i < 3; i++) {
        matrix[i] = new bool[3];
        for (int j = 0; j < 3; j++) {
            if (i == j)matrix[i][j] = false;
            else
            matrix[i][j] = true;
        }
    }
    Graph g(matrix, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
           if (i != j) {
            EXPECT_EQ(true, g.Has_Edge(i, j));
           }
        }
    }
}

TEST(Simeunovic_Aleksandar_Graph_Components, matrix_adjacency_test3) {
    std::random_device dev;
    std::mt19937 rand_r(dev());
    uint64_t num_of_nodes = rand_r() % 100+1;
    bool** matrix;
    matrix = new bool* [num_of_nodes];
    for (uint64_t i = 0; i < num_of_nodes; i++) {
        matrix[i] = new bool[num_of_nodes];
        for (uint64_t j = i; j < num_of_nodes; j++) {
            if (i == j) {
                matrix[i][j] = false;
            } else {
                int num = rand_r() % 2;
                if (num)matrix[i][j] = true;
                else
                matrix[i][j] = false;
            }
        }
    }
    Graph g(matrix, num_of_nodes);
    for (uint64_t i = 0; i < num_of_nodes; i++) {
        for (uint64_t j = i; j < num_of_nodes; j++) {
            EXPECT_EQ(matrix[i][j], g.Has_Edge(i, j));
        }
    }
}

TEST(Simeunovic_Aleksandar_Graph_Components, unordered_map_constructor) {
    std::unordered_map<int, std::list<int> > adjacency_map;
    adjacency_map[0]={1, 2};
    adjacency_map[1]={0};
    Graph g(adjacency_map, 5);
    EXPECT_NO_THROW();
}

TEST(Simeunovic_Aleksandar_Graph_Components, adding_edge_out_of_range) {
    Graph g(5);
    EXPECT_ANY_THROW({ g.Add_Edge(0, 5); });
}

TEST(Simeunovic_Aleksandar_Graph_Components, delete_edge_out_of_range) {
    Graph g(5);
    EXPECT_ANY_THROW({ g.Delete_Edge(0, 5); });
}

TEST(Simeunovic_Aleksandar_Graph_Components, adding_edge) {
    Graph g(5);  // There are no edges between any two pair of nodes
    EXPECT_EQ(false, g.Has_Edge(1, 3));
    g.Add_Edge(1, 3);
    EXPECT_EQ(true, g.Has_Edge(1, 3));
    EXPECT_EQ(true, g.Has_Edge(3, 1));
}

TEST(Simeunovic_Aleksandar_Graph_Components, deleting_edge) {
    Graph g(5);
    g.Add_Edge(1, 3);
    EXPECT_EQ(true, g.Has_Edge(1, 3));
    g.Delete_Edge(1, 3);
    EXPECT_EQ(false, g.Has_Edge(1, 3));
    EXPECT_EQ(false, g.Has_Edge(3, 1));
}

TEST(Simeunovic_Aleksandar_Graph_Components, num_of_components1) {
    Graph g(5);
    g.Add_Edge(0, 1);
    g.Add_Edge(0, 2);
    g.Add_Edge(0, 3);
    // Expecting components:[0,1,2,3],[4]
    uint64_t expected = 2;
    EXPECT_EQ(expected, g.Get_Num_Of_Components());
}

TEST(Simeunovic_Aleksandar_Graph_Components, num_of_components2_no_edges) {
    Graph g(5);
    // Expecting components:[0],[1],[2],[3],[4]
    uint64_t expected = 5;
    EXPECT_EQ(expected, g.Get_Num_Of_Components());
}

TEST(Simeunovic_Aleksandar_Graph_Components, num_of_components3) {
    Graph g(10);
    g.Add_Edge(0, 1);
    g.Add_Edge(0, 2);
    g.Add_Edge(4, 5);
    g.Add_Edge(5, 6);
    // Expecting components:[0,1,2],[3],[4,5,6],[7],[8],[9]
    uint64_t expected = 6;
    EXPECT_EQ(expected, g.Get_Num_Of_Components());
}

TEST(Simeunovic_Aleksandar_Graph_Components, one_with_all) {
    std::random_device dev;
    std::mt19937 rand_r(dev());
    uint64_t num_of_nodes = rand_r() % 100 + 1;
    Graph g(num_of_nodes);
    for (uint64_t i = 1; i < num_of_nodes; i++) {
        g.Add_Edge(0, i);
    }
    uint64_t expected = 1;
    EXPECT_EQ(expected, g.Get_Num_Of_Components());
}

TEST(Simeunovic_Aleksandar_Graph_Components, every_pair_is_connected) {
    std::random_device dev;
    std::mt19937 rand_r(dev());
    uint64_t num_of_nodes = rand_r() % 100 + 1;
    Graph g(num_of_nodes);
    for (uint64_t i = 0; i < num_of_nodes; i++) {
       for (uint64_t j = 0; j < num_of_nodes; j++) {
           g.Add_Edge(i, j);
        }
    }
    uint64_t expected = 1;
    EXPECT_EQ(expected, g.Get_Num_Of_Components());
}
