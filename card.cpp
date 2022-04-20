#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "card.hpp"
#define SPADE "\xE2\x99\xA0"
#define CLUB "\xE2\x99\xA3"
#define HEART "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
using namespace std;
int usedcards[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},count=0;

void DealHand(int cards[])
{
    srand(time(NULL));
    for (int i=0; i<2; i++){
        int RNG = rand()%52;
        for (int j=0;j<10;j++){
            if (RNG==usedcards[j]){
                RNG = rand()%52;
            }
        }
        cards[i] = RNG;
        usedcards[count]=cards[i];
        count++;
    }
}

void PrintHand(int cards[], string num[],string suits[])
{
    for (int i=0; i<5; i++){
        int number = cards[i]%13;
        num[i] = number;
        if (number == 0)
            num[i]="A";
        if (number >0 && number <10)
            num[i]= to_string(number+1);
        if (number == 10)
            num[i]="J";
        if (number == 11)
            num[i]="Q";
        if (number == 12)
            num[i]="K";
        int suit = cards[i]/13;
        suits[i] = suit;
        if (suit == 0)
            suits[i]=SPADE;
        if (suit == 1)
            suits[i]=HEART;
        if (suit == 2)
            suits[i]=CLUB;
        if (suit == 3)
            suits[i]=DIAMOND;
    }
}

int sumup( int hand[])
{
    int points=0;
    for (int i=0;i<2;i++){
        if (hand[i]>=0 && hand[i]<52){
            if (hand[i]%13==0){
                points+=1;
            }
            else if(hand[i]%13==10 || hand[i]%13==11 || hand[i]%13==12){
                points+=10;
            }
            else{
                points+=hand[i]%13+1;
            }
        }
    }
    return points;
}

int playerhand(int cards[5]) {
    for (int j=0;j<10;j++){
            usedcards[j]=-1;
        }
        count=0;
    int point;
    DealHand(cards);
    string num[5];
    string suits[5];
    PrintHand(cards,num,suits);
    for (int i=0;i<2;++i){
        cout<<num[i]<<suits[i]<<" ";
    }
    point=sumup(cards);
    return point;
}

int dealerhand(int cards[5])
{
    int point;
    DealHand(cards);
    string num[5];
    string suits[5];
    PrintHand(cards,num,suits);
    cout<<num[0]<<suits[0]<<" **";
    point=sumup(cards);
    return point;
}



int hit(int hand[5]){
    int card=rand()%52,point;
    for ( int i=0;i<10;++i){
        if (card==usedcards[i]){
            card=rand()%52;
        }
    }
    for (int j=0;j<5;++j){
        if(hand[j]<0 || hand[j]>52){
            hand[j]=card;
            usedcards[count]=card;
            count++;
            break;
        }
    }
    if (card%13==0){
        point=1;
    }
    else if(card%13==10 || card%13==11 || card%13==12){
        point=10;
    }
    else{
        point=card%13+1;
    }
    string num[5];
    string suits[5];
    PrintHand(hand,num,suits);
    return point;
}
