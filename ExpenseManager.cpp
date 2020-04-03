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
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(atoi( MCD_2PCSZ(xml.GetData()) ));

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }

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

double ExpenseManager::showAllExpenseInThisMonth()
{

}
