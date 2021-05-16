//
// Created by phuoc on 24/04/2021.
//

#ifndef TESTPROJECT_LINKEDLIST_H
#define TESTPROJECT_LINKEDLIST_H

#include "iostream"
#include "Node.h"

template<class T>
class LinkedList {
private:
    Node<T> *current, *head;
public:
    LinkedList();

    void add(T val);

    void print();

    void deleteFirst();

    T showMid();

    T getIndex(int index);

    bool has(T node);

    int getPositionOf(T criteria);

    void deletePosition(int position);

    void deleteItem(T item);

    void update(T oldNode, T newNode);

    int size();

    void swap(T value1, T value2);
};


#endif //TESTPROJECT_LINKEDLIST_H
