#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "AuxiliaryMethods.h"


using namespace std;

class PersonalBudget {

    UserManager userManager;


public:
    PersonalBudget(string usersXMLFileName)
        : userManager(usersXMLFileName){};

    bool isUserLoggedIn();
    void registerUser();
    void logIn();
    void changePassword();
    void logOut();
};

#endif
