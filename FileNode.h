#ifndef SFMLSET_FILENODE_H
#define SFMLSET_FILENODE_H


#include "GUIComponents.h"
#include "SnapShot.h"
#include "FileItem.h"
#include "Image.h"
#include "State.h"
#include <list>
#include <map>
#include <iterator>
#include <iostream>
using namespace std;


class FileNode: public sf::Transformable, public sf::Drawable {
public:
    //This is the data represented in the tree
    FileItem Item;
    string label;
    //this is all the child nodes in the tree, a vector would also work just fine
    map<string, FileNode*> children;
    // vector<FileItem*> chil;
    bool state;
    string click;
    // state = false;
    sf::Vector2f const Reposition;
    // list <FileNode> chil;
    
    //this tells the draw function whether or not to show the node's children
    //this is done by toggling a state on and off
    void toggleChlidren();
    
    //this is called in the draw function to reposition the children so they 
    //are indented and below the parent
    void reposition() const;

    // this is so I can use the iterator for the children map publicly
    // typedef typename list<FileNode> ::iterator iterator;
    typedef typename map<string, FileNode*>::iterator Iterator;
    FileNode();
    FileNode(FileItem data): Item(data){}
    FileNode(Image::image icon, string text, sf::Vector2f size, sf::Vector2f position);
    
    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    
    //This is not currently used
    // virtual void applySnapshot(const Snapshot& snapshot);
    
    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    void update();


    //returns true if the node has no children, otherwise false
    bool isLeaf() const;

    //getters and setters
    FileItem& getData();
    map<string, FileNode*>& getChildren();
    sf::FloatRect getGlobalBounds() const;
    // FileNode* getNode(){return ;}
    // FileNode* getChildren();

    void setPosition(float x, float y);
    void setData(const FileItem &data);
    void set(Image::image icon, string text, sf::Vector2f size, sf::Vector2f position);
    // void insert(map<string, FileNode*> children);
    void printTree();
    // iterators
    map<string, FileNode*>::iterator begin();
    map<string, FileNode*>::iterator end() ;

    void FindClick();
    string ClickFile();
};

#endif