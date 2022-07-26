#include "Board.h"

void Board::push(sf::Text t){
    list.push_back(t);
}









void Board::update(){

}
void Board::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    for(auto iter = list.cbegin(); iter != list.cend(); iter++){
        // std::string s;
        // s = (*iter).getString();
        // cout << s << endl;
        window.draw(*iter);
    }
}
void Board::addEventHandler(sf::RenderWindow& window, sf::Event event){

}