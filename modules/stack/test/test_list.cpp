// Copyright 2023 Kandrin Alexey

#include <gtest/gtest.h>

#include "include/list.h"

TEST(Kandrin_Alexey_ListTest, Can_create_list) {
    // Arrange & act & assert
    ASSERT_NO_THROW(List<int>());
}

TEST(Kandrin_Alexey_ListTest, Can_copy_empty_list) {
    // Arrange
    List<int> list;

    // Act
    List<int> copyList(list);

    // Assert
    ASSERT_EQ(list, copyList);
}

TEST(Kandrin_Alexey_ListTest, Can_copy_list_with_one_element) {
    // Arrange
    List<int> list;
    list.push_back(1);

    // Act
    List<int> copyList(list);

    // Assert
    ASSERT_EQ(list, copyList);
}

TEST(Kandrin_Alexey_ListTest, Can_copy_list_with_two_elements) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    // Act
    List<int> copyList(list);

    // Assert
    ASSERT_EQ(list, copyList);
}

TEST(Kandrin_Alexey_ListTest, Can_move_empty_list) {
    // Arrange
    List<int> list;

    // Act
    List<int> moveList = std::move(list);

    // Assert
    ASSERT_EQ(List<int>(), list);
    ASSERT_EQ(List<int>(), moveList);
}

TEST(Kandrin_Alexey_ListTest, Can_move_list_with_one_element) {
    // Arrange
    List<int> list;
    list.push_back(1);

    List<int> expectedList(list);

    // Act
    List<int> moveList = std::move(list);

    // Assert
    ASSERT_EQ(List<int>(), list);
    ASSERT_EQ(expectedList, moveList);
}

TEST(Kandrin_Alexey_ListTest, Can_move_list_with_two_elements) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    List<int> expectedList(list);

    // Act
    List<int> moveList = std::move(list);

    // Assert
    ASSERT_EQ(List<int>(), list);
    ASSERT_EQ(expectedList, moveList);
}


TEST(Kandrin_Alexey_ListTest, Can_copy_assign_empty_list) {
    // Arrange
    List<int> list;
    List<int> copyList;

    // Act
    copyList = list;

    // Assert
    ASSERT_EQ(list, copyList);
}

TEST(Kandrin_Alexey_ListTest, Can_copy_assign_list_with_one_element) {
    // Arrange
    List<int> list;
    list.push_back(1);

    List<int> copyList;

    // Act
    copyList = list;

    // Assert
    ASSERT_EQ(list, copyList);
}

TEST(Kandrin_Alexey_ListTest, Can_copy_assign_list_with_two_elements) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    List<int> copyList;

    // Act
    copyList = list;

    // Assert
    ASSERT_EQ(list, copyList);
}

TEST(Kandrin_Alexey_ListTest, Can_move_assign_empty_list) {
    // Arrange
    List<int> list;
    List<int> moveList;

    // Act
    moveList = std::move(list);

    // Assert
    ASSERT_EQ(List<int>(), list);
    ASSERT_EQ(List<int>(), moveList);
}

TEST(Kandrin_Alexey_ListTest, Can_move_assign_list_with_one_element) {
    // Arrange
    List<int> list;
    list.push_back(1);

    List<int> expectedList(list);
    List<int> moveList;

    // Act
    moveList = std::move(list);

    // Assert
    ASSERT_EQ(List<int>(), list);
    ASSERT_EQ(expectedList, moveList);
}

TEST(Kandrin_Alexey_ListTest, Can_move_assign_list_with_two_elements) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    List<int> expectedList(list);
    List<int> moveList;

    // Act
    moveList = std::move(list);

    // Assert
    ASSERT_EQ(List<int>(), list);
    ASSERT_EQ(expectedList, moveList);
}

TEST(Kandrin_Alexey_ListTest, Copied_list_has_own_memory) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    // Act
    List<int> copyList(list);

    // Assert
    ASSERT_NE(&list.front(), &copyList.front());
    ASSERT_NE(&list.back(), &copyList.back());
}

TEST(Kandrin_Alexey_ListTest, Moved_list_captures_nodes) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    auto firstPtr = &list.front();
    auto lastPtr = &list.back();

    // Act
    List<int> moveList(std::move(list));

    // Assert
    ASSERT_EQ(firstPtr, &moveList.front());
    ASSERT_EQ(lastPtr, &moveList.back());
}

TEST(Kandrin_Alexey_ListTest, Copied_list_by_assign_has_own_memory) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    List<int> copyList;

    // Act
    copyList = list;

    // Assert
    ASSERT_NE(&list.front(), &copyList.front());
    ASSERT_NE(&list.back(), &copyList.back());
}

TEST(Kandrin_Alexey_ListTest, Moved_list_by_assign_captures_nodes) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    auto firstPtr = &list.front();
    auto lastPtr = &list.back();

    List<int> moveList;

    // Act
    moveList = std::move(list);

    // Assert
    ASSERT_EQ(firstPtr, &moveList.front());
    ASSERT_EQ(lastPtr, &moveList.back());
}

TEST(Kandrin_Alexey_ListTest, Move_constructor_clear_argument) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    // Act
    List<int> moveList(std::move(list));

    // Assert
    ASSERT_TRUE(list.empty());
}

TEST(Kandrin_Alexey_ListTest, Move_assignment_clear_argument) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int> moveList;

    // Act
    moveList = std::move(list);

    // Assert
    ASSERT_TRUE(list.empty());
}

TEST(Kandrin_Alexey_ListTest, Copy_self_assignment_is_correct) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int> expectedList(list);

    // Act
    list = list;

    // Assert
    ASSERT_EQ(expectedList, list);
}

TEST(Kandrin_Alexey_ListTest, Move_self_assignment_is_correct) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int> expectedList(list);

    // Act
    list = std::move(list);

    // Assert
    ASSERT_EQ(expectedList, list);
}

TEST(Kandrin_Alexey_ListTest, Copy_assignment_returns_reference_to_this) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    List<int> copyList;

    // Act
    auto&& reference = (copyList = list);

    // Assert
    ASSERT_EQ(&copyList, &reference);
}

TEST(Kandrin_Alexey_ListTest, Move_assignment_returns_reference_to_this) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    List<int> moveList;

    // Act
    auto&& reference = (moveList = std::move(list));

    // Assert
    ASSERT_EQ(&moveList, &reference);
}

TEST(Kandrin_Alexey_ListTest, Push_back_changes_back_1) {
    // Arrange
    List<int> list;
    int value = 1;

    // Act
    list.push_back(value);

    // Assert
    ASSERT_EQ(value, list.back());
}

TEST(Kandrin_Alexey_ListTest, Push_back_changes_back_2) {
    // Arrange
    List<int> list;
    int value1 = 1;
    int value2 = 5;

    // Act
    list.push_back(value1);
    list.push_back(value2);

    // Assert
    ASSERT_EQ(value2, list.back());
}

TEST(Kandrin_Alexey_ListTest, Pop_back_changes_back) {
    // Arrange
    List<int> list;
    int value1 = 0;
    int value2 = 3;
    list.push_back(value1);
    list.push_back(value2);

    // Act
    list.pop_back();

    // Assert
    ASSERT_EQ(value1, list.back());
}

TEST(Kandrin_Alexey_ListTest, Push_back_changes_front_if_list_was_empty) {
    // Arrange
    List<int> list;
    int value1 = 0;

    // Act
    list.push_back(value1);

    // Assert
    ASSERT_EQ(value1, list.front());
}

TEST(Kandrin_Alexey_ListTest,
    Push_back_doesnt_change_front_if_list_wasnot_empty) {
    // Arrange
    List<int> list;
    int value1 = 0;
    int value2 = 3;
    list.push_back(value1);

    // Act
    list.push_back(value2);

    // Assert
    ASSERT_EQ(value1, list.front());
}

TEST(Kandrin_Alexey_ListTest, Push_back_changes_const_back_1) {
    // Arrange
    List<int> list;
    int value = 1;

    // Act
    list.push_back(value);

    // Assert
    ASSERT_EQ(value, const_cast<const List<int>&>(list).back());
}

TEST(Kandrin_Alexey_ListTest, Push_back_changes_const_back_2) {
    // Arrange
    List<int> list;
    int value1 = 1;
    int value2 = 5;

    // Act
    list.push_back(value1);
    list.push_back(value2);

    // Assert
    ASSERT_EQ(value2, const_cast<const List<int>&>(list).back());
}

TEST(Kandrin_Alexey_ListTest, Pop_back_changes_const_back) {
    // Arrange
    List<int> list;
    int value1 = 0;
    int value2 = 3;
    list.push_back(value1);
    list.push_back(value2);

    // Act
    list.pop_back();

    // Assert
    ASSERT_EQ(value1, const_cast<const List<int>&>(list).back());
}

TEST(Kandrin_Alexey_ListTest, Push_back_changes_const_front_if_list_was_empty) {
    // Arrange
    List<int> list;
    int value1 = 0;

    // Act
    list.push_back(value1);

    // Assert
    ASSERT_EQ(value1, const_cast<const List<int>&>(list).front());
}

TEST(Kandrin_Alexey_ListTest,
    Push_back_doesnt_change_const_front_if_list_wasnot_empty) {
    // Arrange
    List<int> list;
    int value1 = 0;
    int value2 = 3;
    list.push_back(value1);

    // Act
    list.push_back(value2);

    // Assert
    ASSERT_EQ(value1, const_cast<const List<int>&>(list).front());
}

TEST(Kandrin_Alexey_ListTest, Default_constructor_gives_empty_list) {
    // Arrange & act
    List<int> list;

    // Assert
    ASSERT_TRUE(list.empty());
}

TEST(Kandrin_Alexey_ListTest, List_is_not_empty_after_push_back) {
    // Arrange
    List<int> list;

    // Act
    list.push_back(3);

    // Assert
    ASSERT_FALSE(list.empty());
}

TEST(Kandrin_Alexey_ListTest, List_is_not_empty_after_pop_back) {
    // Arrange
    List<int> list;
    list.push_back(3);
    list.push_back(4);

    // Act
    list.pop_back();

    // Assert
    ASSERT_FALSE(list.empty());
}

TEST(Kandrin_Alexey_ListTest, List_is_empty_after_pop_back) {
    // Arrange
    List<int> list;
    list.push_back(3);

    // Act
    list.pop_back();

    // Assert
    ASSERT_TRUE(list.empty());
}

TEST(Kandrin_Alexey_ListTest, Default_constructor_gives_zero_size_list) {
    // Arrange & act
    List<int> list;

    // Assert
    ASSERT_EQ(static_cast<size_t>(0), list.size());
}

TEST(Kandrin_Alexey_ListTest, Push_back_increments_list) {
    // Arrange
    List<int> list;
    size_t size = 0;

    // Act & asserts
    list.push_back(3);
    ++size;
    ASSERT_EQ(size, list.size());

    list.push_back(4);
    ++size;
    ASSERT_EQ(size, list.size());
}

TEST(Kandrin_Alexey_ListTest, Pop_back_decrements_list) {
    // Arrange
    List<int> list;
    list.push_back(3);
    list.push_back(4);
    size_t size = list.size();

    // Act & asserts
    list.pop_back();
    --size;
    ASSERT_EQ(size, list.size());

    list.pop_back();
    --size;
    ASSERT_EQ(size, list.size());
}

TEST(Kandrin_Alexey_ListTest, swap_list_swaps_memories) {
    // Arrange
    List<int> list1;
    list1.push_back(3);
    list1.push_back(4);
    auto list1FirstPtr = &list1.front();
    auto list1LastPtr = &list1.back();

    List<int> list2;
    list2.push_back(7);
    list2.push_back(129);
    list2.push_back(135);
    auto list2FirstPtr = &list2.front();
    auto list2LastPtr = &list2.back();

    // Act
    list1.swap(list2);

    ASSERT_EQ(list2FirstPtr, &list1.front());
    ASSERT_EQ(list2LastPtr, &list1.back());
    ASSERT_EQ(list1FirstPtr, &list2.front());
    ASSERT_EQ(list1LastPtr, &list2.back());
}

TEST(Kandrin_Alexey_ListTest, Comparison_for_empty_lists) {
    // Arrange
    List<int> list1, list2;

    // Act & asserts
    ASSERT_TRUE(list1 == list2);
    ASSERT_FALSE(list1 != list2);
}

TEST(Kandrin_Alexey_ListTest, Comparison_for_list_with_same_elements) {
    // Arrange
    List<int> list1;
    List<int> list2;
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
        list2.push_back(i);
    }

    // Act & asserts
    ASSERT_TRUE(list1 == list2);
    ASSERT_FALSE(list1 != list2);
}

TEST(Kandrin_Alexey_ListTest, Comparison_for_list_with_different_elements) {
    // Arrange
    List<int> list1;
    List<int> list2;
    for (int i = 0; i < 5; ++i) {
        list1.push_back(i);
        list2.push_back(i);
    }
    list1.push_back(6);
    list2.push_back(7);

    // Act & asserts
    ASSERT_FALSE(list1 == list2);
    ASSERT_TRUE(list1 != list2);
}

TEST(Kandrin_Alexey_ListTest, Front_throws_out_of_range) {
    // Arrange
    List<int> list;

    // Act & asserts
    ASSERT_THROW(list.front(), std::out_of_range);
}

TEST(Kandrin_Alexey_ListTest, Const_front_throws_out_of_range) {
    // Arrange
    List<int> list;

    // Act & asserts
    ASSERT_THROW(const_cast<const List<int>&>(list).front(), std::out_of_range);
}

TEST(Kandrin_Alexey_ListTest, Back_throws_out_of_range) {
    // Arrange
    List<int> list;

    // Act & asserts
    ASSERT_THROW(list.back(), std::out_of_range);
}

TEST(Kandrin_Alexey_ListTest, Const_back_throws_out_of_range) {
    // Arrange
    List<int> list;

    // Act & asserts
    ASSERT_THROW(const_cast<const List<int>&>(list).back(), std::out_of_range);
}

TEST(Kandrin_Alexey_ListTest, Pop_back_throws_out_of_range_if_list_is_empty) {
    // Arrange
    List<int> list;

    // Act & asserts
    ASSERT_THROW(list.pop_back(), std::out_of_range);
}

TEST(Kandrin_Alexey_ListTest, Clear_makes_list_empty) {
    // Arrange
    List<int> list;
    list.push_back(1);
    list.push_back(2);

    // Act
    list.clear();

    // Assert
    ASSERT_TRUE(list.empty());
}

TEST(Kandrin_Alexey_ListTest, Clear_with_empty_list_is_correct) {
    // Arrange
    List<int> list;

    // Act
    list.clear();

    // Assert
    ASSERT_TRUE(list.empty());
}
