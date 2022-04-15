//flow.cpp
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include "../header/flow.hpp"
using namespace std;

void story(){
    ifstream fin;
    fin.open("storyline.txt");
    if ( fin.fail() ) {
      cout << "Error in file opening!"<< endl;
      exit(1);
    }
    string line;
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    fin.close();
}
void menu(){
    cout<<"menu: \n1: play\n2: show your record\n3: read the story\n4: credit\n5: save game\n6: quit the game"<<endl;
    cout<<"enter your number of choice: ";
}

int hit(int game){
    srand(time(NULL));
    int card=rand()%10 + 1;
    game+=card;
    return game;
}
int deal(int dealer, string *dealAction){
    if (dealer<=15){
        dealer=hit(dealer);
    }
    else if (dealer > 15){
        *dealAction="stand";
    }
    return dealer;
}
int play() {
    int bet;
    cout<<"input your bet: ";
    cin>>bet;
    while (bet<=0){
        cout<<"invalid bet!"<<endl;
        cout<<"input your bet: ";
        cin>>bet;
    }
    srand(time(NULL));
    int action;
    int player=rand() % 21 + 1;
    int dealer=rand() % 21 + 1;
    cout<<"you: "<<player<<' '<<"dealer: "<<dealer<<endl;
    string  dealAction;
    while (player<21 && dealer<21){
        cout<<"number of action: "<<endl;
        cout<<"1:hit"<<endl;
        cout<<"2:surrender"<<endl;
        cout<<"3:double down"<<endl;
        cout<<"4:stand"<<endl;
        cout<<"input the number of your action: ";
        cin>>action;
        dealer=deal(dealer,&dealAction);
        if (action==1){
            player=hit(player);
        }
        else if (action==2){
            break;
        }
        else if (action==3){
            bet=bet*2;
            player=hit(player);
            cout<<player<<' '<<dealer<<endl;
            break;
        }
        if (action == 4 && dealAction =="stand"){
            break;
        }
    cout<<"you: "<<player<<' '<<"dealer: "<<dealer<<endl;
    }
    if (player==dealer){
        cout<<"tie!"<<endl;
    }
    else if (action==2 || player>21 || (dealer<21 && player<21 && dealer > player) || dealer ==21){
        cout<<"you: "<<player<<' '<<"dealer: "<<dealer<<endl;
        if (player>21){
            cout<<"BUST!"<<endl;
        }
        cout<<"YOU LOSE "<<bet<<'!'<<endl;
        bet=-1*bet;
    }
    else if (player==21 || (dealer<21 && player <21 && player >dealer)) {
    cout<<"you: "<<player<<' '<<"dealer: "<<dealer<<endl;
        cout<<"YOU WIN "<<bet<<'!'<<endl;
    }
    return 0;
}