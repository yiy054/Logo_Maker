#ifndef SFMLSET_LOGO_H
#define SFMLSET_LOGO_H

// #include "Typing.h"
#include "Input.h"
#include "Slider.h"
#include "Typing.h"
#include "Board.h"
#include "MenuBar.h"
#include "OpenWindow.h"


class Logo: public sf::Transformable, public sf::Drawable{
private:
    /* data */
    Input input;
    // Board board;
    MenuBar Bar;
    OpenWindow newWindow;
    string OpenFileName;

    // sf::Texture texture;
public:
    Logo();
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
};



#endif