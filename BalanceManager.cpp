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
    system("cls");
    double incomes = incomeManager->showAllIncomesInThisMonth();
    double expenses = expenseManager->showAllExpensesInThisMonth();
    cout <<"Przychod calkowity: "<<incomes<<endl;
    cout <<"Rozchod calkowity: "<<expenses<<endl;
    double totalBalance = incomes - expenses;
    cout <<"Bilans: "<< totalBalance <<endl;

    system("pause");
}

void BalanceManager::showPreviousMonthBalance()
{
    system("cls");
    double incomes = incomeManager->showAllIncmoesFromPreviousMonth();
    double expenses = expenseManager->showAllExpensesFromPreviousMonth();
    cout <<"Przychod calkowity: "<<incomes<<endl;
    cout <<"Rozchod calkowity: "<<expenses<<endl;
    double totalBalance = incomes - expenses;
    cout <<"Bilans: "<< totalBalance <<endl;

    system("pause");
}

void BalanceManager::showBalanceFromPeriod()
{
    string fromDate, toDate;
    system("cls");
    while(1)
    {
        cout<<"Podaj poczatek wybranego okresu: "<<endl;
        fromDate = SupportMethod::loadLine();
        if(SupportMethod::isProperDate(fromDate,SupportMethod::convertDateWithDashToInt(fromDate)))
            break;
    }
    while(1)
    {
        cout<<"Podaj koniec wybranego okresu: "<<endl;
        toDate = SupportMethod::loadLine();
        if(SupportMethod::isProperDate(toDate,SupportMethod::convertDateWithDashToInt(toDate)))
            break;
    }
    double incomes = incomeManager->showAllIncomesFromPeriod( fromDate, toDate);
    double expenses = expenseManager->showAllExpensesFromPeriod( fromDate, toDate);
    cout <<"Przychod calkowity: "<<incomes<<endl;
    cout <<"Rozchod calkowity: "<<expenses<<endl;
    double totalBalance = incomes - expenses;
    cout <<"Bilans: "<< totalBalance <<endl;

    system("pause");
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
