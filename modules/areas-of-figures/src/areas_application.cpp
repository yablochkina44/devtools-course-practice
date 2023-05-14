  // Copyright 2023 Makarov Danila


#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

#include "../include/areas.h"
#include "../include/areas_application.h"

std::string AreasApplication::help(const char* nameOfApp) {
  return std::string("This application is used to find the areas of figures") +
         " such as a Parallelepiped, a Sphere and a Cylinder.\n\n" +
         "Use the following examples to find the area of a given " +
         "figure:\n\n" + "$ " + nameOfApp + " <radius>" +
         " - to find Sphere area\n\n" + "  $ " + nameOfApp +
         " <radius> <height>" + " - to find Cylinder area\n\n" + "  $ " +
         nameOfApp + " <width> <height> <length>" +
         " - to find Parallelepiped area\n\n" +
         "Where all values are double.\n ";
}

double parseDouble(const char* arg) {
  double value;
  value = strtod(arg, NULL);
  if (value == 0.) throw std::string("Invalid argument format!");
  return value;
}

bool AreasApplication::argumentsIsValid(int argc, const char** argv) {
  if (argc == 1) {
    validatorMessage = help(argv[0]);
    return false;
  }

  if (argc > 4) {
    validatorMessage =
        std::string("Input must contain no more than three arguments!");
    return false;
  }

  std::vector<double> args;

  for (int i = 1; i < argc; i++) {  // проверки на возможность парсить в double
    double value;
    try {
      value = parseDouble(argv[i]);
      args.push_back(value);
    } catch (std::string& str) {
      validatorMessage =
          std::string("Parsing is failed. " + str + "\n");
      return false;
    }
  }

  int size = args.size();

  for (int i = 0; i < size; i++) {  // проверка <= 0
    if (args[i] <= 0) {
      validatorMessage = std::string("Argument is negative or zero: ") +
                         std::to_string(args[i]) + "\n";
      return false;
    }
  }

  return true;  // Если все проверки прошли, то возвращаем true
}

std::string AreasApplication::operator()(int argc, const char** argv) {
  if (!argumentsIsValid(argc, argv)) return validatorMessage;

  std::string result;
  std::vector<double> values;

  for (int i = 1; i < argc; i++) {
    double value;
    value = parseDouble(argv[i]);
    values.push_back(value);
  }

  switch (values.size()) {
    case 1: {
      Sphere s(values[0]);
      result = std::string("Sphere area is ") + std::to_string(s.area());
    } break;
    case 2: {
      Cylinder c(values[0], values[1]);
      result = std::string("Cylinder area is ") + std::to_string(c.area());
    } break;
    case 3: {
      Parallelepiped p(values[0], values[1], values[2]);
      result =
          std::string("Parallelepiped area is ") + std::to_string(p.area());
    } break;
  }

  return result;
}
