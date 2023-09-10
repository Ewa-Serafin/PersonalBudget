#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    string name;
    string lastname;
    int UserID;
    string login;
    string password;

public:

    void setName (string newName);
    void setLastname (string newLastname);
    void setUserID (int newUserID);
    void setLogin (string newLogin);
    void setPassword (string newPassword);

    string getName();
    string getLastname();
    int getUserID();
    string getLogin();
    string getPassword();
};
#endif
