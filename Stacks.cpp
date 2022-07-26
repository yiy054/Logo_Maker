#ifndef Stacks_CPP_
#define Stacks_CPP_
#include "Stacks.h"
#include <iostream>
using namespace std;

template <class T>
T Stacks<T>::pop(){
    T data = list.TAIL();
    list.RemoveTail();
    return data;
}

template <class T>
void Stacks<T>::push(T item){
    // cout << list << endl;
    list.insertAfter(item);
    // cout << list << endl;
}

template <class T>
bool Stacks<T>::empty(){
    if(list.Size() == 0)
        return true;
    else
        return false;
}

template <class T>
int Stacks<T>::size() {
    // cout << list.Size() << endl;
    return list.Size();
}

template <class T>
T Stacks<T>::top() const{
    return list.TAIL();
}

template <class T>
T& Stacks<T>::seek(size_type n) {
    // cout << "print" << endl;
    // cout << n << " "<< endl;
    return list.target(n);
}

template <class T>
T Stacks<T>::print(std::ostream &output){
    output << list << endl;
    return output;
}

template <class T>
T& Stacks<T>::operator*() const {
  // cout <<"work*"<< endl;
  return *this->data;
}

#endif