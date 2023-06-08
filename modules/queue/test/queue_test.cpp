// Copyright 2023 Sudomoykin Andrey

#include "include/queue.h"

#include <gtest/gtest.h>

TEST(Queue, can_push) {
  Queue<int> queue;
  ASSERT_NO_THROW(queue.push(2));
}

TEST(Queue, can_pop) {
  Queue<int> queue;
  queue.push(1);
  EXPECT_EQ(1, queue.pop());
}

TEST(Queue, cant_pop_if_empty) {
  Queue<int> queue;
  ASSERT_ANY_THROW(queue.pop());
}

TEST(Queue, can_get_lenght) {
  Queue<int> queue;
  queue.push(1);
  queue.push(2);
  EXPECT_EQ(2, queue.lenght());
}
