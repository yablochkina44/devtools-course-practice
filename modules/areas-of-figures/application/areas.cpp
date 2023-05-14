// Copyright 2023 Makarov Danila

#include "../include/areas_application.h"

int main(int argc, const char **argv) {
  AreasApplication app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
