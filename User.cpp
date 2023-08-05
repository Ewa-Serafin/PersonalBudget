#include "User.h"

void User::setName(string newName)
{
    name = newName;
}

void User::setLastname (string newLastname)
{
    lastname = newLastname;
}

void User::setId (int newId)
{
    if (newId >=0)
        Id = newId;
}

void User::setLogin (string newLogin)
{
    login = newLogin;
}

void User::setPassword (string newPassword)
{
    password = newPassword;
}


string User::getName()
{
    return name;
}

string User::getLastname()
{
    return lastname;
}

int User::getId()
{
    return Id;
}

string User::getLogin()
{
    return login;
}

string User::getPassword()
{
    return password;
}

