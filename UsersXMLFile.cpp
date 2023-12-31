#include"UsersXMLFile.h"

bool UsersXMLFile::addUserToXMLFile(User user) {
    string ID = AuxiliaryMethods::convertIntToString(user.getUserID());
    string login = user.getLogin();
    string password = user.getPassword();
    string name = user.getName();
    string lastname = user.getLastname();
    CMarkup xml;

    xml.Load(getXMLFileName());
    if (!XMLFileExists(getXMLFileName())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.Save(getXMLFileName());
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserID", ID);
    xml.AddElem("Login", login);
    xml.AddElem("Password", password);
    xml.AddElem("Name", name);
    xml.AddElem("Lastname", lastname);

    xml.Save(getXMLFileName());
    return true;
}

vector <User> UsersXMLFile::loadUsersFromXMLFile() {
    int id=0;
    string login="", password="";
    vector <User> users;
    User user;
    CMarkup xml;

    if (!XMLFileExists(getXMLFileName())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.Save(getXMLFileName());
    }

    xml.Load(getXMLFileName());

    if (!xml.Load(getXMLFileName())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") ) {
        xml.FindChildElem( "UserID" );
        id = stoi(xml.GetChildData());
        xml.ResetChildPos();
        xml.FindChildElem( "Login" );
        login = xml.GetChildData();
        xml.ResetChildPos();
        xml.FindChildElem( "Password" );
        password = xml.GetChildData();

        user.setUserID(id);
        user.setLogin(login);
        user.setPassword(password);
        users.push_back(user);
    }
    xml.Save(getXMLFileName());

    cout << "Users loaded successfully." << endl;
    return users;
}

void UsersXMLFile::changeLoggedUserPasswordInXMLFile(string newPassword,int loggedUserID) {
    CMarkup xml;

    xml.Load(getXMLFileName());
    if (!XMLFileExists(getXMLFileName())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        xml.Save(getXMLFileName());
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") ) {
        xml.FindChildElem( "UserID" );
        if(stoi(xml.GetChildData()) == loggedUserID) {
            xml.ResetChildPos();
            xml.FindChildElem( "Password" );
            xml.RemoveChildElem();
            xml.AddChildElem("Password", newPassword);
        }
    }
    xml.Save(getXMLFileName());
}
