#include <iostream>

using namespace std;

#include "PersonalBudget.h"
#include "Menus.h"

int main() {

    char choice;

    PersonalBudget personalBudget("Users");

    while (true) {
        if (!personalBudget.isUserLoggedIn()) {

            choice = Menus::chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.logIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;

            }

        } /*else {

            wybor = WyswietlMenu::wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogujUzytkownika();
                break;
            }
        }
    }
    return 0;
}



 Funkcja do porównywania dat (od-do)
bool isDateInRange(const tm& dateToCheck, const tm& startDate, const tm& endDate) {
    tm dateCheck = dateToCheck;
    dateCheck.tm_hour = dateCheck.tm_min = dateCheck.tm_sec = 0;

    time_t tDateToCheck = mktime(const_cast<tm*>(&dateCheck));

    tm start = startDate;
    start.tm_hour = start.tm_min = start.tm_sec = 0;
    time_t tStartDate = mktime(const_cast<tm*>(&start));

    tm end = endDate;
    end.tm_hour = end.tm_min = end.tm_sec = 0;
    time_t tEndDate = mktime(const_cast<tm*>(&end));

    return (tDateToCheck >= tStartDate && tDateToCheck <= tEndDate);
}

int main() {
    // Zak³adamy, ¿e u¿ytkownik poda zakres dat
    tm startDate = {};
    tm endDate = {};
    int startYear, startMonth, startDay;
    int endYear, endMonth, endDay;

    cout << "Podaj datê pocz¹tkow¹ (RRRR MM DD): ";
    cin >> startYear >> startMonth >> startDay;

    cout << "Podaj datê koñcow¹ (RRRR MM DD): ";
    cin >> endYear >> endMonth >> endDay;

    startDate.tm_year = startYear - 1900;
    startDate.tm_mon = startMonth - 1;
    startDate.tm_mday = startDay;

    endDate.tm_year = endYear - 1900;
    endDate.tm_mon = endMonth - 1;
    endDate.tm_mday = endDay;

    if (isDateInRange(startDate, startDate, endDate)) {
        cout << "Data jest w zakresie od-do." << endl;
    } else {
        cout << "Data nie jest w zakresie od-do." << endl;
    }

    return 0;
}






   CMarkup xml;

   bool fileExists = xml.Load( "users.xml" );

   if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem( "Users" );
   }


xml.FindElem();
xml.IntoElem();
xml.AddElem( "User" );
xml.IntoElem();
xml.AddElem( "UserId", "2" );
xml.AddElem( "Login", "mat" );
xml.AddElem( "Password", "456" );

xml.Save("users.xml");
*/
}
    return 0;
}

