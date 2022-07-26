#ifndef SFMLSET_DROPDOWN_H
#define SFMLSET_DROPDOWN_H

#include "Itemlist.h"
#include "InputBox.h"
#include "History.h"
#include "GUIComponents.h"

class DropDown: public GUIComponents{
private:
    /* data */
    Itemlist menu;    // menu list
    SnapShot snap;    // Snapshot
    // InputBox box;
    InputBox input;   // each input box and change color when past
    float x, y;
    int click;
public:
    DropDown();
    DropDown(vector<string> vec);  // given list of string
    void SetVec(vector<string> vec);
    void SetPosition(float x, float y);
    void SetSize(int n);
    void SetTitle(string title);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();

    int GetClick(){return click;}
    void SetClick(int n);
    
    SnapShot& getSnapShot();
    void applySnapshot(const SnapShot& snapshot);
};

#endif