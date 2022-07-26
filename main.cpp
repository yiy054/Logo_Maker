#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "MyClass.h"
// #include "Typing.h"
// #include "Input.h"
#include "Itemlist.h"
#include "InputBox.h"
#include "DropDown.h"
// #include "Menu.h"
// #include "MenuBar.h"
#include "FileItem.h"
#include "FileNode.h"
#include "FileTree.h"
#include "Image.h"
#include "Logo.h"
#include "Typing.h"
#include "Fonts.h"
#include "Slider.h"
#include "ColorPix.h"
#include <list>
#include <vector>
#include "OpenWindow.h"
#include "Image.h"
#include "State.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(6000,3000),"SFML Project");
//Text project ----------------------------------------
    // sf::Text text;
    // sf::Text shadow;
    // text.setString("CS 008 HOME");
    // shadow.setString("CS 008 HOME");
    //     //font
    // sf::Font font;
    // font.loadFromFile("OpenSans-Bold.ttf");
    // text.setFont(font);
    // shadow.setFont(font);
    // // text.setFont(Fonts::getFont(Fonts::OPENSANS));
    // //color
    // sf::Color white = sf::Color::White;
    // sf::Color color = sf::Color::White;
    // text.setFillColor(color);
    // white.a = 50;
    // shadow.setFillColor(white);
    // shadow.setStyle(sf::Text::Bold);
    // shadow.setPosition(300.f, 500.f);
    // shadow.setScale(sf::Vector2f(6.38f, -5.f));

    // text.setCharacterSize(200);
    // text.setStyle(sf::Text::Bold);
    // text.setPosition(300.f, 150.f);
//Bouncing ball ----------------------------------------
    // MyClass ball(10,5);
    // Typing typing;
    // sf::Texture texture;
    // texture.create(500,500);
    // texture.loadFromFile("file.png"); 
    // texture.update(window);
    // sf::Sprite sprite;
    // sprite.setTexture(texture);
    // sprite.setPosition(300.f, 250.f);
    // sprite.setColor(sf::Color::White);
    // sprite.setScale(0.1f,0.1f);
//Typing ----------------------------------------
    // sf::Cursor cursor;
    // cursor.loadFromSystem(sf::Cursor::Hand);
    // sf::RectangleShape cursor(sf::Vector2f(100.f, 100.f));
    // cursor.setFillColor(sf::Color::Red);
    // cursor.setPosition(300.f, 250.f);

    // sf::Text title;
    // sf::Font font;
    // font.loadFromFile("OpenSans-Bold.ttf");
    // title.setString("Input:");
    // title.setFont(font);
    // title.setCharacterSize(100);
    // title.setStyle(sf::Text::Bold);
    // title.setPosition(200.f, 50.f);
//DROPDOWN Menu ----------------------------------------
    // Input data;
    // vector<string> File{"Close Project", "New Project", "Quit", "Save Project"};
    // vector<string> Render{"Expert Image"};
    // Itemlist menu(vector);
    // InputBox box;
    // Item i;
    // DropDown menu(vector);
    // menu.setPosition(100, 100);
    // MenuBar menu;
    // menu.VecSet(File, "File");
    // menu.VecSet(Render, "Render");
    // Menu menu;
    // menu.("data");
    // menu.VecSet(vector);
    // cout << "Finish Input " << endl;
    // menu.Set(40);
    // menu.SetPosition(20,20);
    // sf::Vector2f size(0.1f,0.1f);
    // sf::Vector2f position(0.f,0.f);

//Flir Tree----------------------------------------
    // FileNode item(Image::FOLDER, "Folder", size,position);

    // // position = position + sf::Vector2f(item.getGlobalBounds());
    // position.x += item.getGlobalBounds().width;
    // position.y += item.getGlobalBounds().height;

    // FileNode item2(Image::FILE, "file 1", size,position);

    // FileTree tree;
    // tree.push("Folder", "Folder 1", Image::FOLDER, Image::FOLDER);
    // tree.push("Folder 1", "Folder 11", Image::FOLDER, Image::FOLDER);
    // tree.push("Folder 1", "file 12", Image::FOLDER, Image::FILE);
    // tree.push("Folder", "file 2", Image::FOLDER, Image::FILE);
    // Folder 
    //      Folder 1
    //         Folder11
    //         file 12
    //     file2
    
//Final Project ----------------------------------------
    Logo logo; 
    sf::Texture texture;
    texture.create(2000, 1000);
    // OpenWindow newWindow;
    // ColorPix Pix;
    // Pix.Insert(350, {100,100}, 500);
    // DropDown BoardFont;
    // vector<string> vector{"BEATNEY", "HARRYP", "OPENSANS", "PUMKIN", "WINTER"};
    // BoardFont.SetTitle("Font");
    // BoardFont.SetVec(vector);
    // BoardFont.SetSize(40);
    // BoardFont.SetPosition(200,200);
    
    // Itemlist lis(vector);

    // sf::Text text;
    // text.setString("Font");
    // text.setFont(Fonts::getFont(Fonts::PUMKIN));
    // InputBox input;
    // input.SetText("Font");
    // input.SetSize(40);
    // input.SetPosition({0,0});

//Color Pix -----------------------------------------------------
    // Slider slider;
    // slider.ListSet(1500,50);
    // Slider RegularLine;
    // RegularLine.LineSet();
    // RegularLine.SUMset(500, "Shadow Capacity", {10,1250}, 100);

        // point.setPosition(X,Y);
    // list<sf::VertexArray> colorBox;
    // int X = 1500;
    // int Y = 50;
    // float R, G, B;
    // R = 100.00;
    // G = 0.00;
    // B = 0.00;
    // for(int x = X; x <= 360+X; x++){
    //     sf::VertexArray lines(sf::LineStrip, 2);
    //     Y = 50;
    //     for(int y = 0; y < 2; y++){
    //         lines[y].position = sf::Vector2f(x, Y);
    //         sf::Color color(R, G, B);
    //         lines[y].color = color;
    //         Y += 10.f;
    //     }
    //     if((x-X) <= 60){
    //         G = (100.00*(x-X)/60.00);
    //     }else if((x-X) <= 120){
    //         R = 100.00 -(((x-X)-60.00)/60.00*100.00);
    //     }else if((x-X) <= 180){
    //         B = (((x-X)-120.00)/60.00*100.00);
    //     }else if((x-X) <= 240){
    //         G = 100.00 - (((x-X)-180.00)/60.00*100.00);
    //     }else if((x-X) <= 300){
    //         R = (((x-X)-240.00)/60.00*100.00);
    //     }else if((x-X) <= 360){
    //         B = 100.00 - (((x-X)-300.00)/60.00*100.00);
    //     }
    //     // cout << "Color RGB : R: " << R << " G: " << G << " B: " << B << endl;
    //     // cout << "X Vale " << x << endl << "-------------------------" << endl;
    //     colorBox.push_back(lines);
    // }

    // sf::VertexArray box(sf::TriangleStrip, 5);

    // box[0].position = sf::Vector2f(0,0);
    // box[1].position = sf::Vector2f(100,0);
    // box[2].position = sf::Vector2f(100,100);
    // box[3].position = sf::Vector2f(0,100);
    // box[4].position = sf::Vector2f(0,0);

    // box[0].color = sf::Color::Black;
    // box[1].color = sf::Color::Black;
    // box[2].color = sf::Color::Yellow;
    // box[3].color = sf::Color::White;
    // box[4].color = sf::Color::Black;

    // sf::VertexArray Pix;
    // Pix.setPrimitiveType(sf::Points);
    // int height = 100;
    // int width = 100;
    // Pix.resize(height*width);
    // int initialX = 0;
    // int initialY = 0;
    // float R = 255.00;
    // float G = 0.00;
    // float B = 0.00;
    // float initialR = 1;
    // float initialG = 0;
    // float initialB = 0;

    // float Max, Min = 0;
    // if(R > Max){Max = R;}
    // if(G > Max){Max = G;}
    // if(B > Max){Max = B;}
    // if(R < Min){Min = R;}
    // if(G < Min){Min = G;}
    // if(B < Min){Min = B;}

    // float H = 0;
    // float S = (Max - Min)/Max/255*100; // 1
    // float V = Max/255*100; //1 
    // float C = V * S;

    // sf::Color c(R,G,B);
    // int point = 0;
    // int Hi;
    // Hi = H/60;
    // float f;
    // f = float(H/60)-Hi;

    // for(int y = 1; y <= 100; y++){

    //     for(int x = 1; x <= 100; x++){        
    //         float p = V/100.00*(1-S/100.00);
    //         float q = V/100.00*(1-f * S/100.00);
    //         float t = V/100.00 * (1-(1-f)*S/100.00);

    //         switch (Hi)
    //         {
    //         case 0: c.r = V;
    //                 c.g = t;
    //                 c.b = p;
    //             break;
    //         case 1: c.r = q;
    //                 c.g = V;
    //                 c.b = p;
    //             break;
    //         case 2: c.r = p;
    //                 c.g = V;
    //                 c.b = t;
    //             break;
    //         case 3: c.r = p;
    //                 c.g = q;
    //                 c.b = V;
    //             break;
    //         case 4: c.r = t;
    //                 c.g = p;
    //                 c.b = V;
    //             break;
    //         case 5: c.r = V;
    //                 c.g = p;
    //                 c.b = q;
    //             break;
    //         }
    //         Pix[x + (y-1)*100-1].color = c;
    //         Pix[x + (y-1)*100-1].position = sf::Vector2f(x+initialX,y+initialY);
    //         point = x + (y-1)*100-1;
    //         if(point == 0 ||point == 100 || point == 10000){
    //             cout << "Point : " << x + (y-1)*100-1 << endl;
    //             cout << "Position: " << x+initialX << ", " << y+initialY << endl;
    //             // cout << "Color Set: " << c.r << ", " << c.g << ", " << c.b << endl;
    //         }
    //         S = S -1;
    //     }
    //     V--; 
    // }


//typing Test----------------------------------------
    // Typing typing;
    // typing.push('d');
    // typing.push('d');
    // typing.push('d');
    // typing.push('d');
    // typing.push('d');
    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            if(State::isStateEnabled(State::QUIT)){
                window.close();
            }
            // newWindow.addEventHandler(window,event);
            // data.addEventHandler(window, event);
            // tree.traverse(window,event);
            // cout << endl << endl << endl << "Another trail" << endl;
            // tree.addEventHandler(window, event);
            // menu.addEventHandler(window, event);
            // list.addEventHandler(window, event);
            // History::pushHistory(t);
            logo.addEventHandler(window,event);
            // BoardFont.addEventHandler(window,event);
            // slider.addEventHandler(window,event);
            // RegularLine.addEventHandler(window,event);
        }
    //This function makes the ball move in the window
        // ball.bounce(window);
//UPDATE -----------------------------------------------------
        // data.update();
        // tree.update();
        // menu.update();
        logo.update();
        // newWindow.update();
        // newWindow.winOpen();
        // BoardFont.update();
        // slider.update();
        // RegularLine.update();
        // cout << "Update" << endl;
//Draw -----------------------------------------------------
        window.clear(sf::Color::Black);
        // window.draw(title);
        // window.draw(sprite);
        // window.setMouseCursor(cursor);
        // window.draw(data);
        // window.draw(ball);
        // window.draw(list);
        // window.draw(box);
        // window.draw(tree);
        // window.draw(menu);
        // window.draw(sprite);
        window.draw(logo);
        // window.draw(newWindow);
        // window.draw(Pix);
        // window.draw(BoardFont);
        // window.draw(text);
        // window.draw(slider);
        // window.draw(RegularLine);
        // window.draw(box);
        // window.draw(shadow);
        // for(auto iter = colorBox.cbegin(); iter!= colorBox.cend(); iter++){
        //     window.draw(*iter);
        // }
        // for(auto iter = 0; iter <= vec.size(); iter++){
        //     window.draw(vec.at(iter));
        // }
        // cout << "Draw" << endl;
        // if(State::isStateEnabled(State::IMAGE)){
        //     texture.update(window, 0, 50);
        //     texture.copyToImage().saveToFile("../Image/Logo.png");
        //     State::setStateEnable(State::IMAGE, false);
        // }
        window.display();
    }
    cout << "End   End" << endl;
    return 0;
}