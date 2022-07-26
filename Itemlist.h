#ifndef SFMLSET_ITEMLIST_H
#define SFMLSET_ITEMLIST_H
#include <iostream>

#include "Item.h"
// #include "LinkedList.h"
#include <list>
#include "MouseEvent.h"
#include "State.h"

class Itemlist: public sf::Transformable, public sf::Drawable{
private:
    /* data */
    list<Item> list;
    int size;
    string chose;
    float y;
    bool keep;
    int clickFont;
public:
    Itemlist(/* args */);
    Itemlist(vector<string> vector);

    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
// inset Set Funtion
    void Insert(sf::String i, int n, float width);
    void SetPosition(float x, float y);
    void SetSize(int n);

//Return Data;
    string GetClicked();
    int GetClickFont();
    string GetClickedByLoc(int n);
};

#endif


