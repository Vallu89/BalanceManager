#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include <vector>
#include "Income.h"
#include "TextFile.h"
#include "Markup.h"


using namespace std;

class FileWithIncome: public TextFile {

    Income getIncomesData();
    CMarkup xml;

public:
    FileWithIncome(string incomeFileName)
        :TextFile( incomeFileName ){};

    void writeIncomesIntoFile( Income income );
    vector <Income> loadIncomesOfLoggedUserFromFile();
    void saveAllToFile();

};

#endif
