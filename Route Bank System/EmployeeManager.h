#pragma once
#include "Employee.h"
#include "Client.h"
#include "FilesHelper.h"
#include "Validation.h"
#include <iostream>
using namespace std;

class EmployeeManager {
public:

    static Employee* login(int id, string password) {
        FilesHelper::getEmployees();
        for (auto& e : employees) {
            if (e.getid() == id && e.getpassword() == password)
                return &e;
        }
        return nullptr;
    }

    //static Client* login(int id, string password) {
    //    FilesHelper::getClients();
    //    for (auto& c : clients) {
    //        if (c.getid() == id && c.getpassword() == password)
    //            return &c;
    //    }
    //    return nullptr;
    //}

    static void printEmployeeMenu() {
        cout << "\n===== Employee Menu =====" << endl;
        cout << "1. Add New Client" << endl;
        cout << "2. Search Client" << endl;
        cout << "3. List Clients" << endl;
        cout << "4. Edit Client" << endl;
        cout << "5. Logout" << endl;
        cout << "Choose: ";
    }

    static void addNewClient(Employee* employee) {

        string name, password;
        double balance;

        cout << "Enter Client Name: ";
        cin >> name;

        while (!Validation::ValidName(name)) {
            cout << "Invalid Name, enter again: ";
            cin >> name;
        }

        cout << "Enter Client Password: ";
        cin >> password;

        while (!Validation::ValidPassword(password)) {
            cout << "Invalid Password, enter again: ";
            cin >> password;
        }

        cout << "Enter Client Balance: ";
        cin >> balance;

        while (balance < 0) {
            cout << "Invalid Balance, enter again: ";
            cin >> balance;
        }

        int id = employees.size() + clients.size() + 1;

        Client c(id, name, password, balance);

        clients.push_back(c);
        FilesHelper::updateClientsFile();

        cout << "Client added successfully." << endl;
    }

    static Client* searchClient(int id) {

        FilesHelper::getClients();

        for (auto& c : clients) {
            if (c.getid() == id)
                return &c;
        }

        return nullptr;
    }

    static void listClients() {

        FilesHelper::getClients();

        for (auto& c : clients) {
            c.printdata();
            cout << "------------------" << endl;
        }
    }

    static void editClient(int id) {

        Client* client = searchClient(id);

        if (!client) {
            cout << "Client not found." << endl;
            return;
        }

        string name, password;
        double balance;

        cout << "Enter New Name: ";
        cin >> name;

        while (!Validation::ValidName(name)) {
            cout << "Invalid Name, enter again: ";
            cin >> name;
        }

        cout << "Enter New Password: ";
        cin >> password;

        while (!Validation::ValidPassword(password)) {
            cout << "Invalid Password, enter again: ";
            cin >> password;
        }

        cout << "Enter New Balance: ";
        cin >> balance;

        while (balance < 0) {
            cout << "Invalid Balance, enter again: ";
            cin >> balance;
        }

        client->setname(name);
        client->setpassword(password);
        client->setbalance(balance);

        FilesHelper::updateClientsFile();

        cout << "Client updated successfully." << endl;
    }

    static bool employeeOptions(Employee* employee) {

        int choice;

        while (true) {

            printEmployeeMenu();
            cin >> choice;

            switch (choice) {

            case 1:
                addNewClient(employee);
                break;

            case 2: {
                int id;
                cout << "Enter Client ID: ";
                cin >> id;
                Client* c = searchClient(id);
                if (c)
                    c->printdata();
                else
                    cout << "Client not found." << endl;
                break;
            }

            case 3:
                listClients();
                break;

            case 4: {
                int id;
                cout << "Enter Client ID to edit: ";
                cin >> id;
                editClient(id);
                break;
            }

            case 5:
                return false;

            default:
                cout << "Invalid Choice" << endl;
            }
        }
    }
};