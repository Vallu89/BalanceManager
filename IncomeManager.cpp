#include "IncomeManager.h"

int IncomeManager::loadIncomesOfLoggedUserFromFile()
{
    Income income;
    xml.Load(fileWithIncome.getFILE_NAME());
    xml.FindElem("Incomes");
    xml.IntoElem();
    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if ( LOGGED_USER_ID == atoi( MCD_2PCSZ(xml.GetData()) ) )
        {
            income.setUserId( atoi( MCD_2PCSZ(xml.GetData()) ) );
            xml.FindElem("IncomeId");
            income.setIncomeId( atoi( MCD_2PCSZ(xml.GetData()) ) );
            xml.FindElem("Date");
            income.setDate(xml.GetData());
            xml.FindElem("DateAsInt");
            income.setDateAsInt( atoi( MCD_2PCSZ(xml.GetData()) ) );
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(atof( MCD_2PCSZ(xml.GetData()) ));

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    sort(incomes.begin(), incomes.end(), [](  Income& l, Income& r )
         {return l.getDateAsInt() < r.getDateAsInt(); });

    return income.getIncomeId();
}

int IncomeManager::addIncome()
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    getNewIncomeData();

    incomes.push_back(income);
    fileWithIncome.writeIncomesIntoFile(income);

    return lastIncomeId;
}

Income IncomeManager::getNewIncomeData()
{
    string AmountAsString;

    income.setIncomeId(++lastIncomeId);
    income.setUserId(LOGGED_USER_ID);

    while(1)
    {
        cout << "Podaj date( format YYYY-MM-DD ): ";
        income.setDate(SupportMethod::loadLine());
        income.setDateAsInt( SupportMethod::convertDateWithDashToInt( income.getDate() ) );
        if(SupportMethod::isProperDate( income.getDate(),income.getDateAsInt() ))
            break;
    }
    cout << "Podaj opis: ";
    income.setItem(SupportMethod::loadLine());

    cout << "Podaj kwote: ";
    cin>>AmountAsString;

    income.setAmount( SupportMethod::changeComaToDot( AmountAsString ) );

    return income;
}
//
double IncomeManager::IncomesFromPeriod(string fromDate, string toDate, bool wholeMonth)
{
    double sum = 0;
    int fromDateAsIntWithoutDays, toDateAsIntWithoutDays;

    if (!incomes.empty())
    {
        if (wholeMonth)
        {
            fromDateAsIntWithoutDays = (SupportMethod::convertDateWithDashToInt( fromDate )/100)*100;
            toDateAsIntWithoutDays = (SupportMethod::convertDateWithDashToInt( toDate )/100)*100
                                                    + SupportMethod::howManyDaysHaveMonth(toDate);
        }
        else
        {
            fromDateAsIntWithoutDays = SupportMethod::convertDateWithDashToInt( fromDate );
            toDateAsIntWithoutDays = SupportMethod::convertDateWithDashToInt( toDate );
        }


        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            if ( itr -> getDateAsInt() > fromDateAsIntWithoutDays && itr -> getDateAsInt() <= toDateAsIntWithoutDays )
            {
                showIncome(*itr);
                sum += itr -> getAmount();
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak Przychodów w obecnym czasie." << endl << endl;
    }
    return sum;
}

double IncomeManager::showAllIncomesInThisMonth()
{
    cout<<"         PRZYCHODY         "<<endl;
    string actualDate = SupportMethod::convertActualDateToString();
    return IncomesFromPeriod( actualDate , actualDate, true );

}

void IncomeManager::showIncome( Income income )
{
    cout << endl << "ID:           " << income.getIncomeId() << endl;
            cout << "Data:         " << income.getDate() << endl;
            cout << "Opis:         " << income.getItem() << endl;
            cout << "Kwota:        " << income.getAmount() << endl;
            cout << "---" << endl;
}
