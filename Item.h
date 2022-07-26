
#ifndef SFMLSET_ITEM_H
#define SFMLSET_ITEM_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Fonts.h"
using namespace std;

class Item: public sf::Transformable, public sf::Drawable{
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Vector2f size;
    // sf::Font font;
public:
    int FontLoc;
    Item(/* args */);
    void String(sf::String s);
    
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const{
        window.draw(box,states);   
        window.draw(text,states);
    }
//SETTING  
    void Position(float x, float y);
    void Position(sf::Vector2f position);
    
    void BoxSetSize();
    void BoxSetSize(sf::Vector2f size);
    
    void SetSize();
    void SetSize(int n);
    
    void SetColor(sf::Color color);
    void SetFontLoc(int n);
    
//RETURN DATA
    sf::String GetString()const {return text.getString();}
    string Getstring()const {string s = text.getString(); return s;}
    sf::FloatRect getGlobalBounds() const {return box.getGlobalBounds();}
    float GetPositiony() {return box.getPosition().y;}
    sf::Color GetFillColor() { return box.getFillColor(); }
    sf::Vector2f GetPosition() const {return box.getPosition();}

};

#endif