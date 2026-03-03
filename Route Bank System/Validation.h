#pragma once
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Validation
{
public:
    void take_input_Employee(string& name, string& password, double& salary) {
        cout << "Enter Employee name : ";
        getline(cin, name);
        while (!ValidName(name)) getline(cin, name);
        cout << "Name Saved\n";

        cout << "Enter your password : ";
        getline(cin, password);
        while (!ValidPassword(password)) getline(cin, password);
        cout << "password Saved" << endl;

        cout << "Enter salary :";
        while (!(cin >> salary)) {
            cout << "please enter numbers only : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();
        while (!ValidSalary(salary)) cin >> salary;
        cout << "Added salary" << endl;
    }

    void take_input_Client(string& name, string& password, double& balance) {
        cout << "Enter your name : ";
        getline(cin, name);
        while (!ValidName(name)) getline(cin, name);
        cout << "Name Saved\n";

        cout << "Enter your password : ";
        getline(cin, password);
        while (!ValidPassword(password)) getline(cin, password);
        cout << "password Saved" << endl;

        cout << "Enter your balance : ";
        while (!(cin >> balance)) {
            cout << "please enter numbers only : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore();
        while (!ValidBalance(balance)) cin >> balance;
        cout << "Added balacne" << endl;
    }

    static bool ValidName(string& name) {
        if (name.length() < 3 || name.length() > 20) {
            cout << "Invalid name: length must be 3-20 characters.\n Please enter the name again : ";
            return false;
        }
        for (int i = 0; i < name.length(); i++) {
            if (name[i] == ' ') {
                cout << "Invalid name: spaces are not allowed.\nPlease enter the name again : ";
                return false;
            }
            if (!isalpha(name[i])) {
                cout << "Invalid name: letters only allowed. \nPlease enter the name again : ";
                return false;
            }
        }
        return true;
    }

    static bool ValidPassword(string& password) {
        if (password.length() < 8 || password.length() > 20) {
            cout << "Invalid password: length must be 8-20 characters. \nPlease enter the password again : ";
            return false;
        }
        for (int i = 0; i < password.length(); i++) {
            if (password[i] == ' ') {
                cout << "Invalid password: spaces are not allowed. \nPlease enter the password again : ";
                return false;
            }
        }
        return true;
    }

    static bool ValidSalary(double& salary) {
        if (salary < 5000) {
            cout << "Invalid salary: The salary must be greater than 5000  \nPlease enter the amount again : ";
            return false;
        }
        return true;
    }

    static bool ValidBalance(double& balance) {
        if (balance < 1500) {
            cout << "Invalid balacne: The balance must be greater than 1500.  \nPlease enter the amount again : ";
            return false;
        }
        return true;
    }
};