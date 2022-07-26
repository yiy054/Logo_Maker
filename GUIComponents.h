#ifndef SFMLSET_GUICOMPONENTS_H
#define SFMLSET_GUICOMPONENTS_H

// #include "EventHandler.h"
#include "State.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;


class GUIComponents: public sf::Transformable, public sf::Drawable, public State/*, public EventHandler */{
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

};

#endif //MAIN_CPP_GUICOMPONENTS_H