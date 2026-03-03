#pragma once
#include "Employee.h"
#include "Client.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Admin : public Employee {
    vector<Employee> employees;
    vector<Client> clients;
    vector<Admin> admins;

public:
    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary) {
    }

    Admin() {};

    void addClient(Client& client) {
        clients.push_back(client);
        ofstream file("Clients.txt", ios::app);
        file << client.getid() << "," << client.getname() << "," << client.getpassword() << "," << client.getbalance() << endl;
        file.close();
    }

    Client* searchClient(int id) {
        for (auto& c : clients) {
            if (c.getid() == id) return &c;
        }
        return nullptr;
    }

    void listClient() {
        for (auto& c : clients) {
            c.printdata();
            cout << "-----------------\n";
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

    void addEmployee(Employee& emp) {
        employees.push_back(emp);
        ofstream file("Employees.txt", ios::app);
        file << emp.getid() << "," << emp.getname() << "," << emp.getpassword() << "," << emp.getSalary() << endl;
        file.close();
    }

    Employee* searchEmployee(int id) {
        for (auto& e : employees) {
            if (e.getid() == id) return &e;
        }
        return nullptr;
    }

    void listEmployee() {
        for (auto& e : employees) {
            e.printdata();
            cout << "\n";
        }
    }

    void editEmployee(int id, string name, string password, double salary) {
        for (auto& e : employees) {
            if (e.getid() == id) {
                e.setname(name);
                e.setpassword(password);
                e.setSalary(salary);
            }
        }
        ofstream file("Employees.txt", ios::trunc);
        for (auto& e : employees) {
            file << e.getid() << "," << e.getname() << "," << e.getpassword() << "," << e.getSalary() << endl;
        }
        file.close();
    }
};