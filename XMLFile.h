#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class XMLFile {

    const string XML_FILE_NAME;

public:

    XMLFile(string XMLFileName) :  XML_FILE_NAME(XMLFileName) {}

    bool XMLFileExists(string XMLFileName);
    string getXMLFileName();
};
#endif

