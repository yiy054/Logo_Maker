
#ifndef SFMLSET_FONTS_H
#define SFMLSET_FONTS_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace std;
#include <cstdlib>

class Fonts {
public:
    // static sf::Font font;
    // static sf::Font& getFont();

    enum fonts {BEATNEY, HARRYP, OPENSANS, PUMKIN, WINTER,LAST};
    static sf::Font& getFont(fonts font);

    static vector<sf::Font> _fonts;
    static vector <bool> loaded;
    
    static string mapfont(fonts font);
    static void loadFont(fonts font);

    // static void loadFont();
    // static bool fontload;
};


#endif //SFMLTYPING_FONTS_H
