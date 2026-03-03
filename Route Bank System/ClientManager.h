#pragma once
#include "Client.h"
#include "FilesHelper.h"
#include "Validation.h"
#include <iostream>
using namespace std;

class ClientManager {
public:

    static Client* login(int id, string password) {
        FilesHelper::getClients();
        for (auto& c : clients) {
            if (c.getid() == id && c.getpassword() == password)
                return &c;
        }
        return nullptr;
    }

    static void printClientMenu() {
        cout << "\n===== Client Menu =====" << endl;
        cout << "1. View Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Transfer Money" << endl;
        cout << "5. Logout" << endl;
        cout << "Choose: ";
    }

    static void viewBalance(Client* client) {
        cout << "Your Balance: " << client->getbalance() << endl;
    }

    static void depositMoney(Client* client) {

        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        while (amount <= 0) {
            cout << "Invalid amount, enter again: ";
            cin >> amount;
        }

        client->deposit(amount);
        FilesHelper::updateClientsFile();

        cout << "Deposit successful. New balance: "
            << client->getbalance() << endl;
    }

    static void withdrawMoney(Client* client) {

        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        while (amount <= 0 || amount > client->getbalance()) {
            cout << "Invalid amount, enter again: ";
            cin >> amount;
        }

        client->withdraw(amount);
        FilesHelper::updateClientsFile();

        cout << "Withdraw successful. New balance: "
            << client->getbalance() << endl;
    }

    static void transferMoney(Client* client) {

        int recipientId;
        cout << "Enter recipient Client ID: ";
        cin >> recipientId;

        Client* recipient = nullptr;

        for (auto& c : clients) {
            if (c.getid() == recipientId) {
                recipient = &c;
                break;
            }
        }

        if (!recipient) {
            cout << "Recipient not found." << endl;
            return;
        }

        double amount;
        cout << "Enter amount to transfer: ";
        cin >> amount;

        while (amount <= 0 || amount > client->getbalance()) {
            cout << "Invalid amount, enter again: ";
            cin >> amount;
        }

        client->transferTo(amount, *recipient);

        FilesHelper::updateClientsFile();

        cout << "Transfer successful. Your new balance: "
            << client->getbalance() << endl;
    }

    static bool clientOptions(Client* client) {

        int choice;

        while (true) {

            printClientMenu();
            cin >> choice;

            switch (choice) {

            case 1:
                viewBalance(client);
                break;

            case 2:
                depositMoney(client);
                break;

            case 3:
                withdrawMoney(client);
                break;

            case 4:
                transferMoney(client);
                break;

            case 5:
                return false;

            default:
                cout << "Invalid Choice" << endl;
            }
        }
    }
};