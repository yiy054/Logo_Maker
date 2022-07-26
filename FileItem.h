#ifndef SFMLSET_FILEITEM_H
#define SFMLSET_FILEITEM_H

#include <list>
#include <iostream>
#include "LinkedList.h"
#include "Item.h"
#include "Image.h"
#include "MouseEvent.h"
#include "State.h"


class FileItem : public Item{
public:
    //Constructors
    FileItem();
    // FileItem():
    FileItem(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position);
    
    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the size of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    void setPosition(const sf::Vector2f pos) ;
    //uses an enum to change the icon to a folder or file
    // void setIcon(Image::image icon);
    sf::Color GetFillColor();
    bool stateChange();
    string ClickData();
    string Getstring();



private:
    //this is the folder or file icon
    Item item;
    sf::Sprite Icon;
    float padding = 5;
    bool state;
    string data;
};

#endif