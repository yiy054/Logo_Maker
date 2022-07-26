#ifndef SFMLSET_Iterator_H
#define SFMLSET_Iterator_H
#include "Node.h"

template <class T>
class Iterator {
 public:
  Node<T>* current;
 
 public:
  Iterator();
  Iterator(Node<T>* n);

  Iterator<T>& operator++() ;
  Iterator<T> operator++(int);

  Iterator<T>& operator--();
  Iterator<T> operator--(int);

  Iterator<T>& operator[](int index);

  Iterator<T> operator+=(int steps);
  Iterator<T> operator-=(int steps);
  Iterator<T> operator+(int steps);
  Iterator<T> operator-(int steps);

  
  bool isNull();

  T& operator*() const;

  template <class S>
  friend bool operator==(const Iterator<S>& LHS, const Iterator<S>& RHS);

  template <class S>
  friend bool operator!=(const Iterator<S>& LHS, const Iterator<S>& RHS);
};

#include "Iterator.cpp"
#endif  // Iterator_H_