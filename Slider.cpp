#include "Slider.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// All Initial Setting ---------------------------------------
Slider::Slider(){
    label.setFillColor(sf::Color::White);
    point.setFillColor(sf::Color::White);
    label.setFont(OneFont::getFont());    
    num.setFillColor(sf::Color::White);
    num.setFont(OneFont::getFont());
    line.setSize({30,10});
    point.setRadius(20);
    click = false;
    RegularLine = false;
    Colorline = false;    
    size = 0;
    sf::String data = to_string(size);
    num.setString(data);
    // clicked = false;
    // box.setSize({500, 300});
    // box.setFillColor(sf::Color::Blue);
    // box.setPosition({100, 100});
}

void Slider::LineSet(){
    line.setFillColor(sf::Color::White);
    line.setSize({30,10});
    RegularLine = true;
}

void Slider::ListSet(float X, float Y, string s){
    label.setString(s);
    label.setPosition({X,Y});
    X = X + label.getGlobalBounds().width + 10;
    point.setPosition({X,Y});
    Y += 5;
    initialColor.x = X;
    initialColor.y = Y;
//Start draw pix
    float R, G, B;
    R = 100.00;
    G = 0.00;
    B = 0.00;
    for(int x = X; x < 360+X; x++){
        sf::VertexArray lines(sf::LineStrip, 2);
        Y = initialColor.y;
        for(int y = 0; y < 2; y++){
            lines[y].position = sf::Vector2f(x, Y);
            sf::Color color(R, G, B);
            lines[y].color = color;
            Y += 10.f;
        }
        if((x-X) <= 60){
            G = (100.00*(x-X)/60.00);
        }else if((x-X) <= 120){
            R = 100.00 -(((x-X)-60.00)/60.00*100.00);
        }else if((x-X) <= 180){
            B = (((x-X)-120.00)/60.00*100.00);
        }else if((x-X) <= 240){
            G = 100.00 - (((x-X)-180.00)/60.00*100.00);
        }else if((x-X) <= 300){
            R = (((x-X)-240.00)/60.00*100.00);
        }else if((x-X) <= 360){
            B = 100.00 - (((x-X)-300.00)/60.00*100.00);
        }
        MaxColorPos.x = x;
        // cout << "Color RGB : R: " << R << " G: " << G << " B: " << B << endl;
        // cout << "X Vale " << x << endl << "-------------------------" << endl;
        colorBox.push_back(lines);
        MaxColorPos.y = Y - 40.f;
    }
    num.setPosition({MaxColorPos.x+40, MaxColorPos.y});
    Colorline = true;
}
void Slider::setSize(float n){
    line.setSize({n+50,10});
}
void Slider::setLabel(string data){
    label.setString(data);
}

void Slider::setPosition(sf::Vector2f position){
    label.setPosition(position);
    // cout << "label x ---------" << position.x << endl;
    position.x = position.x + label.getGlobalBounds().width + 10;
    point.setPosition(position);
    // cout << "point x ---------" << position.x << endl;
    position.y += 5;
    line.setPosition(position);
    position.x = position.x + line.getLocalBounds().width+10;
    // cout << "num x ---------" << position.x << endl;
    num.setPosition(position);
}

void Slider::SUMset(float n, string data, sf::Vector2f position, int s){
    line.setFillColor(sf::Color::White);
    LineSet();
    setLabel(data);
    setSize(n);
    setPosition(position);
    size = s;
    sf::String D(to_string(size));
    num.setString(D);
    position.x = position.x + label.getGlobalBounds().width + 10 + size;
    point.setPosition(position);
    
    RegularLine = true;
}
void Slider::SetByTxt(int n){
    num.setString(to_string(n));
    sf::Vector2f pos;
    pos.y = point.getPosition().y;
    pos.x = n + label.getPosition().x + label.getGlobalBounds().width + 10;
    point.setPosition(pos);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//GetData   -------------------------------

int Slider::getData(){
    return size;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AddEVentHandle Updata Window DRAW  -------------------------------
void Slider::update(){

}
void Slider::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    if(RegularLine){
        // cout << "DRAW reglar line" << endl;
        window.draw(line);
    }
    if(Colorline){
        // cout << "DRAW Color line" << endl;
        for(auto iter = colorBox.cbegin(); iter!= colorBox.cend(); iter++){
            window.draw(*iter);
        }
        // cout << "window DRAW COLOR PIX" << endl;
    }
    window.draw(point);
    window.draw(label);
    window.draw(num);
    // window.draw(box);
}
void Slider::addEventHandler(sf::RenderWindow& window, sf::Event event){
    // if(MouseEvents<sf::CircleShape>::mouseClicked(point, window)){
    //     cout << "Point Click -------" << endl;
    //     while(event.type != event.MouseButtonReleased ){
    //         if(event.type == event.MouseMoved){
    //         sf::Vector2i mousePos = sf::Mouse::getPosition();
    //         sf::Vector2f position(mousePos);
    //         cout << position.x << "-----" << position.y << endl;
    //         point.setPosition(position);
    //         }
    //     }
    //     cout << "Click Release ---------" << endl;
    //     sf::Vector2i mousePos = sf::Mouse::getPosition();
    //     sf::Vector2f position(mousePos);
    //     point.setPosition(position);
    //     size = line.getGlobalBounds().width - position.x;
    // }
    // if(MouseEvents<sf::CircleShape>::draggedOver(point, window, event)){
    //     while(event.type == event.MouseButtonReleased ){
    //         cout << "start MOVE -------" << endl;
    //         sf::Vector2i mousePos = sf::Mouse::getPosition();
    //         sf::Vector2f position(mousePos);
    //         point.setPosition(position);
    //         size = line.getGlobalBounds().width - position.x;
    //     }
    // }
    // if ((point.getLocalBounds()).contains(pos.x, pos.y)) {
    //     cout << "HOVER POINT -------" << endl;
    //     if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
    //     // if(event.type == event.MouseButtonPressed){
    //         // If the mouse button is not released
    //         cout << "Click -----------------" << endl;
    //         while (event.type != event.MouseButtonReleased) {
    //             click = true;
    //             cout << "Change To TRUE" << endl;
    //         }
    //     }

    sf::Vector2i pos = sf::Mouse::getPosition(window);
    if (MouseEvents<sf::CircleShape>::mouseClicked(point, window)) {
        // If the mouse button is not released
        if (event.type != event.MouseButtonReleased) {
            click = true;
            // cout << "Click -----------------" << endl;
        }
    }else if (event.type == event.MouseButtonReleased) {
        click = false;
        // cout << "Change To FALSE" << endl;
    }

    if (click) {
        if(RegularLine == true){
            size = pos.x - label.getPosition().x - label.getGlobalBounds().width - 10;
            if(size <= 0){
                size = 0;
                pos.x = label.getGlobalBounds().width + label.getPosition().x + 10;
            }
            if(size >= (line.getSize().x - 50)){
                size = line.getSize().x-50;
                pos.x = label.getGlobalBounds().width + label.getPosition().x + 10 + line.getGlobalBounds().width - 50;
            }
            sf::String D(to_string(size));
            num.setString(D);
            point.setPosition(pos.x, point.getPosition().y);
            // std::cout << "Distance: " << point.getPosition().x << std::endl;
        }
        if(Colorline == true){
            // cout << "Move point to right color" << endl;
            // cout << "Initial Position: " << pos.x << ", " << pos.y << endl;
            size = pos.x - initialColor.x;
            if(pos.x <= initialColor.x){
                size = 0;
                pos.x = initialColor.x;
            }
            if(pos.x >= MaxColorPos.x){
                size = MaxColorPos.x - initialColor.x;
                pos.x = MaxColorPos.x;
            }
            // cout << "Position: " << pos.x << ", " << pos.y << endl;
            auto iter = colorBox.begin();
            for(; iter != colorBox.end(); iter++){
                if((*iter).getBounds().contains(pos.x, pos.y)){
                    // cout << "Find the list one" << endl;
                    size = pos.x - initialColor.x;
                }
            }
            sf::String D(to_string(size));
            num.setString(D);
            point.setPosition(pos.x, point.getPosition().y);
        }
    }
}
