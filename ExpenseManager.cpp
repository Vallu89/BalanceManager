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

    return ++lastExpenseId;
}

Expense ExpenseManager::getNewExpenseData()
{
    double newAmount;

    expense.setExpenseId(++lastExpenseId);
    expense.setUserId(LOGGED_USER_ID);

    cout << "Podaj date: ";
    expense.setDate(SupportMethod::loadLine());

    cout << "Podaj opis: ";
    expense.setItem(SupportMethod::loadLine());

    cout << "Podaj kwote: ";
    cin >> newAmount;
    expense.setAmount(newAmount);


    return expense;
}

double ExpenseManager::showAllExpenseInThisMonth()
{

}
