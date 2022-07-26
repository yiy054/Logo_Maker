
#ifndef SFMLSET_INPUT_CPP
#define SFMLSET_INPUT_CPP
#include "Input.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AddEVentHandle Updata Window DRAW  -------------------------------

void Input::addEventHandler(sf::RenderWindow& window, sf::Event event){
    // typing.addEventHandler(window,event);
    // !TyperSnapshot t = getSnapShot();
    // texts.addEvenrHandle(window, event);
    if (event.type == sf::Event::TextEntered)
    {
        // !TyperSnapshot t = getSnapShot();
        // std::string s = text.getString().toAnsiString();
        if(event.text.unicode == '\b'){
            typing.pop();
            Board.pop();
            shadow.pop();
        }
        else if(event.text.unicode == '\n'){
            typing.Enter();
            Board.Enter();
            shadow.Enter();
        }
        else if (event.text.unicode < 128 ){
            texting = static_cast<char>(event.text.unicode);
            typing.push(texting);
            Board.push(texting);
            shadow.push(texting);
            // cout << "Text creat sucessful -----" << texting << endl;
        }
    }

    if(MouseEvents<Item>::mouseClicked(Rainbow, window)){
        if(State::isStateEnabled(State::RAINBOW)){
            State::setStateEnable(State::RAINBOW, false);
            // cout << "State::RainBow" << endl;
        }
        else
            State::setStateEnable(State::RAINBOW, true);
    }

    if(MouseEvents<Item>::mouseClicked(Shin, window)){
        if(State::isStateEnabled(State::SHIN)){
            State::setStateEnable(State::SHIN, false);
            // cout << "Shin Click"<< endl;
        }
        else
            State::setStateEnable(State::SHIN, true);
    }
        // History::pushHistory(t);
    BoardFont.addEventHandler(window,event);
    
    size.addEventHandler(window,event);
    ShadowX.addEventHandler(window,event);
    ShadowY.addEventHandler(window,event);
    TextX.addEventHandler(window,event);
    TextY.addEventHandler(window,event);

    ShadowCapacity.addEventHandler(window,event);
    TextCapacity.addEventHandler(window,event);
    BGCapacity.addEventHandler(window,event);
    SkewX.addEventHandler(window,event);
    SkewY.addEventHandler(window,event);
    ColorBox.addEventHandler(window,event);
    BGColorBox.addEventHandler(window,event);

    BoardColorPix.addEventHandler(window,event);
    BGColorPix.addEventHandler(window,event);
}

void Input::update(){
    // cout << "Start Updata" << endl;
    // typing.update();
    // shadow.update();
    Board.update();
    BoardFont.update();
    position = typing.GetPosition();
    // position.x = typing.width() + 50.f;
    // position.y = box.GetPosition().y;
    position.y += 5.f;
    // cout << "Cursor update" << position.x << ",  " << position.y<< endl;
    cursor.update(position);
    // cursor.setPosition(position);
//Text out Out box
    // if(typing.GetPosition().x > (box.Size().width) || typing.GetPosition().y > (box.Size().height+150))
    // {
    //     title.tooMuchletter("Out of Box");
    // }else{
    //     title.tooMuchletter("");
    // }
//
    // BGColor = ColorReturn(BGColorBox.getData());
    BoardColorPix.Insert(ColorBox.getData());
    BGColorPix.Insert(BGColorBox.getData());

    Board.SetSUM(size.getData(), TextX.getData(), TextY.getData(), TextCapacity.getData(),BoardFont.GetClick(), BoardColorPix.ReturnColor());
    shadow.ShadowSetSum(size.getData(), ShadowX.getData(), ShadowY.getData(),ShadowCapacity.getData(), SkewY.getData(),BoardFont.GetClick(), SkewX.getData());
    
    BackGround.setFillColor(BGColorPix.ReturnColor());
    BGColor = BackGround.getFillColor();
    BGColor.a = BGCapacity.getData()*2.5;
    BackGround.setFillColor(BGColor);

    // size, ShadowX; ShadowY, TextX, TextY, ShadowCapacity, TextCapacity, BGCapacity, Skew)
    if(State::isStateEnabled(State::IMAGE)){
        // texture.draw(Board);
        // texture.draw(shadow);
       texture.create(BackGround.getGlobalBounds().width,BackGround.getGlobalBounds().height);
       texture.clear(BackGround.getFillColor());
       
        for(auto iter = Board.list.begin(); iter != Board.list.end(); iter++){
            (*iter).setPosition((*iter).getPosition().x, (*iter).getPosition().y+100.f);
            texture.draw(*iter);
        }
        for(auto it = shadow.list.begin(); it != shadow.list.end(); it++){
            (*it).setPosition((*it).getPosition().x, (*it).getPosition().y+100.f);
            texture.draw(*it);
        }
        // texture.draw(BackGround);
        texture.display();
        // sf::Texture Image;
        // Image.update(texture.getTexture(),0,50);
        // Image.copyToImage().saveToFile("../Image/new.png");
        texture.getTexture().copyToImage().saveToFile("../Image/Logo.png");
        cout << "Sucessfule outPut the Image" << endl;
        State::setStateEnable(State::IMAGE, false);
    }

}
void Input::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(BackGround);
    window.draw(title,states);
    window.draw(box,states);
    window.draw(cursor,states);
    window.draw(typing,states);
    window.draw(shadow,states);
    window.draw(Board,states);
    window.draw(ColorBox);
    window.draw(BGColorBox);
    
    window.draw(size);
    window.draw(ShadowX);
    window.draw(ShadowY);
    window.draw(TextX);
    window.draw(TextY);

    window.draw(ShadowCapacity);
    window.draw(TextCapacity);
    window.draw(BGCapacity);
    window.draw(SkewX);
    window.draw(SkewY);
    window.draw(Rainbow);
    window.draw(Shin);
    window.draw(BoardFont);
   
    window.draw(BoardColorPix);
    window.draw(BGColorPix);
}
////////////////////////////////////////////////////////////////////// /////////////////////////////////////////////////////////////
// All Initial Setting ---------------------------------------

void Input::SetPosition(sf::Vector2f position){
    title.SetPosition(position);
    position.x = position.x + title.GetLocalBound().width + 20.f ;
    box.SetPosition(position);
    cursor.SetPosition(position);
    position.y -= 5.f;
    typing.SetPosition(position);
}
void Input::SetSize(int size){
    title.SetSize(size);
    typing.SetSize(size);
    box.SetHeight(size);
    cursor.SetSize(box.getHeight());
}

list<sf::Text> Input::getText(){
    return typing.list;
}

// sf::Color Input::ColorReturn(int ColorPix){
//     sf::Color c;
//     if(ColorPix <= 60){
//         c.r = 100;
//         c.g = (100.00*ColorPix/60.00);
//         c.b = 0;
//     }else if(ColorPix <= 120){
//         c.r = 100.00 -((ColorPix-60.00)/60.00*100.00);
//         c.g = 100;
//         c.b = 0;
//     }else if(ColorPix <= 180){
//         c.r = 0;
//         c.g = 100;
//         c.b = ((ColorPix-120.00)/60.00*100.00);
//     }else if(ColorPix <= 240){
//         c.r = 0;
//         c.g = 100.00 - ((ColorPix-180.00)/60.00*100.00);
//         c.b = 100;
//     }else if(ColorPix <= 300){
//         c.r = ((ColorPix-240.00)/60.00*100.00);
//         c.g = 0;
//         c.b = 100;
//     }else if(ColorPix <= 360){
//         c.r = 100;
//         c.g = 0;
//         c.b = 100.00 - ((ColorPix-300.00)/60.00*100.00);
//     }
//     return c;
// }

// float Input::ColorReturnB(int ColorPix){
//     float b;
//     if(ColorPix <= 60){
//         b = 0;
//     }else if(ColorPix <= 120){
//         b = 0;
//     }else if(ColorPix <= 180){
//         b = ((ColorPix-120.00)/60.00*100.00);
//     }else if(ColorPix <= 240){
//         b = 100;
//     }else if(ColorPix <= 300){
//         b = 100;
//     }else if(ColorPix <= 360){
//         b = 100.00 - ((ColorPix-300.00)/60.00*100.00);
//     }
//     return b;
// }
// float Input::ColorReturnR(int ColorPix){
//     float r;
//     if(ColorPix <= 60){
//         r = 100;
//     }else if(ColorPix <= 120){
//         r = 100.00 -((ColorPix-60.00)/60.00*100.00);
//     }else if(ColorPix <= 180){
//         r = 0;
//     }else if(ColorPix <= 240){
//         r = 0;
//     }else if(ColorPix <= 300){
//         r = ((ColorPix-240.00)/60.00*100.00);
//     }else if(ColorPix <= 360){
//         r = 100;
//     }
//     return r;
// }
// float Input::ColorReturnG(int ColorPix){
//     float g;
//     if(ColorPix <= 60){
//         g = (100.00*ColorPix/60.00);
//     }else if(ColorPix <= 120){
//         g = 100;
//     }else if(ColorPix <= 180){
//         g = 100;
//     }else if(ColorPix <= 240){
//         g = 100.00 - ((ColorPix-180.00)/60.00*100.00);
//     }else if(ColorPix <= 300){
//         g = 0;
//     }else if(ColorPix <= 360){
//         g = 0;
//     }
//     return g;
// }

void Input::FileOpen(string Loc){
    typing.Clean();
    Board.Clean();
    shadow.Clean();
    ifstream file(Loc);
    string line;
    int i = 0;
    if(file.is_open()){
        while (getline(file,line))
        {
            cout << line << endl;
            switch (i)
            {
            case 0 :
                for(auto i = 0; i<line.size(); i++){
                    char texting = line.at(i);
                    typing.push(texting);
                    Board.push(texting);
                    shadow.push(texting);
                }
                break;
            case 1: 
                // int s = stoi(line);
                cout << stoi(line) << endl;
                size.SetByTxt(stoi(line));
                break;
            case 2: 
                // int sX = stoi(line);
                ShadowX.SetByTxt(stoi(line));
                break;
            case 3: 
                // int sY = stoi(line);
                ShadowY.SetByTxt(stoi(line));
                break;
            case 4: 
                // int tX = stoi(line);
                TextX.SetByTxt(stoi(line));
                break;
            case 5: 
                // int tY = stoi(line);
                TextY.SetByTxt(stoi(line));
                break;
            case 6: 
                // int sC = stoi(line);
                ShadowCapacity.SetByTxt(stoi(line));
                break;
            case 7: 
                // int tC = stoi(line);
                TextCapacity.SetByTxt(stoi(line));
                break;
            case 8: 
                // int BGC = stoi(line);
                BGCapacity.SetByTxt(stoi(line));
                break;
            case 9: 
                // int S = stoi(line);
                SkewY.SetByTxt(stoi(line));
                break;
            case 10: 
                // int BF = stoi(line);
                BoardFont.SetClick(stoi(line));
                break;
            case 11: 
                // int CB = stoi(line);
                ColorBox.SetByTxt(stoi(line));
                break;
            case 12: 
                // int BB = stoi(line);
                BGColorBox.SetByTxt(stoi(line));
                break;
            case 13: 
                // int Rainbow = stoi(line);
                State::setStateEnable(State::RAINBOW, stoi(line));
                break;
            case 14: 
                // int Shin = stoi(line);
                State::setStateEnable(State::SHIN, stoi(line));
                break;
            case 15: 
                BoardColorPix.SetX(stoi(line));
                break;
            case 16: 
                BoardColorPix.SetY(stoi(line));
                break;
            case 17: 
                BGColorPix.SetX(stoi(line));
                break;
            case 18: 
                BGColorPix.SetY(stoi(line));
                break;
            default:
                break;
            }
            i++;
        }
        file.close();
    }else {
        cout << "Cannot find the file" << endl;
    }
}

void Input::clean(){
    typing.Clean();
    Board.Clean();
    shadow.Clean();
}
#endif
