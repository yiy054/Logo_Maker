
#ifndef SFMLSET_ITERATOR_CPP
#define SFMLSET_ITERATOR_CPP
#include "Iterator.h"
#include <iostream>
using namespace std;

template <class T>
Iterator<T>::Iterator() {
  current = nullptr;
}

template <class T>
Iterator<T>::Iterator(Node<T>* n) {
  current = n;
}

template <class T>
Iterator<T>& Iterator<T>::operator++()  {
  // cout <<"work++";
  current = current->next;
  // cout << "end"<< endl;
  return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator++(int) {
  // cout <<"work++";
  Iterator<T>* temporary = *this;
  current = current->next;
  // cout << "end"<< endl;
  return temporary;
}

template <class T>
Iterator<T>& Iterator<T>::operator--() {
  // cout <<"work--";
  current = current->prev;
  // cout << "end"<< endl;
  return *this;
}

template <class T>
Iterator<T> Iterator<T>::operator--(int) {
  // cout <<"work--";
  Iterator<T>* temporary = *this;
  current = current->prev;
  // cout << "end"<< endl;
  return current;
}

template <class T>
T& Iterator<T>::operator*() const {
  // cout <<"work*"<< endl;
  return current->data;
}

template <class S>
bool operator==(const Iterator<S>& LHS, const Iterator<S>& RHS) {
  // cout <<"work"<< endl;
  return LHS.current == RHS.current;
}

template <class S>
bool operator!=(const Iterator<S>& LHS, const Iterator<S>& RHS) {
  return LHS.current != RHS.current;
}

template <class T>
Iterator<T>& Iterator<T>::operator[](int index){
  return (current+index)->data();
}
template <class T>
Iterator<T> Iterator<T>::operator+=(int steps){
  int step = 0;
  while(step < steps){
    current = current->next;
    step++;
  }
  return current;
}

template <class T>
Iterator<T> Iterator<T>::operator-=(int steps){
  int step = 0;
  while(step < steps){
    current = current->prev;
    step++;
  }
  return current;
}

template <class T>
Iterator<T> Iterator<T>::operator+(int steps){
  Iterator<T> temp(current);
  temp += steps;
  return temp;
}

template <class T>
Iterator<T> Iterator<T>::operator-(int steps){
  Iterator<T> temp(current);
  temp -= steps;
  return temp;

}

template <class T>
bool Iterator<T>::isNull(){
  if(!current)
    return true;
  else
    return false;

}
#endif  // Iterator_CPP_