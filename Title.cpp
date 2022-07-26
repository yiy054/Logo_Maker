
#ifndef SFMLSET_TITLE_CPP
#define SFMLSET_TITLE_CPP
#include "Title.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


void Title::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(title,states);
    window.draw(Remaind,states);
}

#endif