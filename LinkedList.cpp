//
// Created by yi yao on 3/18/21.
//
#ifndef SFMLSET_LINKEDLIST_CPP
#define SFMLSET_LINKEDLIST_CPP
#include "LinkedList.h"
#include <iostream>
using namespace std;

template<class T>
LinkedList<T>::LinkedList(){
    // cout << "constructor start" << endl;
    head = nullptr;
    tail = nullptr;
    // cout << "constructor end" << endl;
}

//template<class T>
//LinkedList<T>::LinkedList(const LinkedList<T>& list){
//    // cout << "start" << endl;
//    Node<T>* n = list.head;
//    Node<T>* New = new Node<T>;
//    New->data = n->data;
//    head = New;
//    while (n->next != nullptr){
//        insertAfter(n->next->data);
//        n = n->next;
//    }
//    // cout << "end" << endl;
//}

//template<class T>
//LinkedList<T>::~LinkedList<T>(){
//    //cout << "start  1" << endl;
//    Node <T> *n = head;
//    while (head != nullptr) {
//        head = head->next;
//        delete n;
//        n = head;
//    }
//    delete head;
//    //cout << "   start2" << endl;
//}

template<class T>
void LinkedList<T>::clear(const LinkedList& list){
    Node<T>* n = list.head;
    while (head != nullptr) {
        head = head->next;
        delete n;
        n = head;
    }
    delete head;
    size = 0;
}
//head
template< class T>
void LinkedList<T>::insertBefore(T data){
    if (head == nullptr||head->data == 0){
        Node<T>* n = new Node<T>;
        n->data = data;
        head = n;
        tail = n;
        size++;
        return;
    }
    Node<T>* n = new Node<T>;
    n->data = data;
    current = head;
    n->next = current;
    current->prev = n;
    head = n;
    head->prev = nullptr;
    size++;

}
//end
template< class T>
void LinkedList<T>::insertAfter(T data) {
    // cout << "insert start" << endl;
    if (head == nullptr||tail == nullptr){
        Node<T>* n = new Node<T>;
        n->data = data;
        n->next = nullptr;
        n->prev = nullptr;
        head = n;
        tail = n;
        size++;
        // cout << "insert end" << endl;
        return;
    }
    Node<T>* n = new Node<T>;
    n->data = data;
    n->prev = nullptr;
    n->next = nullptr;
    // current = tail;
    tail->next = n;
    n->prev = tail;
    tail = n;
    size++;
    // cout << "insert end" << endl;
}

//+
template< class T>
void LinkedList<T>::operator += (T data){
    Node<T>* n = new Node<T>;
    n->data = data;
    if (tail == nullptr){
        Node<T>* n = new Node<T>;
        n->data = data;
        head = n;
        tail = n;
        size++;
        return;
    }
    tail->next = n;
    n->prev = tail;
    tail = n;
    tail->next = nullptr;
    size++;
}


//insert
template< class T>
void LinkedList<T>::insertPrev (T data,T n){
    Node<T>* newNode= new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;
    size++;

    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node<T>* current = find(n);
        newNode->prev = current->prev;
        newNode->next = current;
        newNode->prev->next = newNode;
        current->prev = newNode;
    }
}

template< class T>
void LinkedList<T>::insertNext (T data,T n){
    Node<T>* newNode= new Node<T>;
    newNode->data = data;
    newNode->next = nullptr;
    size++;
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node<T>* current = find(n);
        newNode->next = current->next;
        newNode->prev = current;
        current->next = newNode;
    }
}
//find
template< class T>
Node<T>* LinkedList<T>::find(T data){
    Node<T>* current = head;
    while (current->data != data){
        current = current->next;
    }
    if(current->data == data){
        return current;
    } else{
        return 0;
    }
}
template< class T>
void LinkedList<T>::remove(T data){
    if(head == nullptr) return;
    if(head->data == data) {
        head = head->next;
        head->prev = nullptr;
        size--;
        return;
    }
    current = find(data);
    current->prev->next = current->next;
    size--;
    delete current;
}

template< class T>
T& LinkedList<T>::target(int n) const {
    Node<T>* current = head;
    int i = 0;
    while(current != nullptr && i != n)
    {
        current = current -> next;
        i++;
    }
    return current->data;
}


template< class T>
const char * LinkedList<T>::Empty(const LinkedList& list){
    if(list.head == nullptr||(list.head == 0 && list.head->next == nullptr))
        return "true";
    return "false";
}

template< class T>
int LinkedList<T>::Size(){
    // int n = 0;
    // Node<T>* current = head;
    // cout << "Size start" << endl;
    // while(current != nullptr){
    //     // n++;
    //     cout << n;
    //     current = current->next;
    //     n++;
    // }
    // cout << "Size End" << endl;
    return size;
}

template< class s>
std::ostream& operator << (std::ostream &output, const LinkedList<s>& list){
    Node<s>* n = list.head;
    while(n != nullptr){
        output << n->data << " ";
        n = n->next;
    }
    return output;
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::begin() const{
  return Iterator<T>(head);
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::end() const{
    // cout << "end call" << endl;
  return Iterator<T>(nullptr);
}

template <class T>
typename LinkedList<T>::iterator LinkedList<T>::Tail() const{
  return Iterator<T>(tail);
}

#endif