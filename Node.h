//
// Created by yi yao on 3/18/21.
//

#ifndef SFMLSET_NODE_H
#define SFMLSET_NODE_H

template< class T>
class Node {
public:
    Node<T>* next;
    Node<T>* prev;
    T data;
};


#endif //LINKEDLIST_NODE_H