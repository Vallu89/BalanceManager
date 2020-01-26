#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "TextFile.h"
#include "SupportMethod.h"

using namespace std;

class FileWithUsers : public TextFile {

    //const string USERS_FILE_NAME;

    //bool isFileEmpty();
    string changeRecipientDataToDataSeparatedByVerticalLines(User user);
    User getUserData(string SingularUserDataSeparateByVerticalLines);


public:

    FileWithUsers( string FILENAME )
        : TextFile( FILENAME ){};
    void writeUserIntoFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);
};


#endif
