#include "MenuBar.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// All Initial Setting ---------------------------------------
MenuBar::MenuBar(){
    x = 0;
    y = 0;
}

void MenuBar::VecSet(vector<string> vector, sf::String title, float width){
    // string s = "Menu" + to_string(i);
    sf::String T = title;
    Menu menu; // each Small Menu inside Bar
    // menu.itemSet(s);
    // menu.itemlistSet(vector);
    // menu.SetSize(40);
    // menu.setPosition(x,y);
    menu.MenuSum(title,vector, 40, {x, y}, width);
    // cout << "Menu Set" << i << endl;
    // cout << x << " Sucessfule Insert THE MENU " << endl;
    cout << menu.GetPosition().x << ", " << menu.GetPosition().y << endl << endl;
    bar.push_back(menu);
    x += width;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AddEVentHandle Updata Window DRAW  -------------------------------
void MenuBar::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    auto iter = bar.cbegin();
        for(;iter != bar.cend(); ++iter){
            window.draw(*iter);
        }
}

void MenuBar::addEventHandler(sf::RenderWindow& window, sf::Event event){
    auto iter = bar.begin();
    for(;iter != bar.end(); ++iter){
        (*iter).menuSet(menu);
        (*iter).addEventHandler(window,event);
        (*iter).update();
        menu = (*iter).getMenu();
        if(State::isStateEnabled(State::BAR)){
            click = (*iter).ReturnClickItem();
            // cout << click << endl;
        }
    }
}

void MenuBar::update(){
}