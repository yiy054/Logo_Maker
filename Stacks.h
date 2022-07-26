#ifndef Stacks_H_
#define Stacks_H_

#include "LinkedList.h"


template <class T>
class Stacks {
    private:
        LinkedList<T> list;
        typedef size_t size_type;
    public:
        Stacks(){
            LinkedList<T> list;
        }
        Stacks(const LinkedList<T>& List){
            LinkedList<T> list(List);
        }
        Stacks& operator = (const Stacks& List){
            return *this;
        }
        T pop();
        void push(T item);
        bool empty();
        int size();
        T top() const;
        T& seek(size_type n);

        T print(std::ostream &output);
        T& operator*() const;

};

#include "Stacks.cpp"

#endif