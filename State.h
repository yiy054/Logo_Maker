#ifndef SFMLSET_STATE_H
#define SFMLSET_STATE_H

// enum State{
//     HIDDEN,
//     NONHIDDEN,
//     HIGHLIGHTED,
//     DISABLED,
//     BITNKON,
//     BINKOFF,
//     LASTSTATE
// };

#include <map>
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>

class State{
public:
    enum ObjectState{
        APPEAR, CLICKED, LASTSTATE, BAR, KEEP, RAINBOW, SHIN, OPEN, NEW, QUIT, CLOSE, SAVE, IMAGE
    };
    State();
    void operator=(const State& other);
    static bool isStateEnabled(ObjectState state);
    static void setStateEnable(ObjectState state, bool set);
    static sf::Font font;
    static bool loadFont;
    
private:
    static map<ObjectState, bool> states;
};



#endif //STATE_H