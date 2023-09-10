#include "OperationXML.h"

bool OperationXML::addOperationToXMLFile(Operation &operation) {
    CMarkup xml;

    xml.Load(getXMLFileName());
    if (!XMLFileExists(getXMLFileName())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
        xml.Save(getXMLFileName());
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("Operation");
    xml.IntoElem();

    xml.AddElem("OperationID", AuxiliaryMethods::convertIntToString(getLastOperationID(operation.getUserID()) + 1));
    xml.AddElem("UserID", AuxiliaryMethods::convertIntToString(operation.getUserID()));
    xml.AddElem("Date", DateMethods::convertIntDateToStringWithDashes(operation.getDate()));
    xml.AddElem("Item", operation.getItem());

    double amount = operation.getAmount();
    string amountString = to_string(amount);
    string delimiter = ".";
    string truncatedAmount = amountString.substr(0, amountString.find(delimiter) + 3);
    xml.AddElem("Amount", truncatedAmount);

    xml.Save(getXMLFileName());
    return true;
}

int OperationXML::getLastOperationID(const int loggedInUserId) {

    Operation operation;
    CMarkup xml;
    int temp = 0;

    xml.Load(getXMLFileName());

    if (!XMLFileExists(getXMLFileName())) {
        lastOperationID = 0;
        return lastOperationID;
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Operation")) {
        xml.FindChildElem("OperationID");
        operation.setOperationID(atoi(xml.GetChildData().c_str()));
        xml.ResetChildPos();

        xml.FindChildElem("UserID");
        operation.setUserID(atoi(xml.GetChildData().c_str()));

        if (operation.getUserID() != loggedInUserId) {
            continue;
        }

        temp = max(temp,  operation.getOperationID());
        xml.ResetChildPos();
    }

    lastOperationID = temp;
    xml.Save(getXMLFileName());

    return lastOperationID;
}

vector<Operation> OperationXML::loadOperationsFromXMLFile(const int loggedInUserId) {

    vector<Operation> operations;
    Operation operation;
    CMarkup xml;

    xml.Load(getXMLFileName());

    if (!xml.Load(getXMLFileName())) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Operation")) {

        xml.FindChildElem("OperationID");
        operation.setOperationID(atoi(xml.GetChildData().c_str()));
        xml.ResetChildPos();

        xml.FindChildElem("UserID");
        string userStr = xml.GetChildData();
        int convertedUser = AuxiliaryMethods::convertStringToInt(userStr);
        operation.setUserID(convertedUser);
        if (operation.getUserID() != loggedInUserId) {
            continue;
        }
        xml.ResetChildPos();

        xml.FindChildElem("Date");
        string dateStr = xml.GetChildData();
        int convertedDate = DateMethods::convertStringDateToInt(dateStr);
        operation.setDate(convertedDate);
        xml.ResetChildPos();

        xml.FindChildElem("Item");
        string itemFromXML = xml.GetChildData();
        operation.setItem(itemFromXML);
        xml.ResetChildPos();

        xml.FindChildElem("Amount");
        operation.setAmount(stod(xml.GetChildData()));
        xml.ResetChildPos();

        operations.push_back(operation);
    }

    xml.Save(getXMLFileName());

    return operations;
}

