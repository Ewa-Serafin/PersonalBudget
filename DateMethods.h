#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <chrono>
#include <ctime>
#include <regex>
#include <sstream>
#include <string>

#include "Operation.h"
#include "OperationXML.h"
#include "AuxiliaryMethods.h"

using namespace std;

class DateMethods {

public:
    static bool validateDate(string &date);
    static int convertStringDateToInt(const string &dateAsString);
    static  string convertIntDateToStringWithDashes(int dateAsInt);
    static int getCurrentDate();
    static int getCurrentMonthFirstDayDate();
    static int getPreviousMonthFirstDayDate();
    static int getPreviousMonthLastDayDate();
    static void calculateCurrentDate(map<string, int>& currentDate);
    static bool isYearLeap(int year);
    static string getCurrentDateAsString();
};
#endif

