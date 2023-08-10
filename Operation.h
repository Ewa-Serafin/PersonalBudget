#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;


class Operation{

    int date;
    int operationID;
    int userID;
    string item;
    double amount;

    public:
    Operation(int date = 0, int OperationID = 0, int userID = 0, string item = "", double amount = 0):
        date(date), operationID(operationID), userID(userID), item(item), amount(amount) {}

    bool operator < (const Operation& other) const
    {
        return (date < other.date);
    }

    void setDate(int newDate);
    void setOperationID(int newOperationID);
    void setUserID(int newUserID);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getDate();
    int getOperationID();
    int getUserID();
    string getItem();
    double getAmount();
};



#endif
