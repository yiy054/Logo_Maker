
#include "DropDown.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// All Initial Setting ---------------------------------------
DropDown::DropDown(){}

DropDown::DropDown(vector<string> vec){SetVec(vec);}

void DropDown::SetVec(vector<string> vec){
    menu.setPosition(input.GetPosition().x, input.getGlobalBounds().height + 5);
    for(int i = 0; i < vec.size(); i++){
        menu.Insert(vec.at(i), i+1, 250);
    }
}

void DropDown::SetTitle(string title){
    input.SetText(title, 3);
}

void DropDown::SetPosition(float x, float y){
    input.SetPosition({x, y});
    // cout << "Position: " << x << ", " << y << endl;
    menu.SetPosition(x, y + input.getGlobalBounds().height);
}

void DropDown::SetSize(int n){
    input.SetSize(n); 
    menu.SetSize(n);
}

void DropDown::SetClick(int n){
    click = n;
    input.SetText(menu.GetClickedByLoc(click),click);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AddEVentHandle Updata Window DRAW  -------------------------------

void DropDown::draw(sf::RenderTarget& window, sf::RenderStates State) const{
    window.draw(input);
    if(State::isStateEnabled(State::APPEAR))
        window.draw(menu);
}

void DropDown::addEventHandler(sf::RenderWindow& window, sf::Event event){
    // undo key
    if(
        ( sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem) )&&
        ( sf::Keyboard::isKeyPressed(sf::Keyboard::Z) )
       ){
        if(History::topHistory().getSnapshot() != ""){
            applySnapshot(History::topHistory());
            History::popHistory();
        }
    }
    if(MouseEvents<InputBox>::mouseClicked(input, window)){
        // cout << State::APPEAR << endl;
        if(State::isStateEnabled(State::APPEAR)){
            State::setStateEnable(State::APPEAR, false);
            // cout << State::APPEAR << endl;
        }
        else
            State::setStateEnable(State::APPEAR, true);

        // cout << State::APPEAR << endl;
    }
    if(State::isStateEnabled(State::APPEAR)){
        // cout << State::APPEAR << endl;
        menu.addEventHandler(window, event);
    }
}

void DropDown::update(){
    if(State::isStateEnabled(State::CLICKED)){
        History::pushHistory(getSnapShot());
        State::setStateEnable(State::CLICKED, false);
        input.SetText(menu.GetClicked(),menu.GetClickFont());
        // cout << menu.GetClicked() << ", " << menu.GetClickFont() << endl;
        click = menu.GetClickFont();
        // SetPosition(x, y);
        // input.SetPosition({x,y});
    }
}


//SNAP SHOT -----------------------------------------
//---------------------------------------------------
SnapShot& DropDown::getSnapShot(){
    snap.setString(input.getText());
    return snap;
}


void DropDown::applySnapshot(const SnapShot& snapshot){
    string other = snapshot.getSnapshot();
    input.SetText(other, 3);
    setPosition(x, y);
}

