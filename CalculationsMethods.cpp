#include "CalculationsMethods.h"

bool CalculationsMethods::validateAmount(string& amount) {
    if (amount.empty()) {
        cout << "Amount field cannot be empty. Try again." << endl;
        return false;
    }

    AuxiliaryMethods::replaceCommaWithDot(amount);

    size_t dotCount = count(amount.begin(), amount.end(), '.');
    if (dotCount > 1) {
        cout << "Incorrect number format. Try again." << endl;
        return false;
    }

    double value;
    if (!tryConvertToDouble(amount, value)) {
        cout << "Invalid amount. Please try again." << endl;
        return false;
    }

    amount = AuxiliaryMethods::convertDoubleToString(value);

    return true;
}

bool CalculationsMethods::tryConvertToDouble(const string& str, double& result) {
    try {
        result = stod(str);
        return true;
    } catch (const exception&) {
        return false;
    }
}

