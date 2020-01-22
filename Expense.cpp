#include "Expense.h"

void Expense::setExpenseId ( int expenseId ){

    this->expenseId = expenseId;
}

void Expense::setUserId ( int userId ){

    this->userId = userId;
}

void Expense::setDate ( string date ){

    this->date = date;
}

void Expense::setDateToInt( int dateToInt ){

    this->dateToInt = dateToInt;
}

void Expense::setItem ( string item ){

    this->item = item;
}

void Expense::setAmount ( float amount ){

    this->amount = amount;
}

int Expense::getExpenseId(){

    return expenseId;
}

int Expense::getUserId(){

    return userId;
}

string Expense::getDate(){

    return date;
}

int Expense::getDateToInt(){

    return dateToInt;
}


string Expense::getItem(){

    return item;
}

float Expense::getAmount(){

    return amount;
}
