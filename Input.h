
#ifndef SFMLSET_INPUT_H
#define SFMLSET_INPUT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

// #include "Stacks.h"
// #include "EventHandler.h"
// #include "Cursor.h"
// #include "Stacks.h"
#include "Typing.h"
#include "Title.h"
#include "Cursor.h"
#include "Box.h"
#include "Slider.h"
#include "Item.h"
// #include "SnapShot.h"
// #include "Menu.h"
#include "DropDown.h"
#include "ColorPix.h"

class Input: public sf::Transformable, public sf::Drawable{
    private:
//Text input box
    // sf::Text title;
    Title title;
    Cursor cursor;
    Typing typing;
    Box box;
    sf::Font font;
    sf::Vector2f position;
    char texting;
//Board text and shadow
    Typing Board;
    Typing shadow;
// BackGround Set
    sf::RectangleShape BackGround;
    sf::Color BGColor;
    sf::Color white = sf::Color::White;
//DropDown 
//fonts set
    DropDown BoardFont;
//All Slider set
    Slider size;
    Slider ShadowX;
    Slider ShadowY;
    Slider TextX;
    Slider TextY;
    Slider ShadowCapacity;
    Slider TextCapacity;
    Slider BGCapacity;
    Slider SkewX;
    Slider SkewY;
//Color Set
    Slider ColorBox;
    Slider BGColorBox;
    Item Rainbow;
    Item Shin;
    //  size;
    //  ShadowX;
    //  ShadowY;
    //  TextX;
    //  TextY;
    //  ShadowCapacity;
    //  TextCapacity;
    //  BGCapacity;
    //  Skew;
    ColorPix BoardColorPix;
    ColorPix BGColorPix;

    // string OpenFileLoc;
    sf::RenderTexture texture;

    public:
        Input(){
            // font.loadFromFile("OpenSans-Bold.ttf");
            // text.setFont(font);
            // text.setFillColor(sf::Color::Black);
            // text.setCharacterSize(50);
            // text.setStyle(sf::Text::Bold);
            // text.setPosition(300.f, 250.f);
            // Board.SetPosition({0,0});
            // Board.SetSize(500);
            
            white.a = 0;
            // shadow.SetFillColor(white);
            // shadow.setStyle(sf::Text::Bold);
            // shadow.SetSize(500);
            // shadow.setPosition({0,2000});
            // shadow.setScale(sf::Vector2f(6.38f, -5.f));
            Board.SetPosition({0,100});
            shadow.SetPosition({0,150});

            BackGround.setFillColor(white);
            BackGround.setSize({2000,1050});
            BackGround.setPosition({0,100});

            //Slide: (float max, string data, sf::Vector2f position, int initial)
            

            SkewX.SUMset(1000, "SkewX", {10,1210},250);
            SkewY.SUMset(1000, "SkewY", {1500,1210},750);

            ShadowY.SUMset(1000, "Shaow-Y", {10,1300},500);
            TextY.SUMset(1000, "Text-Y", {10,1400},250);
            TextX.SUMset(1900, "Text-X", {10,1500},1000);
            ShadowX.SUMset(1900, "Shadow-X", {10,1600},1000);
            
            // x, y, name Slider
            ColorBox.ListSet(2100,50, "Text Color:");
            BGColorBox.ListSet(2100,350, "BackGround Color:");
            //position, size ColorPix Class
            BoardColorPix.InitialSet({2100,100}, 200);
            BGColorPix.InitialSet({2500,100}, 200);          
            //RainBow color
            Rainbow.String("Rainbow Color");
            Rainbow.SetSize(40);
            Rainbow.BoxSetSize();
            Rainbow.Position({2100,450});          
            //Shining Color  
            Shin.String("Blink");
            Shin.SetSize(40);
            Shin.BoxSetSize();
            Shin.Position({2500,450});

            //Font Click  DropDown 
            vector<string> vector{"BEATNEY", "HARRYP", "OPENSANS", "PUMKIN", "WINTER"};
            BoardFont.SetTitle("Font");
            BoardFont.SetVec(vector);
            BoardFont.SetSize(40);
            BoardFont.SetPosition(2100,550);
            
            size.SUMset(400,"Font Size", {2100,750}, 100);
            TextCapacity.SUMset(100, "Text Capcity", {2100,850}, 10);
            ShadowCapacity.SUMset(100, "Shadow Capacity", {2100,950}, 10);
            BGCapacity.SUMset(100, "BackGround Capcity", {2100,1050}, 0);

            texture.create(2000, 1050);
        }

        void FileOpen(string Loc);
        void SetPosition(sf::Vector2f position);
        void SetSize(int size);
        void SetFont();
        void clean();

        list<sf::Text> getText();
        // sf::Color ColorReturn(int ColorPix);
        // float ColorReturnR(int ColorPix);
        // float ColorReturnG(int ColorPix);
        // float ColorReturnB(int ColorPix);

        void update();
        virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
        void addEventHandler(sf::RenderWindow& window, sf::Event event);
};

#endif