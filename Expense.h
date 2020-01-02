#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{

    int expenseId;
    int userId;
    string date;
    string item;
    float amount;

public:

    void setExpenseId( int expenseId );
    void setUserId( int userId );
    void setDate( string date );
    void setItem ( string item );
    void setAmount ( float amount );

    int getExpenseId();
    int getUserId();
    string getDate();
    string getItem();
    float getAmount();

};

#endif // EXPENSE_H
