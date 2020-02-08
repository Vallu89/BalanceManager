#ifndef ADRESAT_H
#define ADRESAT_H

using namespace std;

#include "SupportMethod.h"
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

class BalanceManager{

    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;

    char choice;

public:

    BalanceManager( string USERS_FILE_NAME )
        : userManager(USERS_FILE_NAME)
    {
        incomeManager = NULL;
        expenseManager = NULL;
    };

    ~BalanceManager()
    {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    };

    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void addIncome();
    void addExpense();
    void showThisMonthBalance();
    void showPreviousMonthBalance();
    void showBalanceFromPeriod();

};

#endif
