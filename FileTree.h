#ifndef SFMLSET_FILETREE_H
#define SFMLSET_FILETREE_H

#include "FileNode.h"
#include "FileItem.h"
#include "Image.h"
#include <string>

class FileTree : public GUIComponents{
private:
    string click;
    //the root node of the tree
    FileNode* root = nullptr;
    // FileItem Item;
    sf::Vector2f initPosition = {0, 0};
    // sf::Vector2f position

    //finds the parent and add the item to the parent. 
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, std::string parent, std::string item, Image::image P, Image::image C);
    
    //traverses the tree ad adds the evenhandlers for each of the nodes
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);
    
public:
    //constructors
    FileTree();
    
    //this is the public version of push
    void push(std::string parent, std::string item, Image::image P, Image::image C);
    void traverse(sf::RenderWindow& window, sf::Event event);
    void Clean();
    void Clean(FileNode* &root);
    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    
    //does nothing now
    // virtual void applySnapshot(const Snapshot& snapshot);
    
    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void FindFile(FileNode* &root);
    string ClickFile(){return click;}
    // //does nothing now
    // virtual void update();
    // //does nothing now
    // virtual Snapshot& getSnapshot();
    // //does nothing now
    // virtual sf::FloatRect getGlobalBounds();
};

#endif