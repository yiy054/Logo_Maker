//
// Created by yi yao on 3/17/21.
//

#include "MyClass.h"
#include <SFML/Graphics.hpp>

void MyClass::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_ball, states);
}


void MyClass::bounce(sf::RenderWindow& window){
    if (m_ball.getPosition().x + m_ball.getGlobalBounds().width >= window.getSize().x) {
        x = -1;
    }
    if (m_ball.getPosition().y + m_ball.getGlobalBounds().width > window.getSize().y) {
        y = -1;
    }
    if (m_ball.getPosition().y < 0) {
        y = 1;
    }
    if (m_ball.getPosition().x <= 0) {
        x = 1;
    }
    m_ball.move(x,y);
}

MyClass::MyClass(int num, int angle) {
    m_ball = sf::CircleShape(num,angle);
    x = y = 1;

}
