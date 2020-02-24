#include "FileWithExpense.h"

void FileWithExpense::writeExpensesIntoFile( Expense expense )
{
    xml.Load(FILE_NAME);
    xml.FindElem("Expenses");
    xml.IntoElem();

    xml.AddElem("Expense");
    xml.IntoElem();

    xml.AddElem("UserId",expense.getUserId());
    xml.AddElem("ExpenseId",expense.getExpenseId());
    xml.AddElem("Date",expense.getDate());
    xml.AddElem("Item",expense.getItem());
    xml.AddElem("Amount",expense.getAmount());

    xml.Save(FILE_NAME);
}
