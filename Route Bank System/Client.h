#pragma once
#include "Person.h"
#include "Validation.h"
#include <iostream>
using namespace std;

class Client : public Person {
private:
    double balance;

public:
    Client(int id, string name, string password, double balance)
        : Person(id, name, password) {
        this->balance = balance;
    }

    void setbalance(double balance) {
        while (!Validation::ValidBalance(balance)) {
            cout << "Enter salary again: ";
            cin >> balance;
        }
        this->balance = balance;
    }

    double getbalance() const {
        return balance;
    }

    void deposit(double amount) {
        while (amount <= 0) {
            cout << "Please enter a valid amount (> 0): ";
            cin >> amount;
        }
        balance += amount;
    }

    void withdraw(double amount) {
        while (amount <= 0 || amount > balance) {
            cout << "your balance is " << balance << " Please enter a valid amount : ";
            cin >> amount;
        }
        balance -= amount;
    }

    void transferTo(double amount, Client& recipient) {
        while (amount <= 0 || amount > balance) {
            cout << "your balance is " << balance << " Please enter a valid amount : ";
            cin >> amount;
        }
        balance -= amount;
        recipient.balance += amount;
    }

    void printdata() {
        cout << "Client ID: " << getid() << endl;
        cout << "Client Name: " << getname() << endl;
        cout << "Client Password: " << getpassword() << endl;
        cout << "Client Balance: " << balance << endl;
    }
};