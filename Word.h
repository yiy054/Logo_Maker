#ifndef SFMLSET_WORD_H
#define SFMLSET_WORD_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

#include "Stacks.h"

class Word: public sf::Text{
public:
    Word(string words, sf::Color color, int size);
    Word(string words, int size);
    Word(string words);
    Word();
    void update();
    void pop_back();
    void operator+=(string other);
    bool empty();
    void add(string other);
    friend bool operator==(const Word& first, const Word& second);
    // friend std::ostream& operator << (const Word& other){
    //     return (other.getString()); 
    // }
private:
    int size;
    sf::Font font;
};

#endif