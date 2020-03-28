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
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(atoi( MCD_2PCSZ(xml.GetData()) ));

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }

    return income.getIncomeId();
}

int IncomeManager::addIncome()
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    getNewIncomeData();

    incomes.push_back(income);
    fileWithIncome.writeIncomesIntoFile(income);

    return ++lastIncomeId;
}

Income IncomeManager::getNewIncomeData()
{
    double newAmount;

    income.setIncomeId(++lastIncomeId);
    income.setUserId(LOGGED_USER_ID);

    cout << "Podaj date: ";
    income.setDate(SupportMethod::loadLine());

    cout << "Podaj opis: ";
    income.setItem(SupportMethod::loadLine());

    cout << "Podaj kwote: ";
    cin >> newAmount;
    income.setAmount(newAmount);


    return income;
}

double IncomeManager::showAllIncomesInThisMonth()
{

}

