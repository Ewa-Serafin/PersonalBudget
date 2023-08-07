#include "UserManager.h"

UserManager::UserManager(string usersXMLNameFile) : usersXMLFile(usersXMLNameFile){
    loggedInUserId = 0;
    users = usersXMLFile.loadUsersFromXMLFile();
}

void UserManager::registerUser() {
    User user = insertNewUserData();

    users.push_back(user);

    usersXMLFile.addUserToXMLFile(user);
    cout << endl << "Account created successfully." << endl << endl;
    system("pause");
}


void UserManager::logIn() {
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin()  == login) {
            for (int attemptsLeft  = 3; attemptsLeft  > 0; attemptsLeft --) {
                cout << "Enter password. Attempts left: " << attemptsLeft << ": ";
                password = AuxiliaryMethods::readLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "Logged in." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getId();
                    return;
                }
            }
            cout << "Incorrect password entered 3 times." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "No user with such login exists" << endl << endl;
    system("pause");
    return;
}

int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}

bool UserManager::isUserLoggedIn() {
    return loggedInUserId > 0;
}

void UserManager::changePassword() {
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::readLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getId() == loggedInUserId) {
            itr -> setPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
   usersXMLFile.changeLoggedUserPasswordInXMLFile(newPassword,loggedInUserId);
}

void UserManager::logOut() {
    loggedInUserId = 0;
    cout << "Successfully logged out." << endl;
    Sleep(1000);
}

User UserManager::insertNewUserData() {
    User user;

    user.setId(getNewUserId());

    string login;
    do {
        cout << "Enter login: ";
        cin >> login;
        user.setLogin(login);
    } while (isLoginExsist(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    cin >> password;
    user.setPassword(password);

     string name;
    cout << "Enter name: ";
    cin >> name;
    user.setName(name);

     string lastname;
    cout << "Enter lastname: ";
    cin >> lastname;
    user.setLastname(lastname);

    return user;
}


int  UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExsist(string login) {
    for (size_t i =0; i< users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "A user with this login already exists." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::clearUsers() {

    users.clear();
}
