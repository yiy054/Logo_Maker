#ifndef SFMLSET_MENUBAR_H
#define SFMLSET_MENUBAR_H

#include "Menu.h"
#include <list>
// #include "LinkedList.h"

#include "GUIComponents.h"

class MenuBar : public GUIComponents{
private:
    /* data */
    list<Menu> bar;
    // Menu menu;
    float x, y;
    string click;
    string menu;
public:
    MenuBar();

    void VecSet(vector<string> vector, sf::String title, float width);
    
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    string ReturnClick(){return click;}
};


#endif