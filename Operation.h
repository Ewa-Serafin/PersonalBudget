#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;
#include "OperationType.h"

class Operation {

    int date;
    int operationID;
    int userID;
    string item;
    double amount;
    OperationType type;

public:

    void setDate(int newDate);
    void setOperationID(int newOperationID);
    void setUserID(int newUserID);
    void setItem(string newItem);
    void setAmount(double newAmount);
    void setType(OperationType newType);

    int getDate()const;
    int getOperationID()const;
    int getUserID()const;
    string getItem()const;
    double getAmount() const;
    OperationType getType() const;

    //bool operator<(const Operation& other) const;
};

#endif
