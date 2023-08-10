#include "OperationXML.h"

void OperationXML::addOperationToXMLFile(Operation operation)
{
    CMarkup xml;

    xml.Load(operationsXMLFileName + ".xml");
    if (!XMLFileExists(operationsXMLFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("Operation");
    xml.IntoElem();
    xml.AddElem("OperationID", AuxiliaryMethods::convertIntToString(operation.getOperationID()));
    xml.AddElem("UserID", AuxiliaryMethods::convertIntToString(operation.getUserID()));
    xml.AddElem("Date", AuxiliaryMethods::dateToDispalyFormat(to_string(operation.getDate())));
    xml.AddElem("Item", operation.getItem());

    double amount = operation.getAmount();
    string amountString = to_string(amount);
    string delimiter = ".";
    string truncatedAmount = amountString.substr(0, amountString.find(delimiter) + 3);
    xml.AddElem("Amount", truncatedAmount);

    xml.Save(operationsXMLFileName + ".xml");
}

int OperationXML::getLastOperationID()
{
    CMarkup xml;
    int temp = 0;

    xml.Load(operationsXMLFileName + ".xml");
    if (!XMLFileExists(operationsXMLFileName))
    {
        lastOperationID = 0;
        return lastOperationID;
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Operation"))
    {
        xml.FindChildElem("OperationID");
        int operationID = stoi(xml.GetChildData());
        temp = max(temp, operationID);
        xml.ResetChildPos();
    }

    lastOperationID = temp;
    xml.Save(operationsXMLFileName + ".xml");
    return lastOperationID;
}

vector<Operation> OperationXML::loadOperationsFromXMLFile()
{
    vector<Operation> operations;
    CMarkup xml;

    xml.Load(operationsXMLFileName + ".xml");
    if (!XMLFileExists(operationsXMLFileName))
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Operations");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Operation"))
    {
        xml.FindChildElem("OperationID");
        int operationID = stoi(xml.GetChildData());
        xml.ResetChildPos();

        xml.FindChildElem("UserID");
        int userID = stoi(xml.GetChildData());
        xml.ResetChildPos();

        xml.FindChildElem("Date");
        string date = xml.GetChildData();
        xml.ResetChildPos();

        xml.FindChildElem("Item");
        string item = xml.GetChildData();
        xml.ResetChildPos();

        xml.FindChildElem("Amount");
        double amount = stod(xml.GetChildData());
        xml.ResetChildPos();

        Operation operation(operationID, userID, stoi(AuxiliaryMethods::dateToStoreFormat(date)), item, amount);
        operations.push_back(operation);
    }

    xml.Save(operationsXMLFileName + ".xml");

    return operations;
}
