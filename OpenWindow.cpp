#include "OpenWindow.h"


OpenWindow::OpenWindow() {
    // popWin.create(sf::VideoMode(500, 500), "File Open");
    open = false;
    tree = false;
    path str("../Image");
    cout << "Start Push Tree" << endl;
    // floder.Clean();
    if (exists(str)){
        tree = true;
        directory_entry entry(str);	
        if (entry.status().type() == file_type::directory)
            cout << "Find The Path" << endl;
        PushTree(str);
    }
    input.String("Input");
    input.SetSize(40);
    input.BoxSetSize();
    input.Position({300,400});  
}

void OpenWindow::PushTree(path str){
    directory_iterator list(str);	      
    for (auto& it:list) {
        cout << it.path().filename()<< endl;
        if(it.status().type() == file_type::directory){
            floder.push(str.filename(), it.path().filename(), Image::FOLDER, Image::FOLDER);
            path str(it.path());
            PushTree(str);
        }else{
            floder.push(str.filename(), it.path().filename(), Image::FOLDER, Image::FILE);
        }
    }
}
    


void OpenWindow::winOpen(){
    if (open) {
        sf::Event popevent;
        // cout << "Open Window" << endl;
        while (popWin.pollEvent(popevent)) {
            if (popevent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::F2)) {
                open = false;
                cout << "Winow Close" << endl;
                State::setStateEnable(State::OPEN, false);
                popWin.close();
            }
            if(tree){
                floder.addEventHandler(popWin,popevent);
                if(MouseEvents<Item>::mouseClicked(input, popWin)){
                    floder.update();
                    click = floder.ClickFile();
                    State::setStateEnable(State::OPEN, false);
                    popWin.close();
                }
            }
        }
        popWin.clear(popWinColor);
        if(tree){
            floder.update();
            popWin.draw(floder);
            popWin.draw(input);
        }
        popWin.display();
    }else{
        popWin.close();
    }
}
string OpenWindow::ReturnClick(){
    path str("/Users/yiyao/Desktop/MtSac/CS008/SFMLset/Image");
    if (exists(str)){
        directory_entry entry(str);	
        if (entry.status().type() == file_type::directory){
            // cout << "Find The Path" << endl;
            directory_iterator list(str);	      
            for (auto& it:list) {
                // cout << it.path().filename()<< endl;
                if(click == it.path().filename()){
                    string click = it.path();
                    return click;
                }
            }
        }   
    }
    return "CONNOT FIND";
}

void OpenWindow::update(){
    winOpen();
}
void OpenWindow::draw(sf::RenderTarget& window, sf::RenderStates states) const{

}
void OpenWindow::addEventHandler(sf::RenderWindow& window, sf::Event event){
    if(State::isStateEnabled(State::OPEN)){
        open = true;
        // cout << "OPEN WINDOW" << endl;
        popWin.create(sf::VideoMode(500, 500), "File Open");
        State::setStateEnable(State::OPEN, false);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)){
        open = false;
    }
}