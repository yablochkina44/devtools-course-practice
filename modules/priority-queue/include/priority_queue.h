// Copyright 2023 Zorin Oleg

#ifndef MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
#define MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_

#include <list>
#include <algorithm>
#include <stdexcept>

template<class T>
class PriorityQueue {
  std::list<T> data;
 public:
  PriorityQueue();
  PriorityQueue(const PriorityQueue &other);
  PriorityQueue &operator=(const PriorityQueue &other);
  ~PriorityQueue();
  void put(const T &value);
  const T &top() const;
  void pop();
  T get();
  bool empty() const;
  size_t size() const;
  void clear();
};

#endif  // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
