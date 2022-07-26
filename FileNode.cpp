#include "FileNode.h"

//this tells the draw function whether or not to show the node's children
//this is done by toggling a state on and off
void FileNode::toggleChlidren(){
    if(state)
        state = false;
    else
        state = true;
}

//this is called in the draw function to reposition the children so they 
//are indented and below the parent
void FileNode::reposition() const{
    // int i = 0;
    // for(map<string, FileNode*>::iterator itr = children.begin();itr != children.end(); ++itr){
    //     itr->second->setPosition(Item.getPosition().x - 50, Item.getPosition().y - Item.getGlobalBounds().height*(i+1));
    //     i++;
    // }
    sf::Vector2f position(Item.getPosition().x + 50, Item.getPosition().y + Item.getGlobalBounds().height+ Item.getGlobalBounds().top);
    // Reposition.x = Item.getPosition().x - 50;
    // Reposition.y = Item.getPosition().y - Item.getGlobalBounds().height;
    // sf::Vector2<float>::Vector2	(	const Vector2< U > & 	vector	)	;
    // sf::Vector2f vec(const sf::Vector2f & position);
    // Item.setPosition({Item.getPosition().x - 50, Item.getPosition().y - Item.getGlobalBounds().height});
    // sf::FloatRect p = Item.getGlobalBounds();
    // float y = p.height;
    // cout << "Start Reputition" << endl;
    auto iter = children.begin();
    auto prev = children.begin();
    for(;iter != children.end(); ++iter){
        (*iter).second->Item.setPosition(position);
        // position.y += iter->second.getGlobalBounds().height;
        position.y += iter->second->getGlobalBounds().height;
    }
}



FileNode::FileNode(){
    sf::Vector2f initialsize(0.1f,0.1f);
    state = true;
    // FileItem *n = new FileItem;
    // n->String
    // FileItem item(Image::FOLDER, "NULL", initialsize, (0,0));
    // FileNode(item);
}

FileNode::FileNode(Image::image icon, std::string text, sf::Vector2f size, sf::Vector2f position):Item(icon, text, size, position){
    label = text;
}

void FileNode::set(Image::image icon, string text, sf::Vector2f size, sf::Vector2f position){
    // FileNode(icon, text, size, position);
    // label = text;
}


//this draws the node. This is a recursive function to draw all the children nodes as well
// this will only draw the node's children when it is in the proper state
void FileNode::draw(sf::RenderTarget& window, sf::RenderStates states) const{
    window.draw(Item);
    // cout << "DROW" << endl;
    if(!children.empty()){
        if(state){
            // list<FileNode>::iterator iter; 
            // for(iter = chil.begin();iter != chil.end(); ++iter){
            // // for(auto const &iter:FileNode){
            //     // window.draw(*iter);
            //     *iter->draw(window,states);
            // }
            for(std::map<std::string, FileNode*>::const_iterator itr = children.begin();itr != children.end(); ++itr)
            {
                // update();
                reposition();
                window.draw(*(itr->second));
            }
            // cout << "Draw In NODE" << endl;
        }else{
            // cout << "Not Chil" << endl;
            // reposition();
        }
    }
}

                //This is not currently used
                // virtual void applySnapshot(const Snapshot& snapshot);

//This calls the addEventHandler for all the children. It calls the toggleChildren function
// when the node's data (FileItem) is clicked on
void FileNode::addEventHandler(sf::RenderWindow& window, sf::Event event){
    Item.addEventHandler(window, event);
    
    // if(Item.getFillColor() == sf::Color::Blue && !state){
    //     toggleChlidren();
    //     update();
    //     cout << "OPEN FOLDER" << endl;
    // }
        // toggleChlidren();
    // if(MouseEvents<FileItem>::mouseClicked(Item, window) && state){
    //     // toggleChlidren();
    //     state = !state;
    //     // update();
    //     cout << "OPEN FOLDER mouse click check" << endl;
    // }
    // cout << state << endl;
    // state = Item.stateChange();
    click = Item.ClickData();
    if(click == label){
    //     state = true;
    //     update();
    // }else{
    //     state = false;
    //     reposition();
    // }
    // if(State::isStateEnabled(State::CLICKED)){
        // toggleChlidren();
        state = true;
        // cout << endl << endl << click << " position Star " << Item.Getstring() <<  endl;
        // cout << Item.getPosition().x << ", " << Item.getPosition().y << endl << endl;
        update();
        // cout << click << "position change" << endl;
        // reposition();
        // if(children == nullptr){
            // auto iter = children.begin();
            // for(; iter!= children.end(); ++iter){
            //     update();
            // }
        // }
        // cout << click << " " << label << endl;
        // cout << "OPEN FOLDER mouse click check" << endl;
    }else{
        state = false;
        // cout << "Close" << label << endl;
        // reposition();
    }
    // cout << endl << endl;
        // cout << "OPEN FOLDER state check" << endl;
    // }
    for(map<string, FileNode*>::const_iterator itr = children.begin(); itr != children.end(); ++itr)
    {
        itr->second->addEventHandler(window,event);
    }
}
void FileNode::printTree(){
    int i = 1;
    for(map<string, FileNode*>::iterator itr = children.begin();itr != children.end(); ++itr)
    {
        // cout << "childre " << i << " " << itr->first << endl;
        itr->second->printTree();
        i++;
    }
}
void FileNode::update(){
    // cout << "TREE" << Item.getstring() << endl;
    // printTree();

    int i = 0;
    // cout << "Map change "<< endl;
    // sf::Vector2f pos = Item.getPosition();
    for(map<string, FileNode*>::iterator itr = children.begin();itr != children.end(); ++itr)
    {
        // cout << itr->first << "(" << Item.getPosition().x + 50 << "," << Item.getPosition().y + Item.getGlobalBounds().height*(i+1) << " )" << endl;
        itr->second->setPosition(Item.getPosition().x + 50, Item.getPosition().y + Item.getGlobalBounds().height*(i+1));
        i++;
    }
    // reposition();
}

//returns true if the node has no children, otherwise false
bool FileNode::isLeaf() const{
    return children.size() == 0;
}

//getters and setters
FileItem& FileNode::getData(){
    return Item;
}
void FileNode::setData(const FileItem &data){
    // chil.insert(getChildren());
    // children.insert(pair<string, FileNode*>(1, data));
    Item = data;
    // cout << "data set" << endl;
}

// FileNode* FileNode::getChildren(){
//     FileNode* temp = new FileNode();
//     temp->Item = getData();
//     // temp->chil = new list<FileNode>;
//     return 
// }

map<string, FileNode*>& FileNode::getChildren(){
    return children;
}

// iterators?
map<string, FileNode*>::iterator FileNode::begin(){
    return children.begin();
}


map<string, FileNode*>::iterator FileNode::end(){
    return children.end();
}

void FileNode::setPosition(float x, float y){
    // cout <<Item.Getstring() << "(" << x << "," << y << ")" << endl;
    sf::Vector2f pos(x,y);
    Item.setPosition(pos);
    update();
}

// void FileNode::insert(string item, FileNode node){
//     // children.insert(map<string, FileNode*>(children));
// }

sf::FloatRect FileNode::getGlobalBounds() const{
    sf::FloatRect bound = Item.getGlobalBounds();
    // bound.height = 
    bound.width = Item.getGlobalBounds().width + 50 ;
    if(state){
        auto iter = children.begin();
        for(; iter != children.end(); ++iter){
            bound.height += iter->second->getGlobalBounds().height;
        }
    }
    return bound;
}

void FileNode::FindClick(){
    if(!children.empty()){
        auto iter = children.begin();
        for(; iter != children.end(); ++iter){
            
        }
    }
}

// string FileNode::ClickFile(){
//     if(state){
//         if(!children.empty()){
//             auto iter = children.begin();
//             for(; iter != children.end(); ++iter){
//                 return (*iter).second->ClickFile();
//             }
//         }
//         return label;
//     }
//     return "Null";
// }
