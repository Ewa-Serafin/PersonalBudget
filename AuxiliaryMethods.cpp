#include "AuxiliaryMethods.h"

string AuxiliaryMethods::readLine() {
    string input = "";
    cin.sync();
    getline(cin, input);
    return input;
}

string AuxiliaryMethods::replaceCommaWithDot(string& text) {
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] == ',') {
            text[i] = '.';
        }
    }
    return text;
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

string AuxiliaryMethods::convertIntToString (int number ) {
    ostringstream ss;
    ss << number;
    return ss.str();
}

string AuxiliaryMethods::convertDoubleToString(double number) {
    ostringstream ss;
    ss << fixed << setprecision(2) << number;
    return ss.str();
}

int AuxiliaryMethods::convertStringToInt(string number) {
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}
