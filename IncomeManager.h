#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>

#include "FileWithIncome.h"
#include "Income.h"
#include "SupportMethod.h"

using namespace std;

class IncomeManager {

    FileWithIncome fileWithIncome;
    vector <Income> incomes;
    const int LOGGED_USER_ID;

public:

    IncomeManager();
    void addIncome();
    void showAllIncomesInThisMonth();
    void showAllIncmoesFromPrevousMonth();
    void showAllIncomesFromPeriod();
};

#endif
