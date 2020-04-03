#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H

#include "Expense.h"
#include "TextFile.h"
#include "Markup.h"
#include <string.h>

using namespace std;

class FileWithExpense: public TextFile {

    Expense getExpensesData();
    CMarkup xml;

public:
    FileWithExpense(string expenseFileName)
        :TextFile( expenseFileName ){};

    int loadExpensesOfLoggedUserFromFile();
    void writeExpensesIntoFile( Expense expense );
    void saveAllExpensesToFile();
};

#endif
