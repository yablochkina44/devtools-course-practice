// Copyright 2023 Kandrin Alexey

#ifndef MODULES_STACK_INCLUDE_LIST_H_
#define MODULES_STACK_INCLUDE_LIST_H_

#include <stdexcept>
#include <utility>

//! @addtogroup list
//! @{

/**
 * @brief A template class representing a data structure called a two-linked list
 *
 * Two-linked list is a linear collection of data elements whose order is not given
 * by their physical placement in memory. Instead, each element points to the next
 * and to the previous.
 */
template <class T>
class List {
 public:
    /**
     * @brief Default constructor
     */
    List();

    /**
     * @brief Copy constructor
     * @param[in] other List to copy from
     */
    List(const List& other);

    /**
     * @brief Move constructor
     * @param[in] other List to copy from
     */
    List(List&& other) noexcept;


    /**
     * @brief Copy assignment operator
     * @param[in] other List to copy from
     * @return Current object with changed values
     */
    List& operator=(const List& other);


    /**
     * @brief Move assignment operator
     * @param[in] other List to move from
     * @return Current object with changed values
     */
    List& operator=(List&& other) noexcept;


    /**
     * @brief Destructor
     */
    ~List();


    /**
     * @brief Getter for the first element
     * @return Non-constant reference to the first element
     */
    T& front();

    /**
     * @brief Getter for the first element
     * @return Constant reference to the first element
     */
    const T& front() const;


    /**
     * @brief Getter for the last element
     * @return Non-constant reference to the last element
     */
    T& back();


    /**
     * @brief Getter for the last element
     * @return Constant reference to the last element
     */
    const T& back() const;


    /**
     * @brief Determining if the list is empty
     * @return True if list is empty; otherwise False.
     */
    bool empty() const;


    /**
     * @brief Get the number of elements on the list.
     * @return Number of elements on the list
     */
    size_t size() const;


    /**
     * @brief Add an element to the end of the list
     * @param[in] value Element to be added
     */
    void push_back(const T& value);


    /**
     * @brief Remove element from the end of the list
     */
    void pop_back();


    /**
     * @brief Remove all elements from the list
     */
    void clear();


    /**
     * @brief Swap lists
     * @param other List to be swapped
     */
    void swap(List& other);


    /**
     * @brief Comparison operator
     * @param[in] other List to compare
     * @return True if the elements of the lists are pairwise equal; otherwise False.
     */
    bool operator==(const List& other) const;


    /**
     * @brief Comparison operator
     * @param[in] other List to compare
     * @return False if the elements of the lists are pairwise equal; otherwise True.
     */
    bool operator!=(const List& other) const;

 private:
    /**
     * @brief Capture data from list. The captured list is then cleared
     * @param other The list from which the data is captured
     */
    void capture(List* other);

 private:
    struct Node {
        T value;
        Node* prev;
        Node* next;

        Node(const T& value, Node* prev, Node* next)
            : value(value), prev(prev), next(next) {}
    };

    Node* m_firstNode = nullptr;
    Node* m_lastNode = nullptr;
};

//! @}

#endif  // MODULES_STACK_INCLUDE_LIST_H_
