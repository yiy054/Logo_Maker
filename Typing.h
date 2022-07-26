//
// Created by yi yao on 3/18/21.
//

#ifndef SFMLSET_TYPING_H
#define SFMLSET_TYPING_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
using namespace std;
// #include "EventHandler.h"
// #include <map>
// #include "ObjectState.h"
// #include "SnapShot.h"
// #include "LinkedList.h"
// #include "Stacks.h"
// #include "Word.h"
#include <list>
#include "Iterator.h"
#include "Fonts.h"
#include "OneFont.h"
#include "State.h"

class Typing : public sf::Transformable, public sf::Drawable {
public:
    Typing(){
        // font.loadFromFile("OpenSans-Bold.ttf");
        // text.setFont(OneFont::getFont());
        text.setFont(Fonts::getFont(Fonts::OPENSANS));
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(100);
        text.setStyle(sf::Text::Bold);
        position.x = 100.f;
        position.y = 100.f;
        text.setPosition(position);
        size = list.size();
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();

    int width(){return position.x;};
    int height(){return position.y;};

    sf::Vector2f GetPosition (){return position;};

    void pop();
    void push(char s);
    void Enter(){position.y += 100.f; position.x = initial.x;}
    void Recursion(int n);
    void Clean();

    void SetPosition(sf::Vector2f position);
    void SetSize(int size){text.setCharacterSize(size);}
    sf::Color Rainbow(int n);
    sf::Color Shine();

    void SetSUM(int size,  int TextX, int TextY,  int TextCapacity, int FontOption, sf::Color c);
    void ShadowSetSum(int size, int ShadowX, int ShadowY,int ShadowCapacity, int SkewY, int FontOption, int SkewX);
    void SetFillColor(sf::Color color);
    void SetScale(sf::Vector2f vector);
public:
    sf::Text text;
    // sf::String texting;
    sf::Font font;
    sf::Vector2f position;

    // SnapShot shot;
    // EventHandler data;
    list<sf::Text> list;
    int size;
    sf::Vector2f initial;
    // vector<sf::Text> string;
    // Iterator<sf::Text> iter1;
    // String data;
};

#endif //SFMLSET_TYPING_H
