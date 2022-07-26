#ifndef SFMLSET_MENU_H
#define SFMLSET_MENU_H

// #include <iostream>
// #include <SFML/Graphics.hpp>
#include "Itemlist.h"
#include "Item.h"
#include "InputBox.h"
#include "History.h"
#include "GUIComponents.h"
using namespace std;

class Menu: public sf::Transformable, public sf::Drawable{
private:
    /* data */
    // Item i;
    Itemlist list;
    InputBox input;
    // SnapShot snap;
    float x, y;
    bool hid;
    sf::String MenuTitleHov;
    sf::String inputdata;
    string ClickItem;
    // string check;
public:
    Menu(/* args */);

    void itemSet(string data);
    void SetSize(int size);
    void itemlistSet(vector<string> vector);
    void SetPosition(float X, float Y);
    sf::String getMenu();
    sf::String getInputBox();
    sf::Vector2f GetPosition(){return input.GetPosition();}
    string ReturnClickItem(){return ClickItem;}
    void menuSet(sf::String m);

    void MenuSum(sf::String title, vector<string> vecList, int size, sf::Vector2f pos, float width);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    // SnapShot& getSnapShot();
    // void applySnapshot(const SnapShot& snapshot);
};


#endif