#ifndef OPERATIONXML_H
#define OPERATIONXML_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "Markup.h"
#include "Operation.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"

using namespace std;

class OperationXML : public XMLFile
{
    int lastOperationID;
    string operationsXMLFileName;

public:

    OperationXML(string operationsXMLFileNameParam)
        : XMLFile(operationsXMLFileNameParam), operationsXMLFileName(operationsXMLFileNameParam)
    {
        lastOperationID = 0;
    };

    vector <Operation> loadOperationsFromXMLFile();
    void addOperationToXMLFile(Operation operation);
    int getLastOperationID();

};

#endif
