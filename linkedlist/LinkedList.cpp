//
// Created by phuoc on 24/04/2021.
//

#include "iostream"
#include "LinkedList.h"
#include "Node.cpp"

using namespace std;

template<class T>
LinkedList<T>::LinkedList() {
    current = head = nullptr;
}

template<class T>
void LinkedList<T>::add(T val) {
    auto *node = new Node<T>(val);
    if (head == NULL) {
        head = node;
        current = head;
        return;
    }
    current->next = node;
    current = current->next;
}

template<class T>
void LinkedList<T>::print() {
    current = head;
    std::cout << "[ " << endl;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
        cout << ";" << endl;
    }
    cout << "]" << endl;
}

template<class T>
T LinkedList<T>::showMid() {
    Node<T> *slowPointer = head;
    Node<T> *fastPointer = head;
    if (head == NULL) {
        cout << "List is empty";
        return nullptr;
    } else {
        while (fastPointer != NULL && fastPointer->next != NULL) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        cout << "middle element is:" << slowPointer->val;
    }
    return slowPointer->val;
}

template<class T>
T LinkedList<T>::getIndex(int index) {
    int pointerPosition = 0;
    Node<T> *pointer = head;

    if (head == NULL) {
        cout << "List is empty";
    } else {
        pointerPosition++;
        while (pointerPosition < index) {
            pointer = pointer->next;
            pointerPosition++;
        }
    }
    return pointer->val;
}

template<class T>
bool LinkedList<T>::has(T node) {

    if (head == NULL) {
        cout << "List is empty";
    } else {
        Node<T> *pointer = head;
        T goal = pointer->val;
        while (pointer != NULL) {
            if (node.operator==(goal)) {
                return true;
            }
            else{
                if(pointer->next != NULL){
                    pointer = pointer->next;
                    goal = pointer->val;
                }
                else {
                    break;
                }
            }
        }
    }
    return false;
}

template<class T>
int LinkedList<T>::getPositionOf(T criteria) {

    int position = 0;
    if (head == NULL) {
        cout << "List is empty";
    } else {
        position++;
        Node<T> *pointer = head;
        T goal = pointer->val;
        while (pointer != NULL) {
            if (goal.operator==(criteria)) {
                break;
            }
            position++;
            pointer = pointer->next;
            goal = pointer->val;
        }
    }
    return position;
}

template<class T>
void LinkedList<T>::deleteFirst() {
    if (head == NULL) {
        cout << "List empty";
    } else {
        Node<T> *pointer = head;
        head = head->next;
        free(pointer);
    }
}

template<class T>
void LinkedList<T>::deletePosition(int position) {
    Node<T> *temporary;
    Node<T> *previous;
    temporary = head;
    for (int i = 1; i < position; i++) {
        previous = temporary;
        temporary = temporary->next;
    }
    previous->next = temporary->next;
}

template<class T>
void LinkedList<T>::deleteItem(T item) {
    deletePosition(getPositionOf(item));
}

template<class T>
void LinkedList<T>::update(T oldNode, T newNode) {
    int position = 0;
    if (head == NULL) {
        printf("Linked List not initialized");
        return;
    }
    current = head;
    while (current != NULL) {
        position++;
        if (current->val == oldNode) {
            current->val = newNode;
            return;
        }
        current = current->next;
    }
    printf("%d does not exist in the list\n", oldNode);
}

template<class T>
int LinkedList<T>::size() {
    int size = 0;

    if(head==NULL) {
        printf("List size : %d ", size);
        return size;
    }

    current = head;
    size = 1;
    while(current->next!=NULL) {
        current = current->next;
        size++;
    }
    return size;
}

template<class T>
void LinkedList<T>::swap(T value1, T value2) {
    T temp = value1;
    value1 = value2;
    value2 = temp;
    update(value1, value2);
    update(value2, value1);
}