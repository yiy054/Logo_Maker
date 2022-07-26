#ifndef SFMLSET_CURSOR_CPP
#define SFMLSET_CURSOR_CPP

#include "Cursor.h"

Cursor::Cursor(){
    cursor.setSize(sf::Vector2f(10.f, 50.f));
    cursor.setFillColor(sf::Color::Green);
    // cursor.setPosition(100.f, 280.f);
    x = 300;
    time = clock.getElapsedTime();
}


void Cursor::SetSize(float size){
    cursor.setSize({10.f, size});
}


void Cursor::update(sf::Vector2f position){
    cursor.setPosition(position);
    if(clock.getElapsedTime().asMilliseconds() > blink){
        cursor.setFillColor(sf::Color::White);
    }

    if(clock.getElapsedTime().asMilliseconds() > (blink * 2)){
        // cout << clock.getElapsedTime().asMilliseconds() << " " << endl;
        clock.restart();
        cursor.setFillColor(sf::Color::Green);
    }
}


void Cursor::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(cursor,states);
}

void Cursor::SetPosition(sf::Vector2f position){
    cursor.setPosition(position);
}
#endif