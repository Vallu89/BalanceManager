#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include "Income.h"
#include "TextFile.h"

using namespace std;

class FileWithIncome: public TextFile {

    bool isFileEmpty();
    Income getIncomesData();

public:
    FileWithIncome(string incomeFileName)
        :TextFile( incomeFileName ){};

    void writeIncomesIntoFile( Income income );
    vector<Income> loadIncomesFromFile();
    void saveAllToFile();

};

#endif
