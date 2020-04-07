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
    char buffer[64]; // <-- Jakby coœ nie hula³o, warto siê tym zainteresowaæ :P

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%Y-%m-%d",timeinfo);
    string str(buffer);

    return str;
}

int SupportMethod::convertDateWithDashToInt( string date )
{
    int dateWithoutDashInInt;

    string dateWithoutDashes;
    for (char i : date)
    {
        if (i != '-')
            dateWithoutDashes +=i;
    }
    return dateWithoutDashInInt = convertStringToInt(dateWithoutDashes);
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

bool SupportMethod::isLeapYear( string date )
{
    int year = convertDateWithDashToInt( date ) / 10000;

    if ( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 )
        return true;
    else
        return false;
}

short SupportMethod::howManyDaysHaveMonth (string date)
{
    string month;
    short monthAsInt;

    for (int i = 5; i <= 6 ; i++ )
        month += date[i];
    monthAsInt = convertStringToInt( month );

    switch( monthAsInt )
    {
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10 :
        case 12 :
            return 31;
        case 2 :
            if ( isLeapYear( date ) )
                return 29;
            else
                return 28;
        default :
            return 30;
    }
}

bool SupportMethod::isProperDate( string date, int dateAsInt ) {


    if( date.length() == 10 ) {
        if ( dateAsInt >= 20000101 || dateAsInt <= convertDateWithDashToInt( convertActualDateToString() ))
        {
            if ( date[4] == '-' && date[7] == '-' )
            {
                if ( date[5] <= '1' && date[8] <= '3')
                    {
                        if ( dateAsInt % 100 <= howManyDaysHaveMonth( date ))
                            return true;
                        else
                        {
                            cout<<"Wybrany miesiac nie posiada takiej ilosci dni. Wpisz poprawna date."<<endl;
                            return false;
                        }
                    }

                else
                {
                    cout<<"Nie istnieje taki miesiac lub dzien. Wprowadz poprawna wartosc miesiaca lub dnia."<<endl;
                    return false;
                }
            }
            else
            {
                cout<<"Nieprawidlowy format. Wprowadz date w formacie YYYY-MM-DD."<<endl;
                return false;
            }
        }
        else {
            cout<<"Niepoprawny przedzial czasowy. Wprowadz poprawna date ( od 2000-01-01 do dzisiejszej daty ). "<<endl;
            return false;
        }
    }
    else
    {
        cout<<"Niepoprawna dlugosc daty. Wprowadz poprawna date."<<endl;
        return false;
    }

}

double SupportMethod::changeComaToDot( string number )
{
    string newNumber;
    double numberAsDouble;

    for( auto i : number)
    {
        if( i ==',')
            newNumber +=".";
        else
            newNumber += i;
    }
    numberAsDouble = atof( newNumber.c_str() );
    return numberAsDouble;
}

 string SupportMethod::changeMonth (string date, char sign)
 {
    string year, error= "Blad!";
    int yearAsInt;
    char ten,unit;

    ten = date[5];
    unit = date[6];

    if ( ten == '0' && unit == '1' && sign == '-' )
    {
       for (int i = 0; i <= 3; i++)
       {
           year += date[i];
       }

       yearAsInt = convertStringToInt( year );
       year = convertIntToString( --yearAsInt );
       ten = '1';
       unit = '2';
       if( yearAsInt < 2000 )
       return error;
        else
       {
          for (int i = 0; i<=3; i++)
        {
            date[i] = year[i];
        }
       }
    }
    else if ( ten == '1' && unit == '2' && sign == '+' )
    {
       for (int i = 0; i <= 3; i++)
       {
           year += date[i];
       }

       yearAsInt = convertStringToInt( year );
       year = convertIntToString( ++yearAsInt );
       ten = '0';
       unit = '1';

          for (int i = 0; i<=3; i++)
        {
            date[i] = year[i];
        }
    }
    else
    {
        if ( sign = '+')
            unit++;
        else if (sign = '-')
            unit--;
        else
           return error;
    }

    date[5] = ten;
    date[6] = unit;

    if ( isProperDate(date, convertDateWithDashToInt(date) ) )
        return date;
    else
       return error;

    return 0;
 }
