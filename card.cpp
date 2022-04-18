#include <iostream>
#include <iomanip>
#include <string>
#define SPADE "\xE2\x99\xA0"
#define CLUB "\xE2\x99\xA3"
#define HEART "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
using namespace std;

void DealHand(int cards[])
{
    int x;
    srand(time(NULL));
    for (int i=0; i<5; i++){
        int RNG = rand()%52;
        cards[i] = RNG; //put random into the array
    }
}

void PrintHand(int cards[], string num[],string suits[])
{
    for (int i=0; i<2; i++){
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
            
        cout<<num[i]<<suits[i]<<" ";
    }
}

int sumup(string num[5])
{
    int points = 0;
    for (int i=0; i<2; i++){
      if (num[i] == "A") {	
			  points+=11;	
		  }
      else if (num[i] >"9") {	
        points += 10;
      }
		  else {	
			  points += stoi(num[i]);
		  }
    }
    if (num->length()>=3){
      for (int j=0;j<num->length();++j){
        if (num[j]=="A" && points>21){
          points-=10;
        }
      }
    }
    return points;
}

int hand() {
    int cards[5];
    DealHand(cards);
    string num[5];
    string suits[5];
    PrintHand(cards,num,suits);
    cout<<endl;
    int point=sumup(num);
    cout<<point<<endl;
    return 0;
}
