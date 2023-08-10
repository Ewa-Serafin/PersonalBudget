#include "Operation.h"

void Operation::setDate(int newDate)
{
    date = newDate;
}

void Operation::setOperationID(int newOperationID)
{
    if (newOperationID > 0)
        operationID = newOperationID;
}

void Operation::setUserID(int newUserID)
{
    if (newUserID > 0)
        userID = newUserID;
}

void Operation::setItem(string newItem)
{
    item = newItem;
}

void Operation::setAmount(double newAmount)
{
    amount = newAmount;
}

int Operation::getDate()
{
    return date;
}

int Operation::getOperationID()
{
    return operationID;
}

int Operation::getUserID()
{
    return userID;
}

string Operation::getItem()
{
    return item;
}

double Operation::getAmount()
{
    return amount;
}
