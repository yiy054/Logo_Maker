
#include "InputBox.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// All Initial Setting ---------------------------------------

// InputBox::InputBox(string msg, sf::Vector2f vec, sf::Color color){
//     // box.setSize(vec);
//     box.setOutlineThickness(5);
//     box.setOutlineColor(color);
//     box.setFillColor(sf::Color::Transparent);

//     text.setFont(Fonts::getFont(Fonts::OPENSANS));
//     text.setString(msg);
//     text.setFillColor(color);
//     text.setCharacterSize(vec.y/2);
//     text.setPosition(box.getPosition().x + box.getLocalBounds().width/2 - text.getLocalBounds().width/2,
//                      box.getPosition().y + box.getLocalBounds().height/2 - text.getLocalBounds().height/1.5);
// }

// InputBox::InputBox(string msg): InputBox(msg, {500,100}, sf::Color::Transparent){}

InputBox::InputBox(){
    box.setOutlineThickness(5);
    box.setFillColor(sf::Color::Black);
    box.setOutlineColor(sf::Color::White);

    text.setFont(Fonts::getFont(Fonts::OPENSANS));
    text.setFillColor(sf::Color::White);
}

void InputBox::SetText(string msg, int loc){
    text.setString(msg);
    // setPosition(getPosition().x, getPosition().y);
    switch (loc)
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
    SetPosition(box.getPosition());
}

void InputBox::SetSize(int n){
    text.setCharacterSize(n);
    sf::Vector2f size = sf::Vector2f(text.getGlobalBounds().width+50.f,text.getGlobalBounds().height+30.f);
    // box.setFillColor(sf::Color::Transparent);
    box.setSize({250, size.y});
}

void InputBox::SetPosition(sf::Vector2f pos){
    box.setPosition(pos.x, pos.y);
    text.setPosition(pos.x + box.getLocalBounds().width/2.00 - text.getGlobalBounds().width/2.00,
                     pos.y + box.getGlobalBounds().height/2.00 - text.getGlobalBounds().height);
    // cout << "BOX position: " << pos.x << ", " << pos.y << endl
    //     << "Text position: " << pos.x + box.getGlobalBounds().width/2.00 - text.getGlobalBounds().width/2.00 << ", " << pos.y + box.getGlobalBounds().height/2.00 - text.getGlobalBounds().height/1.00 << endl;
}
void InputBox::BoxSet(float width){
    sf::Vector2f size = sf::Vector2f(text.getGlobalBounds().width+50.f,text.getGlobalBounds().height+30.f);
    box.setSize({width, size.y});
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AddEVentHandle Updata Window DRAW  -------------------------------
void InputBox::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(box);
    window.draw(text);
}