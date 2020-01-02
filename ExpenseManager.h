#ifndef ADRESAT_H
#define ADRESAT_H

using namespace std;

#include "SupportMethod.h"
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

class ExpenseManager{

    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;

    char choice;

public:

    BalanceManager(){};
    ~BalanceManager(){};

    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void addIncome();
    void addExpense();
    void showThisMonthBalance();
    void showPreviousMonthBalance();
    void showBalanceFromPeriod();

};

#endif
