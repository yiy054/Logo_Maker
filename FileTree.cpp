#include "FileTree.h"

    
    //finds the parent and add the item to the parent. 
    // If the parent isn't found, a new parent is created
    void FileTree::push(FileNode* &root, string parent, string item, Image::image P, Image::image C){

        // FileItem item(Image::FOLDER, item, (0.1f,0.1f),initPosition);
        sf::Vector2f size(0.1f,0.1f);
        // FileItem item = new FileItem;
        Image::image iconC = C;
        // cout << "PUSH START" << endl;
        // cout << item << endl;
        // cout << item.at(1) << endl;
        FileNode *n = new FileNode(iconC, item, size,initPosition);
        // n->set;
        // FileNode node(Image::FOLDER, item, size,initPosition);

        if(root == nullptr){
            Image::image iconP = P;
            root = new FileNode(iconP, parent, size,initPosition);
            // FileNode h(Image::FOLDER, parent, size,initPosition);
            // FileNode *p = new FileNode;
            // p->set(Image::FOLDER, parent, size,initPosition);
            // root->setData(p->getData());
            // cout << "Parent: " << parent << " Children: " << item << endl;
            root->children.insert(pair<string, FileNode*> (item, n));
            return;
        }
        if(root->label == parent){
            root->children.insert(pair<string, FileNode*> (item, n));
            // cout << "Parent: " << root->label << " Children: " << item << endl;
            return;
        }
        for(auto iter = root->children.begin(); iter != root->children.end(); ++iter){
            // root->children.insert(pair<string, FileNode*>(item, node&));
            push(iter->second, parent, item, P, C);
        }
        return;   
    }
    
    // //traverses the tree ad adds the evenhandlers for each of the nodes
    void FileTree::traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event){
        if(root == nullptr){
            return;
        }
        for(auto itr = root->children.begin(); itr != root->children.end(); itr++){
            root = itr->second;
            if(root != nullptr){
                traverse(root, window,event);
            }
        }
        return;
    }

    FileTree::FileTree(){
        // // push("File", "NULL");
        // sf::Vector2f size(0.1f,0.1f);
        // // FileNode *n = new FileNode;
        // // n->set(Image::FOLDER, "item", size,initPosition);
        // FileNode n(Image::FOLDER, "item", size,initPosition);
        // root->setData(n.getData());
        // root = new FileNode(Image::FOLDER, "item", size,initPosition);
    }
    
    // //this is the public version of push
    void FileTree::push(std::string parent, std::string item, Image::image P, Image::image C){
        push(root, parent, item, P, C);
    }
    void FileTree::traverse(sf::RenderWindow& window, sf::Event event){
        traverse(root, window, event);
    }

    //draws the root node of the tree
    void FileTree::draw(sf::RenderTarget& window, sf::RenderStates states) const{
        window.draw(*root);
        // for(auto itr = root->children.begin(); itr != root->children.end(); itr++){
        //     window.draw(root->getData());
        // }
    }

    //calls the traverse function to add the event handlers to each node
    void FileTree::addEventHandler(sf::RenderWindow& window, sf::Event event){
        root->addEventHandler(window,event);
    }

    void FileTree::update(){
        // root->update();
        if((*root).state){
            FindFile(root);
        }
    }
    void FileTree::Clean(FileNode* &root){
        for(auto itr = root->children.begin(); itr != root->children.end(); itr++){
            root = itr->second;
            if(root->children.empty()){
                delete root;
                return;
            }else{
                Clean(root);
                return;
            }
        }
        return;
    }
    void FileTree::Clean(){
        Clean(root);
    }
    void FileTree::FindFile(FileNode* &root){
        if((*root).state && (*root).children.empty()){
            click = (*root).click;
        }
        for(auto itr = root->children.begin(); itr != root->children.end(); itr++){
            FindFile(itr->second);
        }
        return;
    }