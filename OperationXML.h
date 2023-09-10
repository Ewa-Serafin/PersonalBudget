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
#include "DateMethods.h"

using namespace std;

class OperationXML : public XMLFile

{
    int lastOperationID;

public:

    OperationXML(string operationXMLFileName): XMLFile(operationXMLFileName) {
      lastOperationID = 0;
    }

    vector <Operation> loadOperationsFromXMLFile(const int loggedInUserId);
    bool addOperationToXMLFile(Operation &operation);
    int getLastOperationID(const int loggedInUserId);
};

#endif



