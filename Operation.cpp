#include "Operation.h"

void Operation::setDate(int newDate) {
    date = newDate;
}

void Operation::setOperationID(int newOperationID) {
    if (newOperationID > 0)
        operationID = newOperationID;
}

void Operation::setUserID(int newUserID) {
    if (newUserID > 0)
        userID = newUserID;
}

void Operation::setItem(string newItem) {
    item = newItem;
}

void Operation::setAmount(double newAmount) {
    amount = newAmount;
}
void Operation::setType(OperationType newType) {
    type = newType;
}

int Operation::getDate()const {
    return date;
}

int Operation::getOperationID()const {
    return operationID;
}

int Operation::getUserID()const {
    return userID;
}

string Operation::getItem()const {
    return item;
}

double Operation::getAmount() const {
    return amount;
}

OperationType Operation::getType() const {
    return type;
}

