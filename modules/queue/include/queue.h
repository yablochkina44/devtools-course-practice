// Copyright 2023 Sudomoykin Andrey

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_H_

template <class T>
class Queue {
  struct node {
    T data;
    node* nextNode;
  };
  node* head;
  int size;

 public:
  Queue();
  ~Queue();
  void push(T e);
  T pop();
  int lenght();
};

template <typename T>
Queue<T>::Queue() {
  size = 0;
  head = nullptr;
}

template <typename T>
Queue<T>::~Queue() {
  node* temp;
  while (head != nullptr) {
    temp = head;
    head = head->nextNode;
    delete temp;
  }
}

template <typename T>
T Queue<T>::pop() {
  if (head == nullptr) {
    throw "exception";
  }

  node* temp = head;
  T data = head->data;
  head = head->nextNode;
  delete temp;
  size--;

  return data;
}

template <typename T>
void Queue<T>::push(T data) {
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
int Queue<T>::lenght() {
  return size;
}

#endif  //  MODULES_QUEUE_INCLUDE_QUEUE_H_
