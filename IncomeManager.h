#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#include "FileWithIncome.h"
#include "Income.h"
#include "SupportMethod.h"
#include "Markup.h"

using namespace std;

class IncomeManager {

    Income income;
    FileWithIncome fileWithIncome;
    vector <Income> incomes;
    const int LOGGED_USER_ID;
    CMarkup xml;
    int lastIncomeId;

public:

    IncomeManager(string INCOMES_FILE_NAME, int loggedUserId)
        :fileWithIncome(INCOMES_FILE_NAME), LOGGED_USER_ID( loggedUserId )
    {
        lastIncomeId = 0;
    } ;
    int addIncome();
    double showAllIncomesInThisMonth();
    double showAllIncmoesFromPreviousMonth();
    double showAllIncomesFromPeriod(string fromDate, string toDate);
    int loadIncomesOfLoggedUserFromFile();
    vector <Income> &getIncomes() { return incomes; };
    Income getNewIncomeData();
    void showIncome(Income income);
    double IncomesFromPeriod(string fromDate, string toDate, bool wholeMonth);
    int getLastIncomeId() {return lastIncomeId;}
    void setLastIncomeId(int lastIncomeId)
        {this->lastIncomeId = lastIncomeId;}


};

#endif
