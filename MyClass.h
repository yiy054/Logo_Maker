//
// Created by yi yao on 3/17/21.
//

#ifndef SFMLSET_MYCLASS_H
#define SFMLSET_MYCLASS_H
#include <SFML/Graphics.hpp>

class MyClass: public sf::Transformable, public sf::Drawable {
public:
    sf::CircleShape m_ball;
    MyClass(){
        m_ball.setRadius(40.f);
        m_ball.setFillColor(sf::Color::White);
        m_ball.setPosition(1,0);
        x = y = 1;
    }
    MyClass(int num, int angle);

    int x,y;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void bounce(sf::RenderWindow& window);

};


#endif //SFMLSET_MYCLASS_H
