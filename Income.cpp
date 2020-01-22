#include "Income.h"

void Income::setIncomeId( int incomeId ){

    this->incomeId = incomeId;
}

void Income::setUserId( int userId ){

    this->userId = userId;
}

void Income::setDate( string date ){

    this->date = date;
}

void Income::setDateToInt( int dateToInt ){

    this->dateToInt = dateToInt;
}

void Income::setItem ( string item ){

    this->item = item;
}

void Income::setAmount ( float amount ){

    this->amount = amount;
}

int Income::getIncomeId(){

    return incomeId;
}

int Income::getUserId(){

    return userId;
}

string Income::getDate(){

    return date;
}

int Income::getDateToInt(){

    return dateToInt;
}

string Income::getItem(){

    return item;
}

float Income::getAmount(){

    return amount;
}
