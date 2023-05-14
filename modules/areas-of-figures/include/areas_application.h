// Copyright 2023 Makarov Danila

#ifndef MODULES_AREAS_OF_FIGURES_INCLUDE_AREAS_APPLICATION_H_
#define MODULES_AREAS_OF_FIGURES_INCLUDE_AREAS_APPLICATION_H_

#include <string>

class AreasApplication {
 public:
  std::string operator()(int argc, const char **argv);

 private:
  std::string help(const char *nameOfApp);
  bool argumentsIsValid(int argc, const char **argv);
  std::string validatorMessage;
};

#endif  // MODULES_AREAS_OF_FIGURES_INCLUDE_AREAS_APPLICATION_H_
