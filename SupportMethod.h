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
    static string getNumber( string text, int charPosition );
    static string loadLine();
    static short howManyDaysHaveMonth( string date );
    static bool isLeapYear( string date );
    static int periodBetweenDates();
    static char loadChar();
    //static bool isProperDate(); <-- TO DO
};

#endif
