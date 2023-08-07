#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User
{
    string name;
    string lastname;
    int Id;
    string login;
    string password;

public:

    void setName (string newName);
    void setLastname (string newLastname);
    void setId (int newId);
    void setLogin (string newLogin);
    void setPassword (string newPassword);

    string getName();
    string getLastname();
    int getId();
    string getLogin();
    string getPassword();


};

#endif
