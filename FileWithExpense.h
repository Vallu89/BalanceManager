#ifndef FILEWITHEXPENSE_H
#define FILEWITHEXPENSE_H

#include "Expense.h"
#include "TextFile.h"

using namespace std;

class FileWithExpense: public TextFile {


public:
    FileWithExpense(string expenseFileName)
        :TextFile( expenseFileName ){};


};

#endif
