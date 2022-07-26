#include "Menu.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// All Initial Setting ---------------------------------------
Menu::Menu(/* args */){
    x = 0;
    y = 0;
}

void Menu::MenuSum(sf::String title, vector<string> vecList, int size, sf::Vector2f pos, float width){
    input.SetText(title, 3);
    for(int i = 0; i < vecList.size(); i++){
        list.Insert(vecList.at(i), 3, width);
    }
    input.SetSize(size);
    list.SetSize(size);
    input.BoxSet(width);

    input.SetPosition(pos);
    list.SetPosition(pos.x, pos.y + input.getGlobalBounds().height);

}
void Menu::itemSet(string data){
    input.setPosition(x,y);
    input.SetText(data, 3);
    inputdata = input.getText();
}
void Menu::SetSize(int size){
    input.SetSize(size); 
    list.SetSize(size);
}

void Menu::itemlistSet(vector<string> vector){
    // list.setPosition(input.getPosition().x, input.getPosition().y + input.getGlobalBounds().height);
    for(int i = 0; i < vector.size(); i++){
        list.Insert(vector.at(i), 3, 250);
    }
    // cout << "Sucessful Insert END" << endl;
}

void Menu::SetPosition(float X, float Y){
    x = X;
    y = Y;
    input.SetPosition({x, y});
    list.SetPosition(x, y + input.getGlobalBounds().height);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AddEVentHandle Updata Window DRAW  -------------------------------
void Menu::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(input);
    // cout << "START DRAW !!!!!!!!!!!!!" << endl;
    // cout << "Menu Show state (0-F, 1-T) ----------" << State::isStateEnabled(State::BAR) << endl;
    if(State::isStateEnabled(State::BAR)){
        // cout << string(menu) << "COMPARE" << string(inputdata) << endl;
        if(MenuTitleHov == inputdata){
            // cout << string(menu) << "Sucessfule Draw"<< endl;
            window.draw(list);
        }
    }
}

void Menu::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(MouseEvents<InputBox>::mouseClicked(input, window)){
        if(State::isStateEnabled(State::BAR)){
            State::setStateEnable(State::BAR, false);
        }
        else
            State::setStateEnable(State::BAR, true);

        // cout << "Menu Show state (0-F, 1-T)" << State::isStateEnabled(State::BAR) << endl;
    }
    
    if(State::isStateEnabled(State::BAR)){
        State::setStateEnable(State::KEEP, true);
            list.addEventHandler(window, event);
            // cout << "Menu Show state (0-F, 1-T) --------- " << State::isStateEnabled(State::BAR) << endl;
        if(MouseEvents<InputBox>::hovered(input, window)){
            MenuTitleHov = input.getText();//close to the title, menu = the title of the menu
            // cout << data << " Out put the data <<<<<<"<< endl;
        }
    }else{
        ClickItem = list.GetClicked();
    }
    // cout << "Menu Show state (0-F, 1-T)" << State::isStateEnabled(State::BAR) << endl;
}

void Menu::update(){
    inputdata = input.getText();
    if(MenuTitleHov == inputdata){
        State::setStateEnable(State::KEEP, true);
    }else {
        State::setStateEnable(State::KEEP, false);
    }
    // cout << string(inputdata) << " Out put the Inputdata <<<<<<"<< endl;
}



sf::String Menu::getMenu(){
    return MenuTitleHov;
}

sf::String Menu::getInputBox(){
    return input.getText();
}

void Menu::menuSet(sf::String m){
    MenuTitleHov = m;
}
