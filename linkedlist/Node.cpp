//
// Created by phuoc on 24/04/2021.
//
#include "Node.h"

template <class T>
Node<T>::Node(T val){
    next = nullptr;
    this->val = val;
}

template<class T>
bool Node<T>::operator==(const Node &rhs) const {
    return val == rhs.val;
}

template<class T>
bool Node<T>::operator!=(const Node &rhs) const {
    return rhs != *this;
}

