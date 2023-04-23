// Copyright 2023 Kandrin Alexey

#include "include/list.h"

template<class T>
List<T>::List() = default;


template<class T>
List<T>::List(const List& other)
    : List() {
    Node** currentNode = &m_firstNode;
    Node* prevNode = nullptr;
    for (auto currentOtherNode = other.m_firstNode; currentOtherNode != nullptr;
        currentOtherNode = currentOtherNode->next) {
        *currentNode = new Node{ currentOtherNode->value, prevNode, nullptr };
        prevNode = *currentNode;
        currentNode = &(*currentNode)->next;
    }

    m_lastNode = prevNode;
}


template<class T>
List<T>::List(List&& other) noexcept {
    capture(&other);
}


template<class T>
List<T>& List<T>::operator=(const List& other) {
    if (this != &other)
        *this = List(other);  // copy constructor + move assignment
    return *this;
}


template<class T>
List<T>& List<T>::operator=(List&& other) noexcept {
    if (this != &other)
        capture(&other);
    return *this;
}


template<class T>
List<T>::~List() {
    clear();
}


template<class T>
T& List<T>::front() {
    return const_cast<T&>(const_cast<const List&>(*this).front());
}


template<class T>
const T& List<T>::front() const {
    if (m_firstNode == nullptr)
        throw std::out_of_range("Cant front() because list is empty");
    return m_firstNode->value;
}


template<class T>
T& List<T>::back() {
    return const_cast<T&>(const_cast<const List&>(*this).back());
}


template<class T>
const T& List<T>::back() const {
    if (m_lastNode == nullptr)
        throw std::out_of_range("Cant back() because list is empty");
    return m_lastNode->value;
}


template<class T>
bool List<T>::empty() const {
    return size() == 0;
}


template<class T>
size_t List<T>::size() const {
    size_t result = 0;
    for (auto currentNode = m_firstNode; currentNode != nullptr;
        currentNode = currentNode->next)
        ++result;

    return result;
}


template<class T>
void List<T>::push_back(const T& value) {
    Node* newNode = new Node{ value, m_lastNode, nullptr };

    if (m_firstNode == nullptr) {
        m_firstNode = m_lastNode = newNode;
    } else {
        m_lastNode->next = newNode;
        m_lastNode = newNode;
    }
}


template<class T>
void List<T>::pop_back() {
    if (m_lastNode == nullptr)
        throw std::out_of_range("Cant pop_back() because list is empty");

    Node* lastNode = m_lastNode;

    m_lastNode = m_lastNode->prev;
    if (m_lastNode == nullptr)
        m_firstNode = nullptr;
    else
        m_lastNode->next = nullptr;

    delete lastNode;
}


template<class T>
void List<T>::clear() {
    for (auto currentNode = m_firstNode; currentNode != nullptr;) {
        auto nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    m_firstNode = nullptr;
    m_lastNode = nullptr;
}


template<class T>
void List<T>::swap(List& other) {
    std::swap(m_firstNode, other.m_firstNode);
    std::swap(m_lastNode, other.m_lastNode);
}


template<class T>
void List<T>::capture(List* other) {
    swap(*other);
    List().swap(*other);
}


template<class T>
bool List<T>::operator==(const List& other) const {
    auto node = m_firstNode, otherNode = other.m_firstNode;
    while (node != nullptr && otherNode != nullptr) {
        if (node->value != otherNode->value)
            return false;

        node = node->next;
        otherNode = otherNode->next;
    }

    return node == otherNode;  // both equal nullptr
}


template<class T>
bool List<T>::operator!=(const List& other) const {
    return !(*this == other);
}


template class List<int>;  // explicit template instantiation
