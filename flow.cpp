//flow.cpp
#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <sstream>
#include "../header/flow.hpp"
#include "../header/card.cpp"
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
    cout<<"--------------------------------------------"<<endl;

}
void menu(){
    cout<<"menu: \n1: play\n2: show your record\n3: read the story\n4: credit\n5: save game\n6: quit the game"<<endl;
    cout<<"--------------------------------------------"<<endl;
    cout<<"enter your number of choice: ";
}
void clear(){
    std::ofstream ofs;
    ofs.open("save.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
void askLoan(std::vector<record> &records) {
    if (records.back().money <= 0) {
        cout << "You lost all your money! You must loan" << endl;  
    }
    cout << "How much do you want to loan?\n input your loan: ";
    int loan,maxloan=100000, readcount = 5;
    cin>>loan;
    while(loan > maxloan){
        cout<<"no you cant borrow this ton of money\n input your loan: ";
        cin>>loan;
    }
    save(records,records.back().money+loan,loan,readcount,true);
    
    cout << "Loan successful !" << endl;
    cout << "Due after " << records.back().due << " rounds starting from loan date" <<endl;
    cout << "Interest rate : 1.5" << endl;
}

void postgame(std::vector<record> records,int bet){
    if(records.back().hasDebt==0){
        save(records,records.back().money+bet,records.back().debt,records.back().due,records.back().hasDebt);
    }
    else{
        if (records.back().hasDebt==1 && records.back().due>0 && records.back().debt>0){
            save(records,records.back().money+bet,records.back().debt*1.5,records.back().due-1,records.back().hasDebt);
            cout << "Due after " << records.back().due << " rounds starting from loan date" <<endl;    
        }
        else if (records.back().due==0 && records.back().debt > 0) {
            cout << "You are being chased by the gang! " << endl;
            cout << "oh no you run so slow!" << endl;
            cout << "YOU DIED!" << endl;
            records.clear();
            //back to main
        }
    }
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

void play(std::vector<record> &records) {
    int bet;
    cout<<"input your bet: ";
    cin>>bet;
    while (bet<1 || records.back().money <bet){
        cout<<"invalid input\n please input again: ";
        cin>>bet;
    }
    srand(time(NULL));
    int action;
    int player=rand() % 21 + 1;
    int dealer=rand() % 21 + 1;
    cout<<"you: "<<player<<' '<<"dealer: "<<dealer<<endl;
    string  dealAction;
    while (player<21 && dealer<21){
        cout<<"--------------------------------------------\nnumber of action: "<<endl;
        cout<<"1:hit"<<endl;
        cout<<"2:surrender"<<endl;
        cout<<"3:double down"<<endl;
        cout<<"4:stand"<<endl;
        cout<<"--------------------------------------------"<<endl;
        cout<<"input the number of your action: ";
        cin>>action;
        cout<<"--------------------------------------------"<<endl;
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
        bet=0;
    }
    else if (action==2 || player>21 || (dealer<21 && player<21 && dealer > player) || dealer ==21){
        if (player>21){
            cout<<"BUST!"<<endl;
        }
        cout<<"YOU LOSE "<<bet<<'!'<<endl;
        bet=-1*bet;
    }
    else if (player==21 || dealer>21|| (dealer<21 && player <21 && player >dealer)) {
        cout<<"YOU WIN "<<bet<<'!'<<endl;
    }

    if (records.back().hasDebt==1 && records.back().due-1==0 && records.back().debt > 0) {
            cout << "\nYou are being chased by the gang! " << endl;
            cout << "oh no you run so slow!" << endl;
            cout << "YOU DIED!" << endl;
            records.clear();
            clear();
            loadornew(records);
            //back to main
        }
    else{
        if(records.back().hasDebt==0){
            save(records,records.back().money+bet,records.back().debt,records.back().due,records.back().hasDebt);
        }
        else if (records.back().hasDebt==1 && records.back().due>0 && records.back().debt>0){
            save(records,records.back().money+bet,records.back().debt*1.5,records.back().due-1,records.back().hasDebt);
            cout << "Due after " << records.back().due << " rounds starting from loan date" <<endl;    
            
        }
        if (records.back().money<=0){
                cout<<"you are broke! You must borrow money!"<<endl;
                askLoan(records);
        }
        else{
            int respond;
            if (records.back().hasDebt==true){
                cout<< "--------------------------------------------\nDo you want to pay debt?\n1:yes\n2:no\n--------------------------------------------"<<endl;
                cin>>respond;
                if (respond == 1){
                    cout<<"input the amount of loan you want to pay: ";
                    int pay;
                    cin>>pay;
                    while (pay <0 || pay >records.back().money){
                        cout<<"invalid input! please try again: ";
                        cin>>pay;
                    }
                    save(records,records.back().money-pay,records.back().debt-pay,records.back().due,records.back().hasDebt);
                    if (records.back().debt==0 && records.back().money>0){
                        cout<<"you have paid all of your debt!"<<endl;
                        save(records,records.back().money,0,0,false);
                    }
                }
            }
            cout<<"--------------------------------------------\nwant to borrow some money?\n1:yes\n2:no\n--------------------------------------------\ninput your option: ";
            cin>>respond;
            cout<<"--------------------------------------------"<<endl;
            if (respond==1){
                if (records.back().hasDebt!=1){
                    askLoan(records);
                }
                else{
                    cout<<"you havent paid your loan!"<<endl;
                    cout<<"want to play or going back to menu?\n1:play\n2:menu\n--------------------------------------------\ninput your option: ";
                    cin>>respond;
                    cout<<"--------------------------------------------"<<endl;
                    if (respond==1){
                        play(records);
                    }
                }
            }
            else if (respond==2){
                cout<<"want to play or going back to menu?\n1:play\n2:menu\n--------------------------------------------\ninput your option: ";
                cin>>respond;
                cout<<"--------------------------------------------"<<endl;
                if (respond==1){
                    play(records);
                }
            }
        }
    }
}

void save(std::vector<record>& records,int money,int debt,int due,bool hasDebt){
    ofstream fout;
    fout.open("save.txt",ios::app);
    if ( fout.fail() ) {
      cout << "Sorry cant open the file."<< endl;
      exit(1);
    }
    record Newrecord(money,debt,due,hasDebt);
    records.push_back(Newrecord);
    fout<<records.back().money<<' '<<records.back().debt<<' '<<records.back().due<<' '<<records.back().hasDebt<<endl;
    
    fout.close();
}

void show(std::vector<record>& records){
    cout<<"money: "<<records.back().money<<" debt: "<<records.back().debt<<" due: "<<records.back().due<<" hasdebt: "<<records.back().hasDebt<<endl;
}



void loadornew(vector<record>& records){
    ifstream fin;
    fin.open("save.txt");
    if ( fin.fail() || fin.peek() == std::ifstream::traits_type::eof() ) {
        cout << "--------------------------------------------\nSorry cant open the file. starting new career...\n--------------------------------------------"<< endl;
        save(records,1000,0,0,0);
    }
    else{
        int money,due,debt,poscount=0,data[4];
        bool hasDebt;
        string line,str="";
        while(getline(fin,line)){
           for (int i=0;i<line.length();++i){
                if(line[i]!=' ') {
                    str+=line[i];
                }
                else {
                    data[poscount]=stoi(str);
                    data[3]=line[line.length()-1]-'0';
                    str="";
                    if (poscount<2) poscount++;
                    else {
                        poscount=0;
                    }
                }
            }
            str="";
            records.push_back(record(data[0],data[1],data[2],data[3]));
        }
    }
    fin.close();
}
