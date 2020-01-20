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

    UserManager();
    int logonUser();
    void registrationUser();
    void writeAllUsers();
    void logoutUser();
    vector <User> changePasswordOfLoggedUser();
    int downloadIdOfLoggedUser();
    bool isUserLogged();
    User giveNewUserdata();
};

#endif
