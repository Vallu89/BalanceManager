#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{

    int userId;
    int incomeId;
    string date;
    string item;
    float amount;

public:

    void setUserId( int userId );
    void setIncomeId( int incomeId );
    void setDate( string date );
    void setItem ( string item );
    void setAmount ( float amount );

    int getUserId();
    int getIncomeId();
    string getDate();
    string getItem();
    float getAmount();

};

#endif
