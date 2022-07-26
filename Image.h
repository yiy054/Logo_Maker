
#ifndef SFMLSET_IMAGE_H
#define SFMLSET_IMAGE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

// Provide by Prof Dave Smith

class Image {
public:
    enum image{FOLDER, FILE};

    static map<image, sf:: Texture> images;
    static map<image, bool> loaded;
    static sf::Texture& getImage(image image);
    static void loadImage(image image);
    static string getImagePath(image image);
};



#endif 