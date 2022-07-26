#ifndef SFMLSET_EVENTHANDLER_H
#define SFMLSET_EVENTHANDLER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Stacks.h"
using namespace std;

class EventHandler{

// private:
    // Stacks<string> s;
public:
    // Stacks<string> s;
    // sf::Text text;
    // sf::String texting;
    // sf::Font font;
// The window receives input from the user (An event occurred)
    // EventCheck(){
    //     font.loadFromFile("OpenSans-Bold.ttf");
    //     text.setFont(font);
    //     text.setFillColor(sf::Color::White);
    //     text.setCharacterSize(100);
    //     text.setStyle(sf::Text::Bold);
    //     text.setPosition(300.f, 150.f);
    // }
    // void setInput();
// The window responds to the event (Event handler)
    // void EventCheck(sf::Event event);
// Often, the Event Handler, handles the event by changing the State of the object

// The window makes necessary changes to the object, based off of how the event was handled (update)
// The window clears the screen
    // void clean();
// The window draws the objects
    // void draw(sf::RenderTarget& window, sf::RenderStates states)const;
// The window displays the objects
    // void display();

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

};

#include "EventHandler.cpp"

#endif //EVENTHANDLER_H