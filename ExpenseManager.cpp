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
