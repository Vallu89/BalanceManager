#include <iostream>
#include "BalanceManager.h"
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "SupportMethod.h"

using namespace std;

int main(){


    BalanceManager balanceManager("users.xml" );

        while (true)
    {
        if (balanceManager.getIdOfLoggedUser() == 0)
        {

            switch ( balanceManager.chooseOptionFromMainMenu() )
            {
            case '1':
                balanceManager.registrationUser();
                break;

            case '2':
                balanceManager.logonUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

            balanceManager.isIncomesAndExpensesExist();

            switch (balanceManager.chooseOptionFromUserMenu())
            {
            case '1':
                balanceManager.addIncome();
                break;
            case '2':
                balanceManager.addExpense();
                break;
            case '3':
                balanceManager.showThisMonthBalance();
                break;
            case '4':
                balanceManager.showPreviousMonthBalance();
                break;
            case '5':
                balanceManager.showBalanceFromPeriod();
                break;
            case '6':
                balanceManager.changePasswordOfLoggedUser();
                break;
            case '7':
                balanceManager.logoutUser();
                break;
            }
        }
    }
    return 0;
}

int _main()
{


    IncomeManager *incomeManager = new IncomeManager("incomes.xml",1);

    if (incomeManager->getIncomes().empty() == true  )
            incomeManager->setLastIncomeId(incomeManager->loadIncomesOfLoggedUserFromFile());
    incomeManager->addIncome();

    return 0;
}

int __main()
{


    cout <<SupportMethod::convertActualDateToString()<<endl;

    return 0;
}
