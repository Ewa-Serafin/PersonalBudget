#include "MainSettings.h"

bool MainSettings::isUserLoggedIn() {

    return userManager.isUserLoggedIn();
}

void MainSettings::registerUser() {
    userManager.registerUser();
}

void MainSettings::logIn() {
    userManager.logIn();

}

void MainSettings::changePassword() {
    userManager.changePassword();
}

void MainSettings::logOut() {
    userManager.logOut();

}



