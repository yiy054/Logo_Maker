
#ifndef SFMLSET_BOX_H
#define SFMLSET_BOX_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Box : public sf::Transformable, public sf::Drawable{

private:
    sf::Sprite sprite;
    sf::Texture texture;
public:
    Box(){
        texture.create(500,500);
        texture.loadFromFile("White.png"); 
        sprite.setTexture(texture);
        sprite.setPosition(500.f, 1500.f);
        sprite.setColor(sf::Color::White);
        sprite.setTextureRect(sf::IntRect(100, 100, 500, 100));
    }
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const{
        window.draw(sprite, states);
    }
    sf::FloatRect Size(){
        return sprite.getGlobalBounds();
    }
    void SetPosition(sf::Vector2f Position){
        sprite.setPosition(Position);
    }
    sf::Vector2f GetPosition(){return sprite.getPosition();}
    float getHeight(){return sprite.getLocalBounds().height;}

    void SetHeight(int height){sprite.setTextureRect(sf::IntRect(100, 100, 500, height));}

};
#endif