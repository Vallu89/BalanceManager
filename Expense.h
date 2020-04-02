#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{

    int expenseId;
    int userId;
    string date;
    string item;
    double amount;
    int dateAsInt;

public:

    void setExpenseId( int expenseId );
    void setUserId( int userId );
    void setDate( string date );
    void setItem ( string item );
    void setAmount ( double amount );
    void setDateAsInt ( int dateAsInt );

    int getExpenseId();
    int getUserId();
    string getDate();
    string getItem();
    double getAmount();
    int getDateAsInt();

};

#endif // EXPENSE_H
