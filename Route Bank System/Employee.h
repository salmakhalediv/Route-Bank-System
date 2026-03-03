#pragma once
#include "Person.h"
#include "Client.h"
#include "Validation.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Employee : public Person {
private:
    double salary;
protected:
    vector<Client> clients;

public:
    Employee(int id, string name, string password, double salary)
        : Person(id, name, password) {
        setSalary(salary);
    }

    Employee() {};

    void setSalary(double salary) {
        while (!Validation::ValidSalary(salary)) {
            cout << "Enter salary again: ";
            cin >> salary;
        }
        this->salary = salary;
    }

    double getSalary() const {
        return salary;
    }

    void printdata() {
        cout << "Employee ID: " << getid() << endl;
        cout << "Employee Name: " << getname() << endl;
        cout << "Employee Password: " << getpassword() << endl;
        cout << "Employee Salary: " << salary << endl;
    }

    void addclient(Client& c) {
        clients.push_back(c);
        ofstream file("Clients.txt", ios::app);
        file << c.getid() << "," << c.getname() << "," << c.getpassword() << "," << c.getbalance() << endl;
        file.close();
    }

    Client* searchClient(int id) {
        for (auto& c : clients) {
            if (c.getid() == id)
                return &c;
        }
        return nullptr;
    }

    void listClient() {
        for (auto& c : clients) {
            c.printdata();
            cout << "\n";
        }
    }

    void editClient(int id, string name, string password, double balance) {
        for (auto& c : clients) {
            if (c.getid() == id) {
                c.setname(name);
                c.setpassword(password);
                c.setbalance(balance);
            }
        }
        ofstream file("Clients.txt", ios::trunc);
        for (auto& c : clients) {
            file << c.getid() << "," << c.getname() << "," << c.getpassword() << "," << c.getbalance() << endl;
        }
        file.close();
    }
};