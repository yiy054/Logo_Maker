#ifndef SFMLSET_SNAPSHOT_H
#define SFMLSET_SNAPSHOT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;

#include "Stacks.h"

class SnapShot{
private:
    string list;
public:
    SnapShot();
    SnapShot(string text);
    void snapShot(string text);
    string getSnapshot() const;
    void setString(string other);
};
#endif