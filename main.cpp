
#include <iostream>
#include <vector>
#include "flow.hpp"

using namespace std;

int main(){
    std::vector<record> records;
    loadornew(records);
    int choice;
    cout<<"welcome to blackjack!\n If this is your first time playing, please click 3 to check out the story!"<<endl;
    do{
        menu();
        cin>>choice;
        cout<<"--------------------------------------------"<<endl;
        
        switch (choice){
            case(1):
                play(records);
                break;
            case(2):
                show(records);
                break;
            case(3):{
                story();
            }
                break;
            case(4):
                cout<<endl;
                cout<<"credit"<<endl;
                cout<<"Chung Cheuk Man | UID: 3035928079 | githubname:Maktub0630"<<endl;
                cout<<"Kwok Katia | UID: 3035927934 | githubname:katiakwok"<<endl;
                cout<<endl;
                break;
            case(5):
                cout<<"saving the game"<<endl;
                save(records,records.back().money,records.back().debt,records.back().due,records.back().hasDebt);
                break;
            case(6):
                cout<<"quitting the game"<<endl;
            default:
                break;
            
        }
    }
    while (choice!=6);
}
