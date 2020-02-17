#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

using namespace std;

#include "Expense.h"
#include "FileWithExpense.h"
#include "SupportMethod.h"
#include "Markup.h"

class ExpenseManager{

    FileWithExpense fileWithExpense;
    vector <Expense> expenses;
    const int LOGGED_USER_ID;
    CMarkup xml;

public:

    ExpenseManager(string EXPENSES_FILE_NAME, int loggedUserId)
        :fileWithExpense(EXPENSES_FILE_NAME), LOGGED_USER_ID( loggedUserId ){} ;;
    void addExpense();
    void showAllExpenseInThisMonth();
    void showAllExpensesFromPrevousMonth();
    void showAllExpenseFromPeriod();
    vector <Expense> &getExpenses() { return expenses; };
    int loadExpensesOfLoggedUserFromFile();

};

#endif
