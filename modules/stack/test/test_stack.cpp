// Copyright 2023 Kandrin Alexey

#include <gtest/gtest.h>

#include "include/stack.h"

TEST(Kandrin_Alexey_StackTest, Cant_get_top_element_from_empty_stack) {
    // Arrange
    Stack<int> stack;

    // Act & assert
    ASSERT_ANY_THROW(stack.top());
}

TEST(Kandrin_Alexey_StackTest, Cant_get_const_top_element_from_empty_stack) {
    // Arrange
    Stack<int> stack;

    // Act & assert
    ASSERT_ANY_THROW(const_cast<const Stack<int> &>(stack).top());
}

TEST(Kandrin_Alexey_StackTest, Can_get_top_element_from_non_empty_stack) {
    // Arrange
    Stack<int> stack;
    int value = 7;
    stack.push(value);

    // Act & assert
    ASSERT_EQ(value, stack.top());
}

TEST(Kandrin_Alexey_StackTest, Can_get_const_top_element_from_non_empty_stack) {
    // Arrange
    Stack<int> stack;
    int value = 7;
    stack.push(value);

    // Act & assert
    ASSERT_EQ(value, const_cast<const Stack<int> &>(stack).top());
}

TEST(Kandrin_Alexey_StackTest, Top_element_returns_last_pushed_value) {
    // Arrange
    Stack<int> stack;

    // Act & assert
    for (int i = 0; i < 5; ++i) {
        stack.push(i);
        ASSERT_EQ(i, stack.top());
    }
}

TEST(Kandrin_Alexey_StackTest, Const_top_element_returns_last_pushed_value) {
    // Arrange
    Stack<int> stack;

    // Act & assert
    for (int i = 0; i < 5; ++i) {
        stack.push(i);
        ASSERT_EQ(i, const_cast<const Stack<int> &>(stack).top());
    }
}

TEST(Kandrin_Alexey_StackTest, Default_constructor_gives_empty_stack) {
    // Arrange
    Stack<int> stack;

    // Act & assert
    ASSERT_TRUE(stack.empty());
}

TEST(Kandrin_Alexey_StackTest, Stack_is_not_empty_after_push) {
    // Arrange
    Stack<int> stack;

    // Act
    stack.push(1);

    // Assert
    ASSERT_FALSE(stack.empty());
}

TEST(Kandrin_Alexey_StackTest, Stack_is_empty_after_pop) {
    // Arrange
    Stack<int> stack;
    stack.push(1);

    // Act
    stack.pop();

    // Assert
    ASSERT_TRUE(stack.empty());
}

TEST(Kandrin_Alexey_StackTest, Stack_is_not_empty_after_pop) {
    // Arrange
    Stack<int> stack;
    stack.push(1);
    stack.push(2);

    // Act
    stack.pop();

    // Assert
    ASSERT_FALSE(stack.empty());
}

TEST(Kandrin_Alexey_StackTest, Clear_makes_stack_empty) {
    // Arrange
    Stack<int> stack;
    stack.push(1);
    stack.push(2);

    // Act
    stack.clear();

    // Assert
    ASSERT_TRUE(stack.empty());
}

TEST(Kandrin_Alexey_StackTest, Clear_with_empty_stack_is_correct) {
    // Arrange
    Stack<int> stack;

    // Act
    stack.clear();

    // Assert
    ASSERT_TRUE(stack.empty());
}

TEST(Kandrin_Alexey_StackTest, Default_constructor_gives_zero_size_stack) {
    // Arrange & act
    Stack<int> stack;

    // Assert
    ASSERT_EQ(static_cast<size_t>(0), stack.size());
}

TEST(Kandrin_Alexey_StackTest, Push_back_increments_stack_size) {
    // Arrange
    Stack<int> stack;
    size_t size = 0;

    // Act & asserts
    stack.push(3);
    ++size;
    ASSERT_EQ(size, stack.size());

    stack.push(4);
    ++size;
    ASSERT_EQ(size, stack.size());
}

TEST(Kandrin_Alexey_StackTest, Pop_back_decrements_stack_size) {
    // Arrange
    Stack<int> stack;
    stack.push(3);
    stack.push(4);
    size_t size = stack.size();

    // Act & asserts
    stack.pop();
    --size;
    ASSERT_EQ(size, stack.size());

    stack.pop();
    --size;
    ASSERT_EQ(size, stack.size());
}
