#include "MainSettings.h"

bool MainSettings::isUserLoggedIn() {

    return userManager.isUserLoggedIn();
}

void MainSettings::registerUser() {
    userManager.registerUser();
}

void MainSettings::logIn() {
    userManager.logIn();
    if (userManager.isUserLoggedIn()) {

        financialManager = new FinancialManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedInUserId());
    }
}

void MainSettings::changePassword() {
    userManager.changePassword();
}

void MainSettings::logOut() {
    userManager.logOut();
    delete financialManager;
    financialManager = NULL;
}

void MainSettings::addIncome() {
    if (userManager.isUserLoggedIn()) {
        financialManager->addIncome();
    } else {
        cout << "You need to log in first." << endl;
    }
}

void MainSettings::addExpense() {
    if (userManager.isUserLoggedIn()) {
        financialManager->addExpense();
    } else {
        cout << "You need to log in first." << endl;
    }
}

void MainSettings::currentMonthBalance() {
    if (userManager.isUserLoggedIn()) {
        financialManager->currentMonthBalance();
    } else {
        cout << "You need to log in first." << endl;
    }
}

void MainSettings::displayLastMonthBalance() {
    if (userManager.isUserLoggedIn()) {
        financialManager->displayLastMonthBalance();
    } else {
        cout << "You need to log in first." << endl;
    }
}

void MainSettings::displayBalanceFromSelectedDates() {
    if (userManager.isUserLoggedIn()) {
        financialManager->displayBalanceFromSelectedDates();
    } else {
        cout << "You need to log in first." << endl;
    }
}
