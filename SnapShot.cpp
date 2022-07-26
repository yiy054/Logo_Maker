#ifndef SFMLSET_SNAPSHOT_CPP
#define SFMLSET_SNAPSHOT_CPP

#include "SnapShot.h"

SnapShot::SnapShot(){
    list = "";
}

SnapShot::SnapShot(string text){
    list = text;
}

void SnapShot::snapShot(string text){
    list = text;
}

string SnapShot::getSnapshot() const{
    return list;
}

void SnapShot::setString(std::string other){
    list = other;

}

#endif