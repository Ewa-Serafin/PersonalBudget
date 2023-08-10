#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;


class Transaction{

    int date;
    int transactionID;
    int userID;
    string item;
    double amount;

    public:
    Transaction(int date = 0, int transactionID = 0, int userID = 0, string item = "", double amount = 0)
    {
        this->date = date;
        this->transactionID = transactionID;
        this->userID = userID;
        this->item = item;
        this->amount = amount;
    }

    bool operator < (const Transaction& other) const
    {
        return (date < other.date);
    }

    void setDate(int newDate);
    void setTransactionID(int newTransactionID);
    void setUserID(int newUserID);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getDate();
    int getTransactionID();
    int getUserID();
    string getItem();
    double getAmount();
};



#endif
