
#ifndef SFMLSET_ColorPix_H
#define SFMLSET_ColorPix_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
#include "MouseEvent.h"

class ColorPix: public sf::Transformable, public sf::Drawable{
private:
    /* data */
    sf::VertexArray Pix;
    float initialX;
    float initialY;
    int height;
    int width;
    float R ;
    float G ;
    float B ;
    float initialR;
    float initialG;
    float initialB;
    float Max, Min = 0;

    float Size;
    float doubleSize;

    float H, S, V;
    sf::CircleShape point;
    bool click;
    sf::Color ColorClick;
public:
    ColorPix(/* args */);
    void Insert(int h);
    void InitialSet(sf::Vector2f position, int size);
    float FindMax(float r, float g, float b);
    float FindMin(float r, float g, float b);
    float FindH(float r, float g, float b);
    void FindRGB(int H);

    void SetX(int n);
    void SetY(int n);

    sf::Color ReturnColor(){return ColorClick;}

//DRAW ADDEVENTHANDLE UPDATE;
    void update();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

};



#endif