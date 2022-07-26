#include "ColorPix.h"

ColorPix::ColorPix(/* args */){
    Pix.setPrimitiveType(sf::Points);
    height = 101;
    width = 101;
    Pix.resize(height*width);
    initialX = 0;
    initialY = 0;
    R = 255.00;
    G = 0.00;
    B = 0.00;

    float H = 0;
    FindRGB(H);
    Max = FindMax(R,G,B) /255.00; // 1
    Min = FindMin(R,G,B) /255.00; // 0
    // cout << "Initial Color Set: " << Max << ", " << Min << ", " << H << endl;
    float S = (Max - Min)/Max*100; // 100
    // float V = (Max - Min)/(1-abs(Max+Min-1));
    float V = Max*100; //100
    // cout << "Initial Color Set: " << S << ", " << V << ", " << H << endl;
    point.setOutlineColor(sf::Color::White);
    point.setOutlineThickness(5);
    point.setRadius(10);
    ColorClick = sf::Color::Red;
    click = false;
}
void ColorPix::InitialSet(sf::Vector2f position, int size){
    Pix.clear();
    Size = size;
    doubleSize = size/100.00;
    height = 101*doubleSize;
    width = 101*doubleSize;
    Pix.resize(height*width);

    initialX = position.x;
    initialY = position.y;
    point.setPosition(position);
    point.setFillColor(sf::Color::White);
}
void ColorPix::SetX(int n){
    sf::Vector2f pos(initialX, initialY);
    pos.x += n;
    point.setPosition(pos);
    for(int i = 0; i< height*width; i++){
        if(pos.x == Pix[i].position.x && pos.y == Pix[i].position.y){
            ColorClick = Pix[i].color;
            point.setFillColor(ColorClick);
            point.setPosition(Pix[i].position);
            break;
        }
    }
}
void ColorPix::SetY(int n){
    sf::Vector2f pos(initialX, initialY);
    pos.y += n;
    point.setPosition(pos);
    for(int i = 0; i< height*width; i++){
        if(pos.x == Pix[i].position.x && pos.y == Pix[i].position.y){
            ColorClick = Pix[i].color;
            point.setFillColor(ColorClick);
            point.setPosition(Pix[i].position);
            break;
        }
    }
}
void ColorPix::Insert(int h){
    Pix.clear();
    Pix.resize(height*width);
    float H = h;
    FindRGB(H);
    Max = FindMax(R,G,B) /255.00; // 1
    Min = FindMin(R,G,B) /255.00; // 0
    float S = (Max - Min)/Max*100*doubleSize; // 100
    float initialS = (Max - Min)/Max*100*doubleSize; //100
    float V = Max*100*doubleSize; //100
    float initialV = Max*100*doubleSize; //100
    // cout << "Initial Color Set: " << S << ", " << V << ", " << H << endl;

    sf::Color c(R,G,B);
    int Hi;
    Hi = H/60;
    float f;
    f = float(H/60)-Hi;

    // cout << endl << endl;
    for(int y = 0; y <= 100*doubleSize; y++){
        S = initialS;
        for(int x = 0; x <= 100*doubleSize; x++){        
            float p = V/100.00/doubleSize*(1-S/100.00/doubleSize)*225.00;
            float q = V/100.00/doubleSize*(1-f * S/100.00/doubleSize)*225.00;
            float t = V/100.00/doubleSize*(1-(1-f)*S/100.00/doubleSize)*225.00;
            //  cout << "Initial Color Set: " << S << ", " << V << ", " << H << endl;
            //  cout << "Initial Color Set: " << V << ", " << t << ", " << p << endl;
            // if(S == 0){
            //     cout << "Sucessfule White" << S << ", " << V << endl;
            //     cout << "Point : " << x + y*100 << endl;
            //     cout << "Position: " << x+initialX << ", " << y+initialY << endl;
            //     cout << "-------------DATA cal " << f << ", " << S << ", " << V << endl;
            //     cout << "Initial Color Set: " << V/100.00/doubleSize*225.00 << ", " << t << ", " << p << endl;
            //     cout << endl << endl;
            // }
            switch (Hi)
            {
            case 0: c.r = V/100.00/doubleSize*225.00;
                    c.g = t;
                    c.b = p;
                break;
            case 1: c.r = q;
                    c.g = V/100.00/doubleSize*225.00;
                    c.b = p;
                break;
            case 2: c.r = p;
                    c.g = V/100.00/doubleSize*225.00;
                    c.b = t;
                break;
            case 3: c.r = p;
                    c.g = q;
                    c.b = V/100.00/doubleSize*225.00;
                break;
            case 4: c.r = t;
                    c.g = p;
                    c.b = V/100.00/doubleSize*225.00;
                break;
            case 5: c.r = V/100.00/doubleSize*225.00;
                    c.g = p;
                    c.b = q;
                break;
            }
            Pix[x + (y)*100*doubleSize].color = c;
            Pix[x + (y)*100*doubleSize].position = sf::Vector2f(x+initialX,y+initialY);
            // if(point == 0 ||point == 100 || point == 10000){
            //     cout << "Point : " << x + (y)*100 << endl;
            //     cout << "Position: " << x+initialX << ", " << y+initialY << endl;
            //     cout << "Color Set: " << S << ", " << V << ", " << H << endl;
            // }
            S = S - initialS/100/doubleSize;
        }
        V -= initialV/100/doubleSize;
    }
    // point.setFillColor(Pix[0].color);
}
float ColorPix::FindMax(float r, float g, float b){
    float max = 0;
    if(R > max){max = R;}
    if(G > max){max = G;}
    if(B > max){max = B;}
    return max;
}
float ColorPix::FindMin(float r, float g, float b){
    float min = 0;
    if(R < min){min = R;}
    if(G < min){min = G;}
    if(B < min){min = B;}
    return min;
}

void ColorPix::FindRGB(int h){
    R = 100;
    G = 0;
    B = 0;
    if(h <= 60){
        G = (100.00*h/60.00);
    }else if(h <= 120){
        R = 100.00 -((h-60.00)/60.00*100.00);
    }else if(h <= 180){
        B = ((h-120.00)/60.00*100.00);
    }else if(h <= 240){
        G = 100.00 - ((h-180.00)/60.00*100.00);
    }else if(h <= 300){
        R = ((h-240.00)/60.00*100.00);
    }else if(h <= 360){
        B = 100.00 - ((h-300.00)/60.00*100.00);
    }
    R = R/100*255;
    G = G/100*255;
    B = B/100*255;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AddEVentHandle Updata Window DRAW  -------------------------------

void ColorPix::update(){

}
void ColorPix::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(Pix);
    window.draw(point);
}
void ColorPix::addEventHandler(sf::RenderWindow& window, sf::Event event){
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    // cout << pos.x << ", " << pos.y << endl;
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
        if(pos.x <= initialX){
            pos.x = initialX;
        }
        if(pos.x >= initialX + Size){
            pos.x = initialX + Size;
        }
        if(pos.y <= initialY){
            pos.y = initialY;
        }
        if(pos.y >= initialY + Size){
            pos.y = initialY + Size;
        }
        // cout << "Color point change position to:" << point.getPosition().x << ", " << point.getPosition().x << endl;
        // point.setFillColor()
        for(int i = 0; i< height*width; i++){
            if(pos.x == Pix[i].position.x && pos.y == Pix[i].position.y){
                ColorClick = Pix[i].color;
                point.setFillColor(ColorClick);
                point.setPosition(Pix[i].position);
                break;
            }
        }
    }
}
