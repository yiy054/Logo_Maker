// #include "KeyBoard.h"

// void KeyBoard::addEventHandler(sf::RenderWindow& window, sf::Event event, type& typing){
//         if(event.text.unicode == 26){
//             if(typing.getHistory().isEmpty()){   // if is empty stack then clear the input
//                 cout << "is empty" << endl;
//                 string s = "";
//                 typing.getText().setString(s);
//                 typing.setInput(s);
//             }
//             else{    // if is not empty go back once
//                 string s = typing.getHistory().topHistory().getSnapshot();
//                 typing.getText().setString(s);
//                 typing.setInput(s);
//                 typing.getHistory().popHistory();
//                 cout << "undo" << endl;
//             }

//         }


//     if(event.type == sf::Event::KeyPressed){
//         if(event.key.code == sf::Keyboard::Enter){
//             if(typing.isStateEnable(READYTOTYPE)){
//                 typing.disableState(READYTOTYPE);
//                 cout << "Disable typing" << endl;
//             }
//             else{
//                 typing.enableState(READYTOTYPE);
//                 cout << "Ready to type!" << endl;
//             }


//         }
//     }

}