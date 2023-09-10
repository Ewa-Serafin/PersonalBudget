#include "DateMethods.h"

bool DateMethods::validateDate(string &date) {
    map<string, int> currentDate;
    calculateCurrentDate(currentDate);

    if (date == "t" || date == "T") {
        stringstream ss;
        ss << currentDate["year"] << "-" << (currentDate["month"] < 10 ? "0" : "") << currentDate["month"] << "-" << (currentDate["day"] < 10 ? "0" : "") << currentDate["day"];
        date = ss.str();
        return true;
    }

    if (date.length() != 10 || !regex_match(date, regex("[0-9]{4}-[0-9]{2}-[0-9]{2}"))) {
        cout << "Incorrect date format. Try again." << endl;
        return false;
    }

    int year, month, day;
    try {
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));
    } catch (const exception& e) {
        cout << "Exception occurred: " << e.what() << endl;
        return false;
    }

    if (year < 2000 || year > currentDate["year"]) {
        cout << "Invalid year. Try again." << endl;
        return false;
    }

    if (month < 1 || month > 12 || (year == currentDate["year"] && month > currentDate["month"])) {
        cout << "Invalid month. Try again." << endl;
        return false;
    }

    int lastDayOfMonth = 31;

    switch (month) {
    case 4:
    case 6:
    case 9:
    case 11:
        lastDayOfMonth = 30;
        break;
    case 2:
        if (DateMethods::isYearLeap(year)) {
            lastDayOfMonth = 29;
        } else {
            lastDayOfMonth = 28;
        }
        break;
    }

    if (day < 1 || day > lastDayOfMonth || (year == currentDate["year"] && month == currentDate["month"] && day > currentDate["day"])) {
        cout << "Invalid day. Try again." << endl;
        return false;
    }
    return true;
}

int DateMethods::convertStringDateToInt(const string &dateAsString) {
    int year = 0, month = 0, day = 0;

    try {
        year = atoi(dateAsString.substr(0, 4).c_str());
        month = atoi(dateAsString.substr(5, 2).c_str());
        day = atoi(dateAsString.substr(8, 2).c_str());
    } catch (const exception& e) {
        cout << "Exception occurred: " << e.what() << endl;
        return 0;
    }
    return year * 10000 + (month) * 100 + day;

}

string DateMethods::convertIntDateToStringWithDashes(int dateAsInt) {
    string dateAsString = to_string(dateAsInt);

    return dateAsString.substr(0, 4) + '-' + dateAsString.substr(4, 2) + '-' + dateAsString.substr(6, 2);
}


int DateMethods::getCurrentDate() {
    map<string, int> currentDate;
    calculateCurrentDate(currentDate);

    return currentDate["year"] * 10000 + currentDate["month"] * 100 + currentDate["day"];
}

int DateMethods::getCurrentMonthFirstDayDate() {
    return getCurrentDate() / 100 * 100 + 1;
}

int DateMethods::getPreviousMonthFirstDayDate() {
    int year, month, day = 1;
    map<string, int> currentDate;
    calculateCurrentDate(currentDate);

    month = currentDate["month"] - 1;
    year = currentDate["year"];

    if (month == 0) {
        month = 12;
        year--;
    }

    return year * 10000 + month * 100 + day;
}

int DateMethods::getPreviousMonthLastDayDate() {
    int year, month, day = 0;
    map<string, int> currentDate;
    calculateCurrentDate(currentDate);

    month = currentDate["month"] - 1;
    year = currentDate["year"];

    if (month == 0) {
        month = 12;
        year--;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
        day = 30;
    else if (month == 2) {
        if (isYearLeap(year))
            day = 29;
        else
            day = 28;
    } else {
        day = 31;
    }

    return year * 10000 + month * 100 + day;
}

void DateMethods::calculateCurrentDate(map<string, int>& currentDate) {
    auto currentTime = chrono::system_clock::now();
    time_t currentDateTime = chrono::system_clock::to_time_t(currentTime);

    tm currentTm;
    localtime_s(&currentTm, &currentDateTime);

    currentDate["year"] = currentTm.tm_year + 1900;
    currentDate["month"] = currentTm.tm_mon + 1;
    currentDate["day"] = currentTm.tm_mday;
}

bool DateMethods::isYearLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

string DateMethods::getCurrentDateAsString() {
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    struct tm timeInfo;
    localtime_s(&timeInfo, &time);

    string currentDate = to_string(timeInfo.tm_year + 1900) + "-"
                         + (timeInfo.tm_mon < 9 ? "0" : "") + to_string(timeInfo.tm_mon + 1) + "-"
                         + (timeInfo.tm_mday < 10 ? "0" : "") + to_string(timeInfo.tm_mday);

    return currentDate;
}

