#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

using namespace std;

#include "Expense.h"
#include "FileWithExpense.h"
#include "SupportMethod.h"

class ExpenseManager{

    FileWithExpense fileWithExpense;
    vector <Expense> expenses;
    const int LOGGED_USER_ID;

public:

    ExpenseManager();
    void addExpense();
    void showAllExpenseInThisMonth();
    void showAllExpensesFromPrevousMonth();
    void showAllExpenseFromPeriod();

};

#endif
