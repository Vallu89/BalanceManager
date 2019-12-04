#ifndef TEXTFILE_H
#define TEXTFILE_H

#include <iostream>
#include <fstream>

using namespace std;

class TextFile{

protected:
    const string FILE_NAME;

public:
    TextFile( string file_name ): FILE_NAME (file_name){};
    bool isFileEmpty(fstream &textFile);

};


#endif
