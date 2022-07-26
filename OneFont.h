#ifndef SFMLSET_ONEFONT_H
#define SFMLSET_ONEFONT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;
#include <cstdlib>

class OneFont {
public:
    static sf::Font font;
    static sf::Font& getFont();
private:
    static void loadFont();
    static bool fontload;
};






#endif

