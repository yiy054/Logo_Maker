//
// Created by yi yao on 3/18/21.
//

#ifndef SFMLSET_LINKEDLIST_H
#define SFMLSET_LINKEDLIST_H

#include "Node.h"
#include "Iterator.h"
#include <iostream>
using namespace std;


template< class T>
class LinkedList{
public:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* current;
    int size = 0;
    typedef Iterator<T> iterator;
public:
    LinkedList();
//    LinkedList(const LinkedList& list);

//    ~LinkedList();
    void clear(const LinkedList& list);
    void insertBefore(T data); // head
    void operator += (T data);//+
    void insertAfter(T data); //end
    void insertPrev (T data,T n);
    void insertNext (T data,T n);

    const char * Empty(const LinkedList& list);
    int Size();

    Node<T>* find(T data);
    void remove(T data);
    
    T& target(int n) const;

    void RemoveTail(){
        Node<T>* current = tail;
        tail = current->prev;
//        tail->next = nullptr;
        size--;
        delete current;
    }
    template<class s>
    friend std::ostream& operator << (std::ostream& output, const LinkedList<s>& list);

    T HEAD(){
        return head->data;
        }
    T TAIL() const{
        return tail->data;
        }
    
    Iterator<T> begin()const;
    Iterator<T> end()const;
    Iterator<T> Tail()const;

};

#include "LinkedList.cpp"
#endif //LINKEDLIST_H