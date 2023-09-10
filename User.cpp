#include "User.h"

void User::setName(string newName) {
    name = newName;
}

void User::setLastname (string newLastname) {
    lastname = newLastname;
}

void User::setUserID (int newUserID) {
    if (newUserID >=0)
        UserID = newUserID;
}

void User::setLogin (string newLogin) {
    login = newLogin;
}

void User::setPassword (string newPassword) {
    password = newPassword;
}

string User::getName() {
    return name;
}

string User::getLastname() {
    return lastname;
}

int User::getUserID() {
    return UserID;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}
