// Copyright 2023 Shokurov Daniil

#include "../include/longest_inc_subseq.h"
#include "../include/longest_inc_subseq_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

Application::Application() : message_("") {}

void Application::help(const char* appname, const char* message) {
  message_ = std::string(message) +
             "This app is for finding the largest increasing sequence.\n\n" +
             "Please provide arguments in the following format:\n\n" +

             "  $ " + appname + " <value_1> <value_2> ... " +
             "<value_n>. \n\n" + "Where all values are integers.\n ";
}

bool Application::validateNumberOfArguments(int argc, const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  }
  return true;
}

int parseInt(const char* arg) {
  char* end;
  int value = strtol(arg, &end, 10);

  if (end[0]) {
    throw std::string("Wrong number format!");
  }

  return value;
}

std::string Application::operator()(int argc, const char** argv) {
  std::vector<int> values;
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }
  try {
    for (int i = 1; i < argc; ++i) {
      int value = parseInt(argv[i]);
      values.push_back(value);
    }
  } catch (std::string& str) {
    return str;
  }
  std::vector<int> answer = longestIncreasingSubsequence(values);

  std::ostringstream stream;
  for (size_t i = 0; i < answer.size(); ++i) {
    stream << answer[i] << " ";
  }

  message_ = stream.str();

  return message_;
}
