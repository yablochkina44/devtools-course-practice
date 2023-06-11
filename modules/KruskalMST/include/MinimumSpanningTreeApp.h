// Copyright 2023 Shuin Evgeniy

#ifndef MODULES_KRUSKALMST_INCLUDE_MINIMUMSPANNINGTREEAPP_H_
#define MODULES_KRUSKALMST_INCLUDE_MINIMUMSPANNINGTREEAPP_H_

#include "KruskalMST.h"
#include <string>

class MinimumSpanningTreeApp {
 public:
    MinimumSpanningTreeApp();

    std::string processCommand(int argc, char** argv);

 private:
    std::string getHelpMessage();
    std::string processMinimumSpanningTree(int argc, char** argv);
    std::string processMinimumSpanningTreeWeight(int argc, char** argv);
};

#endif  // MODULES_KRUSKALMST_INCLUDE_MINIMUMSPANNINGTREEAPP_H_
