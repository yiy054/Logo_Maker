
#include "State.h"

map<State::ObjectState, bool> State::states;

sf::Font State::font;
bool State::loadFont = false;

State::State(){
    for(int i = static_cast<int>(APPEAR); i < static_cast<int>(LASTSTATE); i++){
        states[static_cast<ObjectState>(i)] = false;
    }
        
}
bool State::isStateEnabled(ObjectState state){
    return states[state];
}


void State::setStateEnable(ObjectState state, bool set){
    states[state] = set;
}