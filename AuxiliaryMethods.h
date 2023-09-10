#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class AuxiliaryMethods {

public:
    static string replaceCommaWithDot(string& text);
    static string readLine();
    static char readCharacter();
    static string convertIntToString(int number);
    static string convertDoubleToString(double number);
    static int convertStringToInt(string number);
};
#endif
