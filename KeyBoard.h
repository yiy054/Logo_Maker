#ifndef SFMLSET_KEYBOARD_H
#define SFMLSET_KEYBOARD_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "Typing.h"
#include "History.h"

class KeyBoard {
public:
    KeyBoard();
    void addEventHandler(sf::RenderWindow& window, sf::Event event, Typing& typing);
    void update();
    virtual void draw(sf::RenderTarget& window)const;

private:
};


#endif //MAIN_CPP_KEYBOARD_H