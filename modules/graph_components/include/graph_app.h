// Copyright 2023 Shaposhnikova Ekaterina

#ifndef MODULES_GRAPH_COMPONENTS_INCLUDE_GRAPH_APP_H_
#define MODULES_GRAPH_COMPONENTS_INCLUDE_GRAPH_APP_H_

#include "./graph.h"

#include <iostream>
#include <string>

class GraphComponentsApp {
 public:
  std::string operator()(int argc, char** argv);

 private:
  std::string help();
};
#endif  //  MODULES_GRAPH_COMPONENTS_INCLUDE_GRAPH_APP_H_
