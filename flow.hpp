//flow.hpp


#ifndef flow_hpp
#define flow_hpp
#include <vector>
//construct the data type for the record
struct record{
    int money,debt,due;
    bool hasDebt;
    record(int money, int debt, int due, bool hasDebt){
        this->debt=debt;
        this->money=money;
        this->due=due;
        this->hasDebt=hasDebt;
    }
};
//displaying the story
void story();
//displaying the menu
void menu();
//borrowing money
void askLoan(std::vector <record> &records);
//saving the game record to the save.txt
void save(std::vector <record>& records, int money, int debt, int due, bool hasDebt);
//function of a round of blackjack
void play(std::vector <record>& records);
//showing latest record
void show(std::vector<record>& records);
//pregame setting
void loadornew(std::vector <record> &records);



#endif
