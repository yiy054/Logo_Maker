#include "Logo.h"

Logo::Logo(){
    input.SetSize(50);
    input.SetPosition({2100,650});
    // vector<string> vector{"item1", "item2", "item3", "item4", "item5"};
    // Bar.VecSet(vector);
    vector<string> File{"Close Project", "New Project", "Open Project", "Quit", "Save Project"};
    vector<string> Render{"Expert Image"};
    Bar.VecSet(File, "File", 300);
    Bar.VecSet(Render, "Render", 300);
    // newWindow.winOpen();
    // texture.create(2800, 1650);
}

void Logo::update(){
    input.update();
    Bar.update();
    // text = input.getText();
    // for(auto iter = text.cbegin(); iter!= text.cend(); iter++){
    //     board.push(*iter);
    // }
    newWindow.update();
    OpenFileName = newWindow.ReturnClick();
    // cout << OpenFileName << endl;
    // char loc = char(OpenFileName);
    if(OpenFileName != "CONNOT FIND"){
        cout << "Sucessfule open" << OpenFileName << endl;
        input.FileOpen(OpenFileName);
        newWindow.initialClick();
    }
    if(State::isStateEnabled(State::NEW)){
        // texture.update();
        input.clean();
        State::setStateEnable(State::NEW, false);
    }
}
void Logo::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(input);
    window.draw(Bar);
    window.draw(newWindow);
}
void Logo::addEventHandler(sf::RenderWindow& window, sf::Event event){
    input.addEventHandler(window,event);
    Bar.addEventHandler(window,event);
    newWindow.addEventHandler(window,event);
    // newWindow.winOpen();
    // texture.update(window);
    
}