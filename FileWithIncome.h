#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include "income.h"
#include "TextFile.h"

using namespace std;

class FileWithIncome: public TextFile {


public:
    FileWithIncome(string incomeFileName)
        :TextFile( incomeFileName ){};


};

#endif
