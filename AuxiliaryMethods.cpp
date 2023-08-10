#include "AuxiliaryMethods.h"

string AuxiliaryMethods::readLine() {
    string input = "";
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char AuxiliaryMethods::readCharacter() {
    string input = "";
    char character   = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            character = input[0];
            break;
        }
        cout << "This is not a single character. Please try again." << endl;
    }
    return character;
}

 string AuxiliaryMethods::dateToDispalyFormat(string date)
{
    if (date.length() != 8)
        return date;

    string year = date.substr(0, 4);
    string month = date.substr(4, 2);
    string day = date.substr(6, 2);

    return day + "-" + month + "-" + year;
}

string AuxiliaryMethods::dateToStoreFormat(string date)
{
    string dateToStore = "";

    dateToStore = date.substr(0, 4) + date.substr(5, 2) + date.substr(8, 2);

    return dateToStore;
}
