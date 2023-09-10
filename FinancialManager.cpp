#include "FinancialManager.h"

Operation FinancialManager::insertNewOperationData(const OperationType &type) {

    Operation operation;
    string temporaryDate, typeDescription;

    if (type == OperationType::INCOME) {
        operation.setOperationID(incomeFile.getLastOperationID(LOGGED_USER_ID) + 1);
        typeDescription=  "Income";

    } else if (type == OperationType::EXPENSE) {
        operation.setOperationID(expenseFile.getLastOperationID(LOGGED_USER_ID) + 1);
        typeDescription= "Expense";
    }

    operation.setUserID(LOGGED_USER_ID);

    do {
        cout << "Enter the " << typeDescription  << " date. "<< endl;
        cout << "Press 't' if you want to enter the current date or enter a different date in the format (YYYY-MM-DD): ";
        string temporaryDate = AuxiliaryMethods::readLine();
        cout << endl;
        if (temporaryDate == "t" || temporaryDate == "T") {
            temporaryDate = DateMethods::getCurrentDateAsString();
        } else if (temporaryDate.length() != 10 || temporaryDate[4] != '-' || temporaryDate[7] != '-') {
            cout << "Invalid input format. Please try again or enter 't'." << endl;
            continue;
        } else if (!DateMethods::validateDate(temporaryDate)) {
            cout << "Invalid date. Please try again." << endl;
            continue;
        }
        operation.setDate(DateMethods::convertStringDateToInt(temporaryDate));
        break;
    } while (true);

    cout << "Enter the " << typeDescription  << " name (salary, bonus, reimbursement, etc.) : ";
    operation.setItem(AuxiliaryMethods::readLine());
    cout << endl;

    do {
        cout << "Add the " << typeDescription << " amount: ";
        string temporaryAmount = AuxiliaryMethods::readLine();
        cout << endl;
        if (CalculationsMethods::validateAmount(temporaryAmount)) {

            operation.setAmount(atof(temporaryAmount.c_str()));
            break;
        } else {
            cout << "Invalid amount. Please try again." << endl;
        }
    } while (true);

    operation.setType(type);

    return operation;
}

void FinancialManager::showBalance(int startDate, int endDate) {

    cout << "Selected period: " << DateMethods::convertIntDateToStringWithDashes(startDate)
         << " to " << DateMethods::convertIntDateToStringWithDashes(endDate) << endl;
    cout << endl;
    double incomesSum = calculateBalance(startDate, endDate, OperationType::INCOME);
    double expensesSum = calculateBalance(startDate, endDate, OperationType::EXPENSE);
    result = incomesSum - expensesSum;

    cout << "Total income in the selected period: " << incomesSum << " PLN." << endl;
    cout << "Total expenses in the selected period: " << expensesSum << " PLN." << endl;
    cout << endl;
}

double FinancialManager::calculateBalance(int startDate, int endDate,const OperationType &type) {

    Operation operation;
    int counter = 0;
    double sum = 0.0;

    string description = (type == OperationType::INCOME) ? "Income" : "Expense";

    vector<Operation> relevantOperations = (type == OperationType::INCOME) ? incomes : expenses;

    if (relevantOperations.empty()) {
        cout << "No " << description << "s recorded." << endl;
        return sum;
    }

    sort(relevantOperations.begin(), relevantOperations.end(), [](const Operation& leftOp, const Operation& rightOp) {
        return leftOp.getDate() < rightOp.getDate();
    });

    cout << endl << ">> " << description << "s listed in selected period: <<" << endl << endl;

    for (const Operation& operation : relevantOperations) {
        if (operation.getDate() >= startDate && operation.getDate() <= endDate) {

            cout << "No.: " << counter + 1 << endl;
            cout << description << " date of: " << DateMethods::convertIntDateToStringWithDashes(operation.getDate()) << endl;
            cout << description << " item: " << operation.getItem() << endl;
            cout << description << " amount: " << operation.getAmount() << endl << endl;
            sum += operation.getAmount();
            ++counter;
        }
    }
    if (!counter) {
        cout << "No " << (char)tolower(description[0]) << description.substr(1) << " recorded in selected date range..." << endl << endl;
    }
    return sum;
}

void FinancialManager::addIncome() {
    system("cls");
    Operation newIncome = insertNewOperationData(OperationType::INCOME);

    if (incomeFile.addOperationToXMLFile(newIncome)) {
        incomes.push_back(newIncome);
        cout << "Income added successfully." << endl;
        system("pause");
        return;
    }
    cout << "Income was not added. Try again." << endl;
    system("pause");
}

void FinancialManager::addExpense() {
    system("cls");

    Operation newExpense = insertNewOperationData(OperationType::EXPENSE);

    if (expenseFile.addOperationToXMLFile(newExpense)) {
        expenses.push_back(newExpense);
        cout << "Expense added successfully." << endl;
        system("pause");
        return;
    }
    cout << "Expense was not added. Try again." << endl;
    system("pause");
}

void FinancialManager::currentMonthBalance() {
    system("cls");
    int startDate = DateMethods::getCurrentMonthFirstDayDate();
    int endDate = DateMethods::getCurrentDate();

    showBalance(startDate, endDate);

    cout << "Balance for the current month: " << result << endl;
    cout << endl;
    system("pause");
}

void FinancialManager::displayLastMonthBalance() {
    system("cls");
    int startDate = DateMethods::getPreviousMonthFirstDayDate();
    int endDate = DateMethods::getPreviousMonthLastDayDate();

    showBalance(startDate, endDate);
    cout << "Balance for the last month: " << result << endl;
    cout << endl;
    system("pause");
}

void FinancialManager::displayBalanceFromSelectedDates() {
    system("cls");
    string temporaryDate;
    int startDateStr, endDateStr;

    do {
        cout << "Enter START date (YYYY-MM-DD) or press 't' if you want to enter the current date: ";
        temporaryDate = AuxiliaryMethods::readLine();
        cout << endl;

        if (temporaryDate == "t" || temporaryDate == "T") {
            temporaryDate = DateMethods::getCurrentDateAsString();
        }
    } while (!DateMethods::validateDate(temporaryDate));

    startDateStr = DateMethods::convertStringDateToInt(temporaryDate);

    do {
        cout << "Enter END date or Press 't' if you want to enter current date: ";
        temporaryDate = AuxiliaryMethods::readLine();
        cout << endl;
        if (temporaryDate == "t" || temporaryDate == "T") {
            temporaryDate = DateMethods::getCurrentDateAsString();
        }
    } while (!DateMethods::validateDate(temporaryDate));

    endDateStr = DateMethods::convertStringDateToInt(temporaryDate);

    if (startDateStr > endDateStr) {
        cout << "Start date later than end date. Try again." << endl;
        cout << endl;
        system("pause");
        return;
    }

    showBalance(startDateStr, endDateStr);
    cout << "Cash balance in selected period: " << result << " PLN" << endl;
    cout << endl;
    system("pause");
}
