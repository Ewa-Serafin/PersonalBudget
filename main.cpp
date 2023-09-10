#include <iostream>

#include "MainSettings.h"
#include "Menus.h"

using namespace std;

int main() {

    MainSettings MainSettings("Users.xml", "Incomes.xml", "Expenses.xml");
    char choice;

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
                MainSettings.addIncome();
                break;
            case '2':
                MainSettings.addExpense();
                break;
            case '3':
                MainSettings.currentMonthBalance();
                break;
            case '4':
                MainSettings.displayLastMonthBalance();
                break;
            case '5':
                MainSettings.displayBalanceFromSelectedDates();
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
