#include "FileItem.h"

    //Constructors
    FileItem::FileItem(){
        // Icon.setTexture(Image::getImage(Image::FILE));
        Icon.setScale(0.1f, 0.1f);
        Icon.setPosition(0.f,0.f);
        // item.String("text");
        item.Position(Icon.getGlobalBounds().width,0.f);
        // Icon.setTextureRect(10.f,10.f);
        state = false;
    }

    FileItem::FileItem(Image::image icon, string text, sf::Vector2f size, sf::Vector2f position){
        Icon.setTexture(Image::getImage(icon));
        Icon.setScale(size);
        Icon.setPosition(position);
        item.String(text);
        item.SetSize();
        item.Position(position.x+Icon.getGlobalBounds().width, position.y);
        state = false;
    }
    
    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    void FileItem::draw(sf::RenderTarget& window, sf::RenderStates states) const{
            window.draw(item);
            window.draw(Icon);
            // cout << "Dow once ---------" << endl;
            // cout << item.getstring() << endl;
    }
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    void FileItem::addEventHandler(sf::RenderWindow& window, sf::Event event){
        if(MouseEvents<Item>::mouseClicked(item, window)){
            // cout << state << endl;
            if(data == item.GetString()){
                // State::setStateEnable(State::CLICKED, false);
                // State::setStateEnable(State::APPEAR, false);
                item.SetColor(sf::Color::Transparent);
                data = "NULL";
                // cout << "Click Again" << endl;
                state = false;
            }
            else{
                // State::setStateEnable(State::CLICKED, true);
                // State::setStateEnable(State::APPEAR, true);
                item.SetColor(sf::Color::Blue);
                data = item.GetString();
                // cout << "Click ----- True Blue" << endl;
                // cout << data << endl;
                // state = true;
            }
            // cout << data << endl;
        }
    }
    //Returns the bounds of the item
    sf::FloatRect FileItem::getGlobalBounds() const{
        sf::FloatRect bound;
        bound.height = item.getGlobalBounds().height+10.f;
        bound.width = item.getGlobalBounds().width;
        // cout << "getGlobalBounds " << bound.width << ", " << bound.height << endl;
        return bound;
    }
    // //returns the size of the item
    // sf::Vector2f FileItem::getSize() const{

    // }
    //returns the size of the item
    sf::Vector2f FileItem::getPosition()const{
        // cout << item.getstring() << "string Test " << endl;
        // cout << "Get Position " << item.getstring() << item.getPosition().x << "," << item.getPosition().y << endl;
        // cout << item.getPosition()
        return item.getPosition();
    }
    //sets the position of the item
    void FileItem::setPosition(const sf::Vector2f pos) {
        Icon.setPosition(pos);
        item.Position(pos.x+Icon.getGlobalBounds().width, pos.y);
        // cout << item.getstring() << pos.x <<" " << pos.y << endl;
    }
    //uses an enum to change the icon to a folder or file
    // void setIcon(Image::image icon);

    sf::Color FileItem::GetFillColor(){
        return item.GetFillColor();
    }

    bool FileItem::stateChange(){
        // cout << state << endl;
        return state;
    }

    string FileItem::ClickData(){
        return data;
    }

    string FileItem::Getstring(){
        return item.Getstring();
    }