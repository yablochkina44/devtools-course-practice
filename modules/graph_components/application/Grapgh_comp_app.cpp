// Copyright 2023 Shaposhnikova Ekaterina
#include <stdio.h>
#include <stdlib.h>

#include <string>

#include "../include/graph_app.h"

int main(int argc, char** argv) {
  GraphComponentsApp gApp;
  std::string outStr = gApp(argc, argv);
  std::cout << outStr;
  return 0;
}
