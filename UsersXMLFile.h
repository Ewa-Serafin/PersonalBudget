#ifndef USERSXMLFILE_H
#define USERSXMLFILE_H

#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "Markup.h"
#include "User.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"

using namespace std;

class UsersXMLFile : public XMLFile {

    string usersXMLFileName;

public:
    UsersXMLFile(string usersXMLFileName)
        : XMLFile (usersXMLFileName) {}; //, usersXMLFileName(usersXMLFileName){};

    vector <User> loadUsersFromXMLFile();
    void addUserToXMLFile(User user);
    void changeLoggedUserPasswordInXMLFile(string newPassword, int loggedUserID);
};

#endif
