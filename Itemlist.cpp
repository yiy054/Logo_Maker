
#include "Itemlist.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// All Initial Setting ---------------------------------------

Itemlist::Itemlist(){}

Itemlist::Itemlist(vector<string> vector){
    for(int i = 0; i < vector.size(); ++i){
        Insert(vector.at(i), 3 , 250);
    }
    size = list.size();
};

void Itemlist::SetPosition(float x, float y){
    // this->x = x;
    this->y = y;
    int index = 0;
    auto iter = list.begin();
    for(; iter != list.end(); ++iter){
        (*iter).Position(x, y + (index * 60));
        ++index;
        // cout << "list Position Set: " << x << " " << y + index * 100 << endl;
    }
}

void Itemlist::Insert(sf::String i, int n, float width){
    Item item;
    item.String(i);
    item.SetFontLoc(n);
    item.BoxSetSize({width,item.getGlobalBounds().height});
    y += item.getGlobalBounds().height;
    item.Position(0.f, y);
    // cout << "Item Font call and set Correct " << n << endl;
    list.push_back(item);
}

void Itemlist::SetSize(int n){
    auto iter = list.begin();
    sf::Vector2f pos = (*iter).GetPosition();
    for(; iter != list.end(); ++iter){
        (*iter).SetSize(n);
    }
    SetPosition(pos.x, pos.y);
}

//////////////////////////////////////////////////////////////////
//AddEVentHandle Updata Window DRAW  -------------------------------

void Itemlist::addEventHandler(sf::RenderWindow& window, sf::Event event){
    auto iter = list.begin();
    for(; iter != list.end(); ++iter){
        if(MouseEvents<Item>::hovered(*iter, window)){
            (*iter).SetColor(sf::Color::Blue);
            string data = (*iter).GetString();
            // cout << data << endl;
        }else{
            (*iter).SetColor(sf::Color::Black);
        }
        
        if(MouseEvents<Item>::mouseClicked(*iter, window)){
            // if mouse clicked on an option, closed the bar
            // set clicked state to be true
            State::setStateEnable(State::APPEAR, false);
            State::setStateEnable(State::CLICKED, true);
            State::setStateEnable(State::BAR, false);
            chose = (*iter).GetString();
            clickFont = (*iter).FontLoc;
            // cout << chose << endl;
            if(chose == "Close Project"){
                State::setStateEnable(State::CLOSE, true); break;
            }
            if(chose == "New Project"){
                State::setStateEnable(State::NEW, true); break;
            }
            if(chose == "Open Project"){
                State::setStateEnable(State::OPEN, true); break;
            }
            if(chose == "Quit"){
                State::setStateEnable(State::QUIT, true); break;
            }
            if(chose == "Save Project"){
                State::setStateEnable(State::SAVE, true); break;
            }
            if(chose == "Expert Image"){
                State::setStateEnable(State::IMAGE, true); break;
            }
            // "New Project", "Quit", "Save Project", Expert Image
        }
    }
}

void Itemlist::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    auto iter = list.cbegin();
    for(;iter != list.cend(); ++iter){
        window.draw(*iter);
    }
}
void Itemlist::update(){

}

//////////////////////////////////////////////////////////////////
//Return All Data  -------------------------------
string Itemlist::GetClicked(){
    return chose;
}

int Itemlist::GetClickFont(){
    return clickFont;
}

string Itemlist::GetClickedByLoc(int n){
    clickFont = n;
    auto iter = list.begin();
    for(; iter != list.end(); ++iter){
        if((*iter).FontLoc == n){
            chose = (*iter).Getstring();
        }
    }
    return chose;
}


