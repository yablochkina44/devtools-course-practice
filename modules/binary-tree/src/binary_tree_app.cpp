// Copyright 2023 Zorin Oleg

#include <cstring>
#include <stdexcept>
#include "include/binary_tree_app.h"

BTApplication::BTApplication() = default;

void BTApplication::help(const char *appname, const char *message) {
  std::string mes = std::string(message);
  mes += mes.empty() ? "" : "\n\n";
  message_ = mes +
      "This is binary tree application.\n\n" +
      "  $ " + appname + " <operation> <value> ... <operation> <value> \n\n" +
      "Where <value> is integer number, " +
      "and <operation> is one of:\n" +
      "find\t--\tFinds element in binary tree\n" +
      "insert\t--\tInserts element to binary tree\n" +
      "delete\t--\tDeletes element from binary tree\n" +
      "empty\t--\tChecks tree for empty\n" +
      "reset\t--\tResets an iterator\n" +
      "next\t--\tMoves the iterator to the next position\n" +
      "get\t--\tReturns a value from an iterator\n" +
      "end\t--\tChecks end for iterator\n";
}

std::string BTApplication::operator()(int argc, const char **argv) {
  if (argc == 1)
    help(argv[0]);
  char op;
  int value;
  int state = 0;
  try {
    for (int i = 1; i < argc; ++i) {
      switch (state) {
        case 0:
          op = parseOperation(argv[i]);
          switch (op) {
            case 'f':
              state = 1;
              break;
            case 'i':
              state = 1;
              break;
            case 'd':
              state = 1;
              break;
            case 'e':
              message_ = tree.IsEmpty() ?
                  "Binary tree is empty." : "Binary tree isn't empty.";
              break;
            case 'r':
              tree.Reset();
              message_ = "Iterator resets.";
              break;
            case 'n':
              tree.SetNext();
              message_ = "Iterator moves to the next position.";
              break;
            case 'g':
              value = tree.GetValue();
              message_ = "Value: " + std::to_string(value);
              break;
            case 'E':
              message_ = tree.IsEnd() ? "This is the end..." : "Not the end.";
              break;
          }
          break;
        case 1:
          value = std::stoi(argv[i]);
          state = 0;
          switch (op) {
            case 'f':
              message_ = tree.Find(value) ?
                  "Element is in tree." : "Element isn't in tree.";
              break;
            case 'i':
              tree.Insert(value);
              message_ = "Element placed in tree.";
              break;
            case 'd':
              tree.Delete(value);
              message_ = "Element removed from tree.";
              break;
          }
          break;
      }
    }
    if (state == 1)
      throw std::invalid_argument("Argument expected");
  } catch (const std::exception &err) {
    help(argv[0], err.what());
  }

  return message_;
}

char BTApplication::parseOperation(const char *arg) {
  char op;
  if (strcmp(arg, "find") == 0) {
    op = 'f';
  } else if (strcmp(arg, "insert") == 0) {
    op = 'i';
  } else if (strcmp(arg, "delete") == 0) {
    op = 'd';
  } else if (strcmp(arg, "empty") == 0) {
    op = 'e';
  } else if (strcmp(arg, "reset") == 0) {
    op = 'r';
  } else if (strcmp(arg, "next") == 0) {
    op = 'n';
  } else if (strcmp(arg, "get") == 0) {
    op = 'g';
  } else if (strcmp(arg, "end") == 0) {
    op = 'E';
  } else {
    throw std::invalid_argument("ERROR: wrong operation.");
  }
  return op;
}

