#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

using namespace std;

#include "Expense.h"
#include "FileWithExpense.h"
#include "SupportMethod.h"
#include "Markup.h"

class ExpenseManager{

    Expense expense;
    FileWithExpense fileWithExpense;
    vector <Expense> expenses;
    const int LOGGED_USER_ID;
    CMarkup xml;
    int lastExpenseId;

public:

    ExpenseManager(string EXPENSES_FILE_NAME, int loggedUserId)
        :fileWithExpense(EXPENSES_FILE_NAME), LOGGED_USER_ID( loggedUserId )
    {
        lastExpenseId = 0;
    };
    int addExpense();
    double showAllExpenseInThisMonth();
    double showAllExpensesFromPrevousMonth();
    double showAllExpenseFromPeriod();
    vector <Expense> &getExpenses() { return expenses; };
    int loadExpensesOfLoggedUserFromFile();
    Expense getNewExpenseData();
    int getLastExpenseId(){return lastExpenseId;}
    void setlastExpenseId(int lastExpenseId )
        {this->lastExpenseId = lastExpenseId;}

};

#endif
