#include "OneFont.h"

sf::Font OneFont::font;
bool OneFont::fontload = false;

sf::Font& OneFont::getFont()
{
    loadFont();
    return font;
}

void OneFont::loadFont(){
    if (!fontload){
        if (!font.loadFromFile("OpenSans-Bold.ttf")){
            std::cout << "It's not working!!\n";
            system("pause");
            fontload = true;
        }
    }
}