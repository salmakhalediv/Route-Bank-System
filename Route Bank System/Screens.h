#pragma once
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "Client.h"
#include "FilesHelper.h"
#include <iostream>
#include "ClientManager.h"
using namespace std;

class Screens {
public:
    static void bankName() {
        cout << "=================================\n";
        cout << "        Bankont System \n";
        cout << "=================================\n";
    }

    static void welcome() { cout << "Welcome to the Banking System\n"; }

    
    static int loginAs() {
        int choice;
        do {
            cout << "Login As:\n1. Client\n2. Employee\n3. Admin\nChoose: ";
            cin >> choice;
        } while (choice < 1 || choice > 3);

        return choice;
    }

    static void invalid(int c) { cout << "Invalid Choice! " << endl; }

    static void logout() { cout << "Logged Out Successfully" << endl; }

    static void loginScreen(int c) {
        int id; string password;
        cout << "Enter ID: "; cin >> id;
        cout << "Enter Password: "; cin >> password;
        if (c == 1) {
            Client* client = ClientManager::login(id, password);
            if (client) ClientManager::clientOptions(client);
            else cout << "Login Failed" << endl;
        }
        else if (c == 2) {
            Employee* employee = EmployeeManager::login(id, password);
            if (employee) EmployeeManager::employeeOptions(employee);
            else cout << "Login Failed" << endl;
        }
        else if (c == 3) {
            Admin* admin = AdminManager::login(id, password);
            if (admin) AdminManager::AdminOptions(admin);
            else cout << "Login Failed" << endl;
        }
        else invalid(c);
    }

    static void runApp() {
        while (true) {
            FilesHelper::getClients();
            FilesHelper::getEmployees();
            FilesHelper::getAdmins();
            bankName();
            welcome();
            int choice = loginAs();
            loginScreen(choice);
            logout();
            cout << "Press 0 to Exit or any number to continue: ";
            int exitChoice; cin >> exitChoice;
            if (exitChoice == 0) break;
        }
    }
};