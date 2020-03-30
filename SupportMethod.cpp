#include "SupportMethod.h"

string SupportMethod::convertIntToString( int number )
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int SupportMethod::convertStringToInt( string number )
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string SupportMethod::convertActualDateToString()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y-%m-%d",timeinfo);
    string str(buffer);

    return str;
}

string SupportMethod::getNumber( string text, int charPosition )
{
    string number = "";
    while(isdigit(text[charPosition]) == true)
    {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

string SupportMethod::loadLine()
{
    string entry = "";
    getline(cin, entry);
    return entry;
}

char SupportMethod::loadChar(){

    string enter = "";
    char sign  = {0};

    while (true)
    {
        getline(cin, enter);

        if (enter.length() == 1)
        {
            sign = enter[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}
