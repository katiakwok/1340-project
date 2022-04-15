
#include <iostream>
#include "../header/flow.hpp"

using namespace std;




int main(){
    int choice;
    cout<<"welcome to blackjack!\n If this is your first time playing, please click 3 to check out the story!"<<endl;
    
    do{
        menu();
        cin>>choice;
        switch (choice){
            case(1):
                play();
                break;
            case(2):
                break;
            case(3):{
                story();
            }
                break;
            case(4):
                cout<<endl;
                cout<<"credit"<<endl;
                cout<<"Chung Cheuk Man | UID: u3592807 | githubname:Maktub0630"<<endl;
                cout<<" | UID:  | githubname:"<<endl;
                cout<<endl;
                break;
            case(5):
                cout<<"saving the game"<<endl;
                break;
            case(6):
                cout<<"quitting the game"<<endl;
            default:
                break;
            
        }
    }
    while (choice!=6);
}