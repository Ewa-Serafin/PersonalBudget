#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
//#include <algorithm>


using namespace std;

class AuxiliaryMethods {
public:
    static string readLine();
    static string convertIntToString(int number);
    static char readCharacter();
    static string dateToDispalyFormat(string date);
    static string dateToStoreFormat(string date);

};

#endif
