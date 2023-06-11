// Copyright 2023 Bykova Aleksandra

#include <gtest/gtest.h>
#include "include/DHeap.h"

TEST(test_dheap, can_call_constructor_with_default_param) {
  // Assert
  ASSERT_NO_THROW(DHeap());
}

TEST(test_dheap, can_call_constructor_with_input_param) {
  // Assert
  ASSERT_NO_THROW(DHeap(15, 6));
}

TEST(test_dheap, dary_larger_than_capacity) {
  // Assert
  ASSERT_NO_THROW(DHeap(5, 20));
}

TEST(test_dheap, can_create_heap_with_wrong_dary) {
  // Assert
  ASSERT_ANY_THROW(DHeap(3, -2));
}

TEST(test_dheap, can_create_heap_with_wrong_capacity) {
  // Assert
  ASSERT_ANY_THROW(DHeap(-5, 2));
}

TEST(test_dheap, empty_test) {
  // Arrange & Act
  DHeap hp;
  // Assert
  ASSERT_TRUE(hp.isEmpty());
}

TEST(test_dheap, not_empty_test) {
  // Arrange & Act
  DHeap hp;
  hp.insert(1);
  // Assert
  ASSERT_FALSE(hp.isEmpty());
}

TEST(test_dheap, full_test) {
  // Arrange & Act
  DHeap hp;
  hp.insert(1);

  // Assert
  ASSERT_FALSE(hp.isFull());
}

TEST(test_dheap, not_full_test) {
  // Arrange & Act
  DHeap hp;

  // Assert
  ASSERT_FALSE(hp.isFull());
}

TEST(test_dheap, insert_test) {
  // Arrange & Act
  DHeap hp;
  // Assert
  ASSERT_NO_THROW(hp.insert(0));
}

TEST(test_dheap, insert_multiply_values_test) {
  // Arrange & Act
  DHeap hp;
  for (int i = -4; i < 0; i++) hp.insert(i);
  // Assert
  ASSERT_NO_THROW(hp.insert(5));
}

TEST(test_dheap, extract_min_test) {
  // Arrange & Act
  DHeap hp;
  for (int i = 4; i > 0; i--) hp.insert(i);
  hp.insert(-5);
  // Assert
  ASSERT_EQ(-5, hp.extractMin());
}

TEST(test_dheap, extract_min_with_equal_values_test) {
  // Arrange & Act
  DHeap hp;
  for (int i = 4; i > 0; i--) hp.insert(1);
  // Assert
  ASSERT_EQ(1, hp.extractMin());
}

TEST(test_dheap, copy_constructor_equality_test) {
  // Arrange & Act
  DHeap hp(4, 3);
  DHeap cpyhp(hp);
  // Assert
  while (!hp.isEmpty()) {
    ASSERT_EQ(hp.extractMin(), cpyhp.extractMin());
  }
}

TEST(test_dheap, extract_decreased_value_test) {
  // Arrange & Act
  DHeap hp;
  for (int i = 10; i > 0; i--) hp.insert(i);
  hp.decreaseValue(5, -5);
  // Assert
    ASSERT_EQ(-5, hp.extractMin());
}

TEST(test_dheap, copy_constructor_test) {
  // Arrange & Act
  DHeap hp(4, 3);
  // Assert
  ASSERT_NO_THROW(DHeap a(hp));
}

TEST(test_dheap, throw_empty_test) {
  // Arrange & Act
  DHeap hp;

  // Assert
  ASSERT_ANY_THROW(hp.extractMin());
}

TEST(DHeapTest, IsEmpty) {
  DHeap heap(5, 2);

  EXPECT_TRUE(heap.isEmpty());

  heap.insert(1);
  EXPECT_FALSE(heap.isEmpty());

  heap.extractMin();
  EXPECT_TRUE(heap.isEmpty());
}

TEST(DHeapTest, IsFull) {
  DHeap heap(100, 2);

  for (int i = 0; i < 100; i++) {
    heap.insert(i);
}

  EXPECT_FALSE(heap.isFull());
}
