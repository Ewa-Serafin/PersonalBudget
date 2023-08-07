#include "PersonalBudget.h"

bool PersonalBudget::isUserLoggedIn() {

    return userManager.isUserLoggedIn();
}

void PersonalBudget::registerUser() {
    userManager.registerUser();
}

void PersonalBudget::logIn() {
    userManager.logIn();

}

void PersonalBudget::changePassword() {
    userManager.changePassword();
}

void PersonalBudget::logOut() {
    userManager.logOut();

}



