#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "FileWithUsers.h"
#include "User.h"

using namespace std;

class UserManager {

    int loggedUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    int downloadNewUserId();
    bool isLoginExist( string login );
    string loadLine();

public:

    UserManager(string USERS_FILE_NAME , int LOGGEDUSERID = 0 )
        :fileWithUsers( USERS_FILE_NAME ), loggedUserId( LOGGEDUSERID )
    {
        users = fileWithUsers.loadUsersFromFile();
    };
    int logonUser();
    void registrationUser();
    void writeAllUsers();
    void logoutUser();
    vector <User> changePasswordOfLoggedUser();
    int getIdOfLoggedUser();
    bool isUserLogged();
    User giveNewUserData();
};

#endif
