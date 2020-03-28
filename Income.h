#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{

    int userId;
    int incomeId;
    string date;
    string item;
    double amount;

public:

    void setUserId( int userId );
    void setIncomeId( int incomeId );
    void setDate( string date );
    void setItem ( string item );
    void setAmount ( double amount );

    int getUserId();
    int getIncomeId();
    string getDate();
    string getItem();
    double getAmount();

};

#endif
