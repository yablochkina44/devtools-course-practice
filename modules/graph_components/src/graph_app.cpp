// Copyright 2023 Shaposhnikova Ekaterina

#include "../include/graph_app.h"

#include <iostream>
#include <stdexcept>
#include <string>

std::string GraphComponentsApp::help() {
  std::string helpStr;
  helpStr.append("This is an app for counting the number of connectivity ");
  helpStr.append("components in a graph.\n");
  helpStr.append("Please enter the arguments in the following order:\n");
  helpStr.append("firstly, enter the number of vertices in the graph, ");
  helpStr.append("then enter the vertices that are connected ");
  helpStr.append("by edges in pairs.\n");
  helpStr.append("The number of arguments must be even and greater than one\n");
  return helpStr;
}

std::string GraphComponentsApp::operator()(int argc, char** argv) {
  int numNodes;
  if (argc == 1 || argc % 2 != 0) {
    return help();
  }
  try {
    numNodes = std::atoi(argv[1]);
  }
  catch (std::string& err) {
    return err;
  }
  Graph g(numNodes);
  try {
    for (int i = 2; i < argc; i+=2) {
      int node1 = std::atoi(argv[i]);
      int node2 = std::atoi(argv[i+1]);
      g.Add_Edge(node1, node2);
    }
  }
  catch (std::string& err) {
    return err;
  }
  std::string res = "The number of connectivity components in the graph is "
    + std::to_string(g.Get_Num_Of_Components());
  return res;
}
