#ifndef SUPPORTMETHOD_H
#define SUPPORTMETHOD_H

using namespace std;

#include <iostream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>

class SupportMethod{

public:

    static string convertIntToString( int number );
    static int convertStringToInt( string number );
    static string convertActualDateToString();
    static int convertDateWithDashToInt( string date );
    static int convertDateToInt();
    static string getNumber( string text, int charPosition );
    static string loadLine();
    static int checkMonth();
    static int isLeapYear();
    static int periodBetweenDates();
    static char loadChar();
};

#endif
