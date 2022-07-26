#ifndef SFMLSET_OPENWINDOW_H
#define SFMLSET_OPENWINDOW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <dirent.h>
#include "FileTree.h"
#include "Image.h"
#include "State.h"

#include <filesystem>
using namespace std;
using namespace std::__fs::filesystem;

class OpenWindow: public sf::Transformable, public sf::Drawable
{
private:
    /* data */
    sf::RenderWindow popWin;
    sf::Color popWinColor = sf::Color(50, 50, 50);
    sf::Event popWinEvent{};
    bool open;
    bool tree;
    FileTree floder;
    Item input;

    string click;
    string loc;
public:
    // Default constructor
    OpenWindow();

    // While pop is Open
    void winOpen();
    void WindowSet();
    void initialClick(){click = "Null";}
    void PushTree(path str);
    string ReturnClick();

    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
};



#endif