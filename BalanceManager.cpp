#include "BalanceManager.h"

char BalanceManager::chooseOptionFromMainMenu()
{
    SupportMethod supportMethod;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = supportMethod.loadChar();

    return choice;
}

char BalanceManager::chooseOptionFromUserMenu()
{
    SupportMethod supportMethod;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = supportMethod.loadChar();

    return choice;
}

void BalanceManager::addIncome()
{
    incomeManager->addIncome();
}

void BalanceManager::addExpense()
{
    expenseManager->addExpense();
}

void BalanceManager::showThisMonthBalance()
{
    float totalBalance = incomeManager->showAllIncomesInThisMonth()
                        - expenseManager->showAllExpenseInThisMonth();

    cout << totalBalance <<endl;
}

void BalanceManager::showPreviousMonthBalance()
{

}

void BalanceManager::showBalanceFromPeriod()
{

}

void BalanceManager::registrationUser()
{
    userManager.registrationUser();
}

void BalanceManager::logonUser()
{
    userManager.logonUser();
    if( userManager.isUserLogged() )
    {
        incomeManager = new IncomeManager("incomes.xml",userManager.getIdOfLoggedUser());
        expenseManager = new ExpenseManager ("expenses.xml",userManager.getIdOfLoggedUser());
    }
}

void BalanceManager::isIncomesAndExpensesExist()
{
    if (incomeManager->getIncomes().empty() == true && expenseManager->getExpenses().empty() == true )
    {
                incomeManager->setLastIncomeId(incomeManager->loadIncomesOfLoggedUserFromFile());
                expenseManager->setlastExpenseId(expenseManager->loadExpensesOfLoggedUserFromFile());
    }
}

void BalanceManager::logoutUser()
{
    userManager.logoutUser();
    incomeManager->getIncomes().clear();
    expenseManager->getExpenses().clear();
}

int BalanceManager::getIdOfLoggedUser()
{
    return userManager.getIdOfLoggedUser();
}

void BalanceManager::changePasswordOfLoggedUser()
{
    userManager.changePasswordOfLoggedUser();
}
