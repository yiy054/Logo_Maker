#include "Image.h"


map<Image::image, sf:: Texture> Image::images;
map<Image::image, bool> Image::loaded;

sf::Texture& Image::getImage(image image){
    if(!loaded[image])
        loadImage(image);
    return images[image];
}

void Image::loadImage(image image){
    if(!loaded[image]){
        if(!images[image].loadFromFile(getImagePath(image)))
            exit(28);
        loaded[image] = true;
    }
}

string Image::getImagePath(image image){
    switch(image){
        case FOLDER: return "folader.png";
        case FILE: return "file.png";
    }
}