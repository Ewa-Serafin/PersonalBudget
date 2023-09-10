#ifndef FINANCIALMANAGER_H
#define FINANCIALMANAGER_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iomanip>

#include "Operation.h"
#include "OperationType.h"
#include "OperationXML.h"
#include "DateMethods.h"
#include "CalculationsMethods.h"
#include "AuxiliaryMethods.h"
#include "UserManager.h"

class FinancialManager {
    const int LOGGED_USER_ID;
    vector<Operation> incomes;
    vector<Operation> expenses;
    OperationXML incomeFile;
    OperationXML expenseFile;

    double result;

    Operation insertNewOperationData(const OperationType &type);

    void showBalance(int startDate, int endDate);
    double calculateBalance(int startDate, int endDate, const OperationType &type);

public:
    FinancialManager(string incomesXMLFileName, string expensesXMLFileName, int loggedInUserID)
        : LOGGED_USER_ID(loggedInUserID),incomeFile(incomesXMLFileName), expenseFile(expensesXMLFileName) {
        incomes = incomeFile.loadOperationsFromXMLFile(LOGGED_USER_ID);
        expenses = expenseFile.loadOperationsFromXMLFile(LOGGED_USER_ID);
    }

    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void displayLastMonthBalance();
    void displayBalanceFromSelectedDates();
};

#endif
