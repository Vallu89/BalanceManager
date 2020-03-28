#include "FileWithIncome.h"

void FileWithIncome::writeIncomesIntoFile( Income income )
{
    xml.Load(FILE_NAME);
    if (!xml.FindElem("Incomes"))
        xml.AddElem("Incomes");
    xml.IntoElem();

    xml.AddElem("Income");
    xml.IntoElem();

    xml.AddElem("UserId",income.getUserId());
    xml.AddElem("IncomeId",income.getIncomeId());
    xml.AddElem("Date",income.getDate());
    xml.AddElem("Item",income.getItem());
    xml.AddElem("Amount",income.getAmount());

    xml.Save(FILE_NAME);
}
