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
