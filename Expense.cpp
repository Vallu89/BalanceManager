#include "Expense.h"

//--------Setters------------------------------

void Expense::setExpenseId ( int expenseId ){

    this->expenseId = expenseId;
}

void Expense::setUserId ( int userId ){

    this->userId = userId;
}

void Expense::setDate ( string date ){

    this->date = date;
}

void Expense::setItem ( string item ){

    this->item = item;
}

void Expense::setAmount ( double amount ){

    this->amount = amount;
}

void Expense::setDateAsInt( int dateAsInt )
{
    this->dateAsInt = dateAsInt;
}

//--------Getters------------------------------

int Expense::getExpenseId(){

    return expenseId;
}

int Expense::getUserId(){

    return userId;
}

string Expense::getDate(){

    return date;
}

string Expense::getItem(){

    return item;
}

double Expense::getAmount(){

    return amount;
}

int Expense::getDateAsInt()
{
    return dateAsInt;
}
