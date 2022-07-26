#ifndef SFMLSET_MOUSEEVENTS_H
#define SFMLSET_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

template <class T>
class MouseEvents {

public:
    // returns true if the mouse clicks on the object
    static bool mouseClicked(T& object, sf::RenderWindow& window);

    // returns true if the mouse clicks anywhere in the window
    static bool mouseClicked( sf::RenderWindow& window, sf::Event event);

    // returns true if the mouse has been double clicked
    static bool mouseDoubleClicked();

    //returns true if the mouse has been triple clicked
    static bool mouseTripleClicked();

    // returns if the object has been clicked and the mouse has dragged over the object
    static bool draggedOver(T& object, sf::RenderWindow& window, sf::Event event);
    
    // returns tru if the mouse is hovered over the object
    static bool hovered(T& object, sf::RenderWindow& window);

private:
    // this is what I used to determine if a double click or triple click occurred
    // you don't have to use this if you don't want to
    static sf::Clock clock;
    static int clicks;
    static void countClicks(sf::Event event);
};


// -----------------implementation------


template <class T>
int MouseEvents<T>::clicks;

template <class T>
bool MouseEvents<T>::mouseClicked(T& object, sf::RenderWindow& window){
    if(hovered(object, window)&&sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        // cout << "HOVERED" << endl;
        // if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        // cout << "EVENT MOUSE CLICK" << endl;
        return true;
    }else{
        return false;
    }
}

template <class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow& window, sf::Event event){
    if( (event.type == event.MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Button::Left) ){
        return true;
    }else{
        return false;
    }
}

template <class T>
bool MouseEvents<T>::mouseDoubleClicked(){
    if(clicks == 2){
        return true;
    }
}

template <class T>
bool MouseEvents<T>::mouseTripleClicked(){
    return (clicks == 3);
}

template <class T>
bool MouseEvents<T>::draggedOver(T& object, sf::RenderWindow& window, sf::Event event){
    if(mouseClicked(object, window)){
        cout << "Mouse Click" << endl;
        while( event.type != event.MouseButtonReleased ){
            if(event.type == event.MouseMoved){
                return true;
            }
        }
        cout << "Move DONE" << endl; 
    }
    return false;
}

template <class T>
bool MouseEvents<T>::hovered(T& object, sf::RenderWindow& window){
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    // cout << object.getLocalBounds().width << " " << object.getLocalBounds().height << endl;
    if((object.getGlobalBounds()).contains(pos.x, pos.y) ){
        // cout << "True" << pos.x << " " << pos.y << endl;
        return true;
    }else{
        return false;
    }
}


template <class T>
void MouseEvents<T>::countClicks(sf::Event event){
    while(clock.getElapsedTime().asSeconds() <= 1){
        if( (event.type == event.MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Button::Left) ){
            clock.restart();
            ++clicks;
        }
    }
            
}

#endif