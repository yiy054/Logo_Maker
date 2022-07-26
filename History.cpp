#include "History.h"

Stacks<SnapShot> History::stack;


void History::pushHistory(const SnapShot& snapshot){
    stack.push(snapshot);
}

SnapShot History::topHistory(){
    if(stack.empty()){
        SnapShot temp("");
        return temp;
    }
    return stack.top();
}

void History::popHistory(){
    stack.pop();
}
