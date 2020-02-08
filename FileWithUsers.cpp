#include "FileWithUsers.h"

vector<User> FileWithUsers::loadUsersFromFile()
{
    vector<User> users;
    User user;
    xml.Load(FILE_NAME);
    xml.FindElem("Users");
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        user.setUserId( atoi( MCD_2PCSZ(xml.GetData()) ) );
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());

        users.push_back(user);

        xml.OutOfElem();
    }

    return users;
}
