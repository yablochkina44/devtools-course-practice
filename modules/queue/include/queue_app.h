// Copyright 2023 Prokofev Denis
#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APP_H_

#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <class T>
class QueueApp {
    std::string message;
    void toStr();
  struct node {
    T data;
    node* nextNode;
  };
  node* head;
  int size;
 public:
     QueueApp();
  void help();
  std::string operator()(int argc, const char** argv);
  int parseInt(const char **el, int id);
  ~QueueApp();
  void push(T e);
  T pop();
  int length();
};

template <typename T>
QueueApp<T>::QueueApp() {
  size = 0;
  head = nullptr;
}

template <typename T>
QueueApp<T>::~QueueApp() {
  node* temp;
  while (head != nullptr) {
    temp = head;
    head = head->nextNode;
    delete temp;
  }
}

template <typename T>
T QueueApp<T>::pop() {
  node* temp = head;
  T data = head->data;
  head = head->nextNode;
  delete temp;
  size--;

  return data;
}

template <typename T>
void QueueApp<T>::push(T data) {
  node* newNode = new node;
  newNode->data = data;
  newNode->nextNode = nullptr;

  size++;

  if (head == nullptr) {
    head = newNode;
    return;
  }

  node* current = head;
  while (current != nullptr) {
    if (current->nextNode == nullptr) {
      current->nextNode = newNode;
      return;
    }

    current = current->nextNode;
  }
}

template <typename T>
int QueueApp<T>::length() {
  return size;
}

template <typename T>
void QueueApp<T>::help() {
    message.append("This is application for create Queue.\n")
    .append("Add data with push\n")
    .append("Read data with pop\n")
    .append("All elements must be integer!");
}

template <typename T>
int QueueApp<T>::parseInt(const char **el, int id) {
    int tmp =- 1;
    try {
      tmp = std::stoi(el[id]);
    }
    catch (std::invalid_argument & ) {
        message.append("please write int");
    }
    return tmp;
  }

template <typename T>
std::string QueueApp<T>::operator()(int argc, const char ** argv) {
  if (argc <= 2) {
    help();
    if (argc != 1) {
      message.append("write element");
    }
    return message;
  }

  std::string op = argv[1];
  if (op == "push") {
      if (argc > 2) {
        for (int i = 2; i < argc; i++) {
          int n = parseInt(argv, i);
          if (n == -1) return message;
          push(n);
        }
      }
      toStr();
      return message;
  } else if (op == "pop") {
      if (argc > 2) {
        for (int i = 2; i < argc; i++) {
          int n = parseInt(argv, i);
          if (n == -1) return message;
          push(n);
        }
      }
      pop();
      toStr();
      return message;
  } else if (op == "length") {
    if (argc > 2) {
      for (int i = 2; i < argc; i++) {
        int n = parseInt(argv, 2);
        push(n);
      }
    }
    message.append("size: ").append(std::to_string(length()))
    .append("\n");
  } else {
    message.append("err op\n");
    help();
    return message;
  }
  return message;
}

template <typename T>
void QueueApp<T>::toStr() {
  if (length() == 0) {
    message.append("empty");
  } else {
    message.append("( ");
    while (length() != 0)
      message.append(std::to_string(pop())).append(" ");
    message.append(")");
  }
}

#endif  //  MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
