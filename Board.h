#ifndef SFMLSET_Board_H
#define SFMLSET_Board_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include <list>
#include "Fonts.h"
#include "OneFont.h"

class Board
{
private:
    /* data */
    list<sf::Text> list;
public:
    Board();
    void push(sf::Text t);

    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
};





#endif