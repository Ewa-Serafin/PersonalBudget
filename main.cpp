#include <iostream>

using namespace std;

#include "MainSettings.h"
#include "Menus.h"

int main() {

    char choice;

    MainSettings MainSettings("Users");

    while (true) {
        if (!MainSettings.isUserLoggedIn()) {

            choice = Menus::chooseOptionFromMainMenu();

            switch (choice) {
            case '1':
                MainSettings.registerUser();
                break;
            case '2':
                MainSettings.logIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;

            }

        } else {

            choice = Menus::chooseOptionFromUserMenu();

            switch (choice) {
            case '1':
              //  MainSettings.addIncome();
                break;
            case '2':
               // MainSettings.addExpese();
                break;
            case '3':
              //  MainSettings.currentMonthBalance();
                break;
            case '4':
              //  MainSettings.displayLastMonthIncomeBalance();
                break;
            case '5':
               // MainSettings.displayIncomeBalanceFromSelectedDates();
                break;
            case '6':
                MainSettings.changePassword();
                break;
            case '7':
                MainSettings.logOut();
                break;
            }
        }
    }
    return 0;
}



/* Funkcja do porównywania dat (od-do)
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

}
    return 0;
}
*/
