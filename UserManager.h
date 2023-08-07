
#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include"User.h"
#include "AuxiliaryMethods.h"
#include"UsersXMLFile.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector <User> users;
    UsersXMLFile usersXMLFile;

    User insertNewUserData();
    int getNewUserId();
    bool isLoginExsist(string login);
    void clearUsers();

public:
    UserManager(string usersXMLNameFile);

    void registerUser();
    void logIn();
    int getLoggedInUserId();
    bool isUserLoggedIn();
    void changePassword();
    void logOut();
};
#endif
