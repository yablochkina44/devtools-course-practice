// Copyright 2023 Kandrin Alexey

#ifndef MODULES_STACK_INCLUDE_STACK_H_
#define MODULES_STACK_INCLUDE_STACK_H_

#include "include/list.h"

//! @addtogroup stack
//! @{

/**
 * @brief A template class representing a data structure called a stack
 *
 * Stack is an abstract data type that serves as a collection of elements, with two main operations:
 *  1) Push, which adds an element to the collection, and
 *  2) Pop, which removes the most recently added element that was not yet removed.
 */
template <class T, class Container = List<T>>
class Stack {
 public:
    /**
     * @brief Getter for the most recently added element
     * @return Non-constant reference to the most recently added element
     */
    T& top();


    /**
     * @brief Getter for the most recently added element
     * @return Constant reference to the most recently added element
     */
    const T& top() const;


    /**
     * @brief Determining if the stack is empty
     * @return True if stack is empty; otherwise False.
     */
    bool empty() const;


    /**
     * @brief Add an element to the top of the stack
     * @param[in] value Element to be added
     */
    void push(const T& value);


    /**
     * @brief Remove element from top of stack
     */
    void pop();

    /**
     * @brief Remove all elements from the stack
     */
    void clear();

    /**
     * @brief Get size of the stack
     * @return Size of the stack
     */
    size_t size() const;

 private:
    Container m_data;
};

//! @}

#endif  // MODULES_STACK_INCLUDE_STACK_H_
