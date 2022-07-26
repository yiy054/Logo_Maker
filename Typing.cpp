//
// Created by yi yao on 3/18/21.
//
#ifndef SFMLSET_TYPING_CPP
#define SFMLSET_TYPING_CPP
#include "Typing.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AddEVentHandle Updata Window DRAW  -------------------------------

void Typing::update(){
    // shot(text.getString());
    // cout << "Start Updata";
    // cout << list.Size() << endl;
    // size = list.size();
    // Recursion(0);
//Shing Color
    // int n = 1;
    // for(auto iter = list.begin(); iter != list.end(); iter++){
    //     (*iter).setFillColor(Shine());
    //     n++;
    //     if(n > 6){
    //         n = 1;
    //     }
    // }
//
    // cout << "typing Updata" << endl;
    // cout << "finish Updata" << endl;
}

void Typing::draw(sf::RenderTarget& window, sf::RenderStates states) const{
   
    // for(int i = 0; i < size; i++){ 
    //     // cout << "Start Draw" << endl;
    //     window.draw(list[i]);
    // }
    for(auto iter = list.cbegin(); iter != list.cend(); iter++){
        // std::string s;
        // s = (*iter).getString();
        // cout << s << endl;
        window.draw(*iter);
    }
    // cout << "Draw end" << endl;
}

void Typing::push(char s){
    text.setString(sf::String(s));
    // position.x += text.getLocalBounds().width;
    // position.y = position.y;
    text.setPosition(position);
    // list.insertAfter(text);
    list.push_back(text);
    // text.setFillColor(sf::Color::Yellow);
    cout << "finish input ------" << s << endl;
    size = list.size();
    // if(isdigit(s)){
    //     // text.setFillColor(sf::Color::Red);
    //     position.x += text.getLocalBounds().width;
    // }else if(isalpha(s)){
    //     // text.setFillColor(sf::Color::Yellow);
    //     // position.x += 50.f;
    //     position.x += text.getLocalBounds().width;
    // }else{
    //     // text.setFillColor(sf::Color::Green);
    //     position.x += text.getLocalBounds().width;
    // }        
    position.x += (text.getLocalBounds().width + 5.f);

}

void Typing::pop(){
    list.pop_back(); 
    if(list.empty()){
        position = initial;
        size = 0;
    }else{
        size = list.size();
        position = (list.back()).getPosition();
        position.x += (list.back()).getLocalBounds().width;    
    }
}

// void Typing::Recursion(int n){
//     // cout << "Recursion used";
//     if(n < size){
//         if((n+3)< size){
//             if(list.target(n).getString() == "i")
//                 if(list.target(n+1).getString() == "n")
//                     if(list.target(n+2).getString() == "t"){
//                         list.target(n).setFillColor(sf::Color::Blue);
//                         list.target(n+1).setFillColor(sf::Color::Blue);
//                         list.target(n+2).setFillColor(sf::Color::Blue);
//                         Recursion(n+3);
//                     }        
//         }
//         if((n+4)< size){
//             if(list.target(n).getString() == "c")
//                 if(list.target(n+1).getString() == "h")
//                     if(list.target(n+2).getString() == "a")
//                         if(list.target(n+3).getString() == "r"){
//                             list.target(n).setFillColor(sf::Color::Blue);
//                             list.target(n+1).setFillColor(sf::Color::Blue);
//                             list.target(n+2).setFillColor(sf::Color::Blue);
//                             list.target(n+3).setFillColor(sf::Color::Blue);
//                             Recursion(n+4);
//                     }        
//         }
//         if((n+5)< size){
//             if(list.target(n).getString() == "d")
//                 if(list.target(n+1).getString() == "o")
//                     if(list.target(n+2).getString() == "u")
//                         if(list.target(n+3).getString() == "b")
//                             if(list.target(n+4).getString() == "l")
//                                 if(list.target(n+5).getString() == "e"){
//                                     list.target(n).setFillColor(sf::Color::Blue);
//                                     list.target(n+1).setFillColor(sf::Color::Blue);
//                                     list.target(n+2).setFillColor(sf::Color::Blue);
//                                     list.target(n+3).setFillColor(sf::Color::Blue);
//                                     list.target(n+4).setFillColor(sf::Color::Blue);
//                                     list.target(n+5).setFillColor(sf::Color::Blue);
//                                     Recursion(n+6);
//                                 }
//         }
//         if((n+4)< size){
//             if(list.target(n).getString() == "f")
//                 if(list.target(n+1).getString() == "l")
//                     if(list.target(n+2).getString() == "o")
//                         if(list.target(n+3).getString() == "a")
//                             if(list.target(n+4).getString() == "t"){
//                                     list.target(n).setFillColor(sf::Color::Blue);
//                                     list.target(n+1).setFillColor(sf::Color::Blue);
//                                     list.target(n+2).setFillColor(sf::Color::Blue);
//                                     list.target(n+3).setFillColor(sf::Color::Blue);
//                                     list.target(n+4).setFillColor(sf::Color::Blue);
//                                     Recursion(n+5);
//                                 }
//         }
//         Recursion(n+1);
//     }
    
// }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// All Initial Setting ---------------------------------------
void Typing::SetPosition(sf::Vector2f Position){
        position = Position;
        initial = Position;
        text.setPosition(Position);
}


sf::Color Typing::Shine(){
    int color = rand()% 6;
    switch (color)
    {
    case 1: return sf::Color::Blue;
    case 2: return sf::Color::Green;
    case 3: return sf::Color::Yellow;
    case 4: return sf::Color::Red;
    case 5: return sf::Color::Cyan;
    case 6: return sf::Color::Magenta;
    default: return sf::Color::White;
        break;
    }
}
sf::Color Typing::Rainbow(int n){
    switch (n)
    {
    case 1: return sf::Color::Blue;
    case 2: return sf::Color::Green;
    case 3: return sf::Color::Yellow;
    case 4: return sf::Color::Red;
    case 5: return sf::Color::Cyan;
    case 6: return sf::Color::Magenta;
    default: return sf::Color::White;
        break;
    }
}


void Typing::SetFillColor(sf::Color color){
    for(auto iter = list.begin(); iter != list.end(); iter++){
        (*iter).setFillColor(color);
    }
}

void Typing::SetScale(sf::Vector2f vector){
    for(auto iter = list.begin(); iter != list.end(); iter++){
        (*iter).setScale(vector);
    }
}

void Typing::SetSUM(int size, int TextX, int TextY, int TextCapacity, int FontOption,sf::Color c){
    Fonts::fonts TextFont;
    switch (FontOption)
    {
    case 1:  TextFont = Fonts::BEATNEY;break;
    case 2:  TextFont = Fonts::HARRYP;break;
    case 3:  TextFont = Fonts::OPENSANS;break;
    case 4:  TextFont = Fonts::PUMKIN;break;
    case 5:  TextFont = Fonts::WINTER;break;
    default: TextFont = Fonts::OPENSANS;
        break;
    }

    int RainBowN = 1;
    auto iter = list.begin();
    sf::Vector2f position = initial;
    // cout << initial.x << ", " << initial.y << endl;
    position.x += TextX;
    position.y += TextY;
    // cout << "Position  + " << position.x << ", " << position.y << endl;
    // sf::Vector2f test = (*iter).getPosition();
    // cout << "Iter Position " << test.x << ", " << test.y << endl;
    float lastPositionY = position.y;
    
    for(; iter != list.end(); iter++){
        // cout <<(*iter).getPosition().y << " " << lastPositionY+100.f << endl;
        if((*iter).getPosition().y == lastPositionY+100.f){
            position.y = (*iter).getPosition().y + TextY;
            position.x = (*iter).getPosition().x + TextX;
            cout << "REchange the position to new line" << endl;
        }
        lastPositionY = (*iter).getPosition().y;
        (*iter).setCharacterSize(size);

        (*iter).setPosition(position);
        (*iter).setFont(Fonts::getFont(TextFont));
        if(State::isStateEnabled(State::RAINBOW)){
            (*iter).setFillColor(Rainbow(RainBowN));
            RainBowN++;
            if(RainBowN > 6){
                RainBowN = 1;
            }
        }else if(State::isStateEnabled(State::SHIN)){
            (*iter).setFillColor(Shine());
        }else {
            (*iter).setFillColor(c);
        }
        sf::Color color = (*iter).getFillColor();
        color.a = TextCapacity*2.5;
        (*iter).setFillColor(color);
        position.x += ((*iter).getLocalBounds().width + 5.f);
        // cout << "SETSUM -------------" << endl
        //     << "Font Option: " << FontOption << endl
        //     << "Size : " << size << endl
        //     << "Position: " << position.x << " " << position.y << endl
        //     << "Text Capacity: " << TextCapacity/2 
        //     << endl;
        // 100 2000 1000 50
    }
}

void Typing::ShadowSetSum(int size, int ShadowX, int ShadowY,int ShadowCapacity, int SkewY, int FontOption, int SkewX){
    auto iter = list.begin();
    sf::Vector2f position = initial;
    position.x += ShadowX;
    position.y += ShadowY;

    Fonts::fonts TextFont;
    switch (FontOption)
    {
    case 1:  TextFont = Fonts::BEATNEY;break;
    case 2:  TextFont = Fonts::HARRYP;break;
    case 3:  TextFont = Fonts::OPENSANS;break;
    case 4:  TextFont = Fonts::PUMKIN;break;
    case 5:  TextFont = Fonts::WINTER;break;
    default: TextFont = Fonts::OPENSANS;
        break;
    }

    for(; iter != list.end(); iter++){
        (*iter).setFont(Fonts::getFont(TextFont));
        (*iter).setCharacterSize(size);
        (*iter).setPosition(position);

        sf::Color color = sf::Color::White;
        color.a = ShadowCapacity*2.5;
        (*iter).setFillColor(color);
        // (*iter).setScale(sf::Vector2f((*iter).getLocalBounds().width, -(Skew/50)));

        float x = ((SkewX-500)/500.00);
        float y = ((SkewY-500)/500.00);
        (*iter).setScale(x, y);           

        position.x += ((*iter).getLocalBounds().width + 5.f);
        // cout << "Shadow SETSUM -------------" << endl
        //     << "Size : " << size << endl
        //     << "Position: " << position.x << " " << position.y << endl
        //     << "Text Capacity: " << ShadowCapacity/2 << endl
        //     << "Shew : " << n << endl;
    }
}

void Typing::Clean(){
    list.clear();
    position = initial;
}


#endif
