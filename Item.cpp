
#include "Item.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// All Initial Setting ---------------------------------------// ------------------------------------------------------------

Item::Item(/* args */){
    // font.loadFromFile("OpenSans-Bold.ttf");
    // text.setFont(Fonts::getFont(Fonts::OPENSANS));
    // size = sf::Vector2f(text.getGlobalBounds().width,text.getGlobalBounds().height);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setCharacterSize(50);
    FontLoc = 2;
    text.setFont(Fonts::getFont(Fonts::OPENSANS));
    box.setFillColor(sf::Color::Black);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(5.0f);
    // box.setSize(size);
    // text.setString("data");
}

void Item::String(sf::String s){
    text.setString(s);
    string data = s;
}

void Item::Position(float x, float y){
    box.setPosition(x,y);
    text.setPosition(x,y);
}

void Item::Position(sf::Vector2f position){
    Position(position.x,position.y);
}

void Item::BoxSetSize(sf::Vector2f size){
    box.setSize(size);
}

void Item::BoxSetSize(){
    sf::Vector2f s(text.getGlobalBounds().width+25.f,text.getGlobalBounds().height+25.f);
    box.setSize(s);
    sf::Vector2f pText(box.getPosition().x+25.f,
                    box.getPosition().y+25.f);
    text.setPosition(pText);
}
void Item::SetSize(int n){
    text.setCharacterSize(n);
    SetSize();
}

void Item::SetSize(){
    size = sf::Vector2f(250,text.getGlobalBounds().height+50.f);
    box.setFillColor(sf::Color::Transparent);
    box.setSize(size);
}

void Item::SetColor(sf::Color color){
    box.setFillColor(color);
    // text.setFillColor(color);
}
void Item::SetFontLoc(int n){
    FontLoc = n;
    switch (FontLoc)
    {
    case 1:  text.setFont(Fonts::getFont(Fonts::BEATNEY));
            break;
    case 2:  text.setFont(Fonts::getFont(Fonts::HARRYP));
            break;
    case 3:  text.setFont(Fonts::getFont(Fonts::OPENSANS));
            break;
    case 4:  text.setFont(Fonts::getFont(Fonts::PUMKIN));
            break;
    case 5:  text.setFont(Fonts::getFont(Fonts::WINTER));
            break;
    default: cout << "Default" << endl;
            text.setFont(Fonts::getFont(Fonts::OPENSANS));
        break;
    }
    // cout << "Font Set Sucessful " << FontLoc << endl;
}

//////////////////////////////////////////////////////////////////
//Return ALL data  -------------------------------






