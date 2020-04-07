#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "TextFile.h"
#include "SupportMethod.h"
#include "Markup.h"

using namespace std;

class FileWithUsers : public TextFile {

    //const string USERS_FILE_NAME;

    //bool isFileEmpty();

    CMarkup xml;

    string changeRecipientDataToDataSeparatedByVerticalLines(User user);
    User getUserData(string SingularUserDataSeparateByVerticalLines);


public:

    FileWithUsers( string USERS_FILE_NAME )
        : TextFile( USERS_FILE_NAME ){};
    void writeUserIntoFile(User user);
    vector <User> loadUsersFromFile();
    void changeUsersPassword(string newPassword, int loggedUserId);
};


#endif
