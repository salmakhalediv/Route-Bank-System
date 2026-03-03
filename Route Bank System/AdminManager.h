#pragma once
#include "Admin.h"
#include "Employee.h"
#include "FilesHelper.h"
#include "Validation.h"
#include <iostream>
using namespace std;

class AdminManager {
public:

    static Admin* login(int id, string password) {
        FilesHelper::getAdmins();
        for (auto& a : admins) {
            if (a.getid() == id && a.getpassword() == password)
                return &a;
        }
        return nullptr;
    }

    static void printAdminMenu() {
        cout << "\n===== Admin Menu =====" << endl;
        cout << "1. Add New Employee" << endl;
        cout << "2. Search Employee" << endl;
        cout << "3. List Employees" << endl;
        cout << "4. Edit Employee" << endl;
        cout << "5. Logout" << endl;
        cout << "Choose: ";
    }

    static void addNewEmployee(Admin* admin) {

        string name, password;
        double salary;

        cout << "Enter Employee Name: ";
        cin >> name;

        while (!Validation::ValidName(name)) {
            cout << "Invalid Name, enter again: ";
            cin >> name;
        }

        cout << "Enter Employee Password: ";
        cin >> password;

        while (!Validation::ValidPassword(password)) {
            cout << "Invalid Password, enter again: ";
            cin >> password;
        }

        cout << "Enter Employee Salary: ";
        cin >> salary;

        while (salary <= 0) {
            cout << "Invalid Salary, enter again: ";
            cin >> salary;
        }

        int id = admins.size() + employees.size() + clients.size() + 1;

        Employee e(id, name, password, salary);

        employees.push_back(e);
        FilesHelper::updateEmployeesFile();

        cout << "Employee added successfully." << endl;
    }

    static Employee* searchEmployee(int id) {

        FilesHelper::getEmployees();

        for (auto& e : employees) {
            if (e.getid() == id)
                return &e;
        }

        return nullptr;
    }

    static void listEmployees() {

        FilesHelper::getEmployees();

        for (auto& e : employees) {
            e.printdata();
            cout << "------------------" << endl;
        }
    }

    static void editEmployee(int id) {

        Employee* employee = searchEmployee(id);

        if (!employee) {
            cout << "Employee not found." << endl;
            return;
        }

        string name, password;
        double salary;

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

        cout << "Enter New Salary: ";
        cin >> salary;

        while (salary <= 0) {
            cout << "Invalid Salary, enter again: ";
            cin >> salary;
        }

        employee->setname(name);
        employee->setpassword(password);
        employee->setSalary(salary);

        FilesHelper::updateEmployeesFile();

        cout << "Employee updated successfully." << endl;
    }

    static bool AdminOptions(Admin* admin) {

        int choice;

        while (true) {

            printAdminMenu();
            cin >> choice;

            switch (choice) {

            case 1:
                addNewEmployee(admin);
                break;

            case 2: {
                int id;
                cout << "Enter Employee ID: ";
                cin >> id;
                Employee* e = searchEmployee(id);
                if (e)
                    e->printdata();
                else
                    cout << "Employee not found." << endl;
                break;
            }

            case 3:
                listEmployees();
                break;

            case 4: {
                int id;
                cout << "Enter Employee ID to edit: ";
                cin >> id;
                editEmployee(id);
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