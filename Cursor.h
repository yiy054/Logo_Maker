

#ifndef SFMLSET_CURSOR_H
#define SFMLSET_CURSOR_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

class Cursor : public sf::Transformable, public sf::Drawable{
    private:
        sf::RectangleShape cursor;
        sf::Clock clock;
        int blink = 500;
        sf::Time time;
        int x;
    public:
        Cursor();
        void SetSize(float size);
        void SetPosition(sf::Vector2f Position);
        virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
        void update(sf::Vector2f position);
};

#endif //CURSOR_H