#ifndef CALCULATIONSMETHODS_H
#define CALCULATIONSMETHODS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

#include "Operation.h"
#include "AuxiliaryMethods.h"

using namespace std;

class CalculationsMethods {
public:

    static bool validateAmount(string& amount);
    static bool tryConvertToDouble(const string& str, double& result);
};
#endif
