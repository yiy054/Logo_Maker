//
// 
//

#include "Fonts.h"

vector<sf::Font> Fonts::_fonts(LAST,sf::Font());
vector <bool> Fonts::loaded(LAST,false);

// vector<sf::Font> Fonts::_fonts;
// vector <bool> Fonts::loaded;

sf::Font& Fonts::getFont(Fonts::fonts font){
    loadFont(font);
    return _fonts[font];
}

string Fonts::mapfont(Fonts::fonts font){
    switch (font)
    {
    case BEATNEY: return "Beatney.ttf";
    case HARRYP: return "HARRYP.ttf";
    case OPENSANS: return "OpenSans-Bold.ttf";
    case PUMKIN: return "Pumpkin Story.ttf";
    case WINTER: return "Winter Sunday.ttf";
    case LAST: return "0";
    }
}
void Fonts::loadFont(Fonts::fonts font){
    if(!loaded[font]){
        _fonts[font].loadFromFile(mapfont(font));
        // cout << "True Sucessful Load" << endl;
        loaded[font] = true;
    }
}
