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
            if (adresatMenadzer.pobierzAdresaci().empty() == true)
                idOstatniegoAdresata = adresatMenadzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();

            switch (ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika())
            {
            case '1':
                idOstatniegoAdresata = adresatMenadzer.dodajAdresata();
                break;
            case '2':
                adresatMenadzer.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                adresatMenadzer.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                adresatMenadzer.wyswietlWszystkichAdresatow();
                break;
            case '5':
                adresatMenadzer.usunAdresata();
                break;
            case '6':
                adresatMenadzer.edytujAdresata();
                break;
            case '7':
                uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '9':
                uzytkownikMenadzer.ustawIdZalogowanegoUzytkownika(0);
                adresatMenadzer.pobierzAdresaci().clear();
                break;
            }
        }
    }
    return 0;
}
