//flow.hpp


#ifndef flow_hpp
#define flow_hpp
#include <vector>
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

void story();

void menu();

void askLoan(std::vector <record> &records);

void save(std::vector <record>& records, int money, int debt, int due, bool hasDebt);

void play(std::vector <record>& records);

void show(std::vector<record>& records);

void loadornew(std::vector <record> &records);



#endif
