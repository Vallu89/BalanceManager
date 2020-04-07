#include "ExpenseManager.h"

int ExpenseManager::loadExpensesOfLoggedUserFromFile()
{
    Expense expense;
    xml.Load(fileWithExpense.getFILE_NAME());
    xml.FindElem("Expenses");
    xml.IntoElem();
    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if ( LOGGED_USER_ID == atoi( MCD_2PCSZ(xml.GetData()) ) )
        {
            expense.setUserId( atoi( MCD_2PCSZ(xml.GetData()) ) );
            xml.FindElem("ExpenseId");
            expense.setExpenseId( atoi( MCD_2PCSZ(xml.GetData()) ) );
            xml.FindElem("Date");
            expense.setDate(xml.GetData());
            xml.FindElem("DateAsInt");
            expense.setDateAsInt( atoi( MCD_2PCSZ(xml.GetData()) ) );
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(atof( MCD_2PCSZ(xml.GetData()) ));

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    sort(expenses.begin(), expenses.end(), [](  Expense& l, Expense& r )
         {return l.getDateAsInt() < r.getDateAsInt(); });

    return expense.getExpenseId();
}

int ExpenseManager::addExpense()
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    getNewExpenseData();

    expenses.push_back(expense);
    fileWithExpense.writeExpensesIntoFile(expense);

    return lastExpenseId;
}

Expense ExpenseManager::getNewExpenseData()
{
string AmountAsString;

    expense.setExpenseId(++lastExpenseId);
    expense.setUserId(LOGGED_USER_ID);

    while(1)
    {
        cout << "Podaj date( format YYYY-MM-DD ): ";
        expense.setDate(SupportMethod::loadLine());
        expense.setDateAsInt( SupportMethod::convertDateWithDashToInt( expense.getDate() ) );
        if(SupportMethod::isProperDate( expense.getDate(),expense.getDateAsInt() ))
            break;
    }
    cout << "Podaj opis: ";
    expense.setItem(SupportMethod::loadLine());

    cout << "Podaj kwote: ";
    cin>>AmountAsString;

    expense.setAmount( SupportMethod::changeComaToDot( AmountAsString ) );

    return expense;
}

//

double ExpenseManager::ExpensesFromPeriod(string fromDate, string toDate, bool wholeMonth)
{
    double sum = 0;
    int fromDateAsIntWithoutDays, toDateAsIntWithoutDays;

    if (!expenses.empty())
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

        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); itr++)
        {
            if ( itr -> getDateAsInt() > fromDateAsIntWithoutDays && itr -> getDateAsInt() <= toDateAsIntWithoutDays )
            {
                showExpense(*itr);
                sum += itr -> getAmount();
            }
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Brak wydatków w obecnym czasie." << endl << endl;
    }
    return sum;
}

double ExpenseManager::showAllExpensesInThisMonth()
{
    cout<<"         WYDATKI         "<<endl;
    string actualDate = SupportMethod::convertActualDateToString();
    return ExpensesFromPeriod(actualDate , actualDate, true );

}

void ExpenseManager::showExpense( Expense expense )
{
    cout << endl << "ID:           " << expense.getExpenseId() << endl;
            cout << "Data:         " << expense.getDate() << endl;
            cout << "Opis:         " << expense.getItem() << endl;
            cout << "Kwota:        -" << expense.getAmount() << endl;
            cout << "---"<< endl;
}
