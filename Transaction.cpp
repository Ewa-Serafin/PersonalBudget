#include "Transaction.h"

void Transaction::setDate(int newDate)
{
    date = newDate;
}

void Transaction::setTransactionID(int newTransactionID)
{
    if (newTransactionID > 0)
        transactionID = newTransactionID;
}

void Transaction::setUserID(int newUserID)
{
    if (newUserID > 0)
        userID = newUserID;
}

void Transaction::setItem(string newItem)
{
    item = newItem;
}

void Transaction::setAmount(double newAmount)
{
    amount = newAmount;
}

int Transaction::getDate()
{
    return date;
}

int Transaction::getTransactionID()
{
    return transactionID;
}

int Transaction::getUserID()
{
    return userID;
}

string Transaction::getItem()
{
    return item;
}

double Transaction::getAmount()
{
    return amount;
}
