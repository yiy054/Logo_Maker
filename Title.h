
#ifndef SFMLSET_TITLE_H
#define SFMLSET_TITLE_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Title: public sf::Transformable, public sf::Drawable{
private:
    sf::Text title;
    sf::Font font;
    sf::Text Remaind;
 public:
    Title(){
        font.loadFromFile("OpenSans-Bold.ttf");
        title.setString("Input:");
        title.setFont(font);
        title.setCharacterSize(20);
        title.setStyle(sf::Text::Bold);
        title.setPosition(100.f, 1500.f);
        Remaind.setFont(font);
        Remaind.setCharacterSize(20);
        Remaind.setStyle(sf::Text::Bold);
        Remaind.setPosition(100.f, 1500.f);
        Remaind.setFillColor(sf::Color::Red);
    }
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void tooMuchletter(sf::String s){
        Remaind.setString(s);
    }
    void SetPosition(sf::Vector2f position){
        title.setPosition(position);
        Remaind.setPosition(position);
    }
    void SetSize(int size){
        title.setCharacterSize(size);
    }
    sf::FloatRect GetLocalBound(){
        return title.getGlobalBounds();
    }
};

#endif