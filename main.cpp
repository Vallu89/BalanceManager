#include <iostream>
#include "BalanceManager.h"
#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "SupportMethod.h"

using namespace std;

int main(){


    int idOstatniegoAdresata = 0;
    int idUsunietegoAdresata = 0;

    BalanceManager balanceManager("users.xml" );
    UserManager userManager("users.xml");

        while (true)
    {
        if (userManager.getIdOfLoggedUser() == 0)
        {

            switch (balanceManager.chooseOptionFromMainMenu())
            {
            case '1':
                userManager.registrationUser();
                break;

            case '2':
                userManager.logonUser();
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
        IncomeManager incomeManager ("incomes.xml",userManager.getIdOfLoggedUser());
        ExpenseManager expenseManager ("expenses.xml",userManager.getIdOfLoggedUser());
            if (incomeManager.getIncomes().empty() == true && expenseManager.getExpenses().empty() == true )
                idOstatniegoAdresata = adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();

            switch (balanceManager.chooseOptionFromUserMenu())
            {
            case '1':
                balanceManager.addIncome();
                break;
            case '2':
                balanceManager.addExpense()
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
                userManager.changePasswordOfLoggedUser();
                break;
            case '7':
                userManager.logoutUser();
                incomeManager.getIncomes().clear();
                expenseManager.getExpenses().clear();
                break;
            }
        }
    }
    return 0;
}
