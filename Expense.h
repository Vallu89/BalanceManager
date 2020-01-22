#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{

    int expenseId;
    int userId;
    string date;
    int dateToInt;
    string item;
    float amount;

public:

    void setExpenseId( int expenseId );
    void setUserId( int userId );
    void setDate( string date );
    void setDateToInt( int dateToInt );
    void setItem ( string item );
    void setAmount ( float amount );

    int getExpenseId();
    int getUserId();
    string getDate();
    int getDateToInt();
    string getItem();
    float getAmount();

};

#endif // EXPENSE_H
