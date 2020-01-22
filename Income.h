#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{

    int incomeId;
    int userId;
    string date;
    int dateToInt;
    string item;
    float amount;

public:

    void setIncomeId( int incomeId );
    void setUserId( int userId );
    void setDate( string date );
    void setDateToInt( int dateToInt );
    void setItem ( string item );
    void setAmount ( float amount );

    int getIncomeId();
    int getUserId();
    string getDate();
    int getDateToInt();
    string getItem();
    float getAmount();

};


#endif
