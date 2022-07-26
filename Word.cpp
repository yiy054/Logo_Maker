#ifndef SFMLSET_WORD_CPP
#define SFMLSET_WORD_CPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

#include "Word.h"


Word::Word(string words, sf::Color color, int size){
    this->size = size;
    font.loadFromFile("OpenSans-Bold.ttf");
    setString(words);
    setFillColor(color);
    setCharacterSize(size);
    setFont(font);
    update();
}

Word::Word(string words, int size): Word(words, sf::Color::White, size){}


Word::Word(string words): Word(words, sf::Color::White, 60){}


Word::Word(): Word("", sf::Color::White, 60){}

void Word::update(){
    string word = getString();

    for(int i = 0; i < word.length(); ++i){
        if(isdigit(word[i])){
            setFillColor(sf::Color::Red);
        }
    }

    if(word != "=" && word != "<" && word != ">" &&
        word != "+" && word != "-" && word != "!" &&
        word != "*" && word != "/" && word != "%" ){
        setFillColor(sf::Color::Green);
    }

}

void Word::pop_back(){
    string temp = getString();
    temp.pop_back();
    setString(temp);
    update();
}

void Word::operator+=(string other){
    add(other);
    update();
}

void Word::add(string other){
    string temp = getString();
    temp += other;
    setString(temp);
    update();
}

bool Word::empty(){
    string temp = getString();
    return temp.empty();
}

bool operator==(const Word& first, const Word& second){
    return (first.getString() == second.getString());
}

#endif