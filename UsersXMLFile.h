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

public:
    UsersXMLFile(string XMLFileName): XMLFile (XMLFileName) {};

    vector <User> loadUsersFromXMLFile();
    bool addUserToXMLFile(User user);
    void changeLoggedUserPasswordInXMLFile(string newPassword, int loggedInUserID);
};

#endif
