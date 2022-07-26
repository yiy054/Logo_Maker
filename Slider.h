
#ifndef SFMLSET_SLIDER_H
#define SFMLSET_SLIDER_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>
using namespace std;
#include "Fonts.h"
#include "OneFont.h"
#include "MouseEvent.h"
#include "list"

class Slider: public sf::Transformable, public sf::Drawable{
private:
    /* data */
    sf::Text label;
    sf::RectangleShape line;
    sf::CircleShape point;
    sf::Text num;
    int size;
    bool click;
    float r, g, b;
    bool RegularLine;
    bool Colorline;

    list<sf::VertexArray> colorBox;
    sf::Vector2f initialColor;
    sf::Vector2f MaxColorPos;
    
    // bool clicked;
    // sf::RectangleShape box;
public:
    Slider();
    int getData();
    // float GetR(){return ;}

    void LineSet();
    void ListSet(float X, float Y, string s);
    void setSize(float n);
    void setLabel(string data);
    void setPosition(sf::Vector2f position);
    void SetByTxt(int n);

    void SUMset(float n, string data, sf::Vector2f position, int s);

    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
};

#endif