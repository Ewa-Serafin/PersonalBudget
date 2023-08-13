#ifndef MAINSETTINGS_H
#define MAINSETTINGS_H

#include <iostream>

#include "UserManager.h"
#include "AuxiliaryMethods.h"


using namespace std;

class MainSettings {

    UserManager userManager;


public:
    MainSettings(string usersXMLFileName)
        : userManager(usersXMLFileName){};

    bool isUserLoggedIn();
    void registerUser();
    void logIn();
    void changePassword();
    void logOut();
};

#endif
