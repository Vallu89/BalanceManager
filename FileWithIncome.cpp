#include "FileWithIncome.h"

void FileWithIncome::writeIncomesIntoFile( Income income )
{
    bool isFileExist = true;

    xml.Load(FILE_NAME);
    if (!xml.FindElem("Incomes"))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
        isFileExist = false;
    }
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId",income.getUserId());
    xml.AddElem("IncomeId",income.getIncomeId());
    xml.AddElem("Date",income.getDate());
    xml.AddElem("DateAsInt",income.getDateAsInt());
    xml.AddElem("Item",income.getItem());
    xml.AddElem("Amount", to_string(income.getAmount()));

    xml.Save(FILE_NAME);
}
