#ifndef MAINSETTINGS_H
#define MAINSETTINGS_H

#include <iostream>

#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "FinancialManager.h"

using namespace std;

class MainSettings {

    UserManager userManager;
    FinancialManager* financialManager;
    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;

public:
    MainSettings(const string& usersXMLFileName, const string& incomesXMLFileName, const string& expensesXMLFileName)
        : userManager(usersXMLFileName), INCOME_FILE_NAME(incomesXMLFileName), EXPENSE_FILE_NAME(expensesXMLFileName) {
        financialManager = NULL;
    }
    bool isUserLoggedIn();
    void registerUser();
    void logIn();
    void changePassword();
    void logOut();

    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void displayLastMonthBalance();
    void displayBalanceFromSelectedDates();
};

#endif

