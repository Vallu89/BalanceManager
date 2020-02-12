#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include "Income.h"
#include "TextFile.h"

using namespace std;

class FileWithIncome: public TextFile {

    Income getIncomesData();

public:
    FileWithIncome(string incomeFileName)
        :TextFile( incomeFileName ){};

    void writeIncomesIntoFile( Income income );
    vector<Income> loadIncomesOfLoggedUserFromFile();
    void saveAllToFile();

};

#endif
