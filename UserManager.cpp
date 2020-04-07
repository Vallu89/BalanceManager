# include "UserManager.h"

int UserManager::downloadNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::isLoginExist( string login )
{
    for (int i = 0; i< users.size(); i++){
        if ( users[i].getLogin() == login ){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;

}

string UserManager::loadLine()
{
    string enter = "";
    getline(cin, enter);
    return enter;
}

int UserManager::logonUser(){

    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int trial = 3; trial > 0; trial--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << trial << ": ";
                password = loadLine();

                if ( itr -> getPassword() == password )
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedUserId = itr -> getUserId();
                    return loggedUserId;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserManager::registrationUser(){

    User user = giveNewUserData();

    users.push_back( user );
    fileWithUsers.writeUserIntoFile( user );

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::writeAllUsers(){

    for (int i = 0; i< users.size(); i++){

        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        }
}

vector <User> UserManager::changePasswordOfLoggedUser()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == loggedUserId)
        {
            itr -> setPassword( newPassword );
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changeUsersPassword( newPassword, loggedUserId );
    return users;
}

void UserManager::logoutUser(){

    loggedUserId = 0;
}

bool UserManager::isUserLogged(){

    if (loggedUserId > 0)
        return true;
    else
        return false;
}

User UserManager::giveNewUserData()
{
    User user;

    user.setUserId(downloadNewUserId());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);

    } while (isLoginExist( user.getLogin()) == true );

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserManager::getIdOfLoggedUser(){

    return loggedUserId;
}
