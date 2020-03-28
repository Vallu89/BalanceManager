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

void FileWithUsers::writeUserIntoFile( User user )
{
    xml.Load(FILE_NAME);
    if (!xml.FindElem("Users"))
        xml.AddElem("Users");
    xml.IntoElem();

    xml.AddElem("User");
    xml.IntoElem();

    xml.AddElem("UserId",user.getUserId());
    xml.AddElem("Login",user.getLogin());
    xml.AddElem("Password",user.getPassword());

    xml.Save(FILE_NAME);
}

void FileWithUsers::saveAllUsersToFile(vector <User> &users)
{
    //TO DO
}
