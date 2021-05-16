//
// Created by phuoc on 24/04/2021.
//

#ifndef TESTPROJECT_NODE_H
#define TESTPROJECT_NODE_H

template <class T>
class Node {
public:
    T val;
    Node* next;
    explicit Node(T val);

    bool operator==(const Node &rhs) const;

    bool operator!=(const Node &rhs) const;
};
#endif //TESTPROJECT_NODE_H
