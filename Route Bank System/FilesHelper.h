#pragma once
#include <vector>
#include <fstream>
#include "Parser.h"
using namespace std;

static vector<Employee> employees;
static vector<Client> clients;
static vector<Admin> admins;

class FilesHelper {
public:

    static void saveClient(Client c) {
        int id = getLast("lastClientId.txt") + 1;
        saveLast("lastClientId.txt", id);

        Client newClient(id, c.getname(), c.getpassword(), c.getbalance());
        ofstream file("Clients.txt", ios::app);
        if (file.is_open()) {
            file << newClient.getid() << "," << newClient.getname() << "," << newClient.getpassword() << "," << newClient.getbalance() << endl;
        }
        file.close();
        clients.push_back(newClient);
    }

    static void saveEmployee(string fileName, string lastIdFile, Employee e) {
        int id = getLast(lastIdFile) + 1;
        saveLast(lastIdFile, id);

        Employee newEmp(id, e.getname(), e.getpassword(), e.getSalary());
        ofstream file(fileName, ios::app);
        if (file.is_open()) {
            file << newEmp.getid() << "," << newEmp.getname() << "," << newEmp.getpassword() << "," << newEmp.getSalary() << endl;
        }
        file.close();
        employees.push_back(newEmp);
    }

    static void saveLast(string fileName, int id) {
        ofstream file(fileName);
        file << id;
        file.close();
    }

    static int getLast(string fileName) {
        ifstream file(fileName);
        int id = 0;
        if (file.is_open())
            file >> id;
        file.close();
        return id;
    }

    static void updateClientsFile() {
        ofstream file("Clients.txt", ios::trunc);
        for (auto& c : clients)
            file << c.getid() << "," << c.getname() << "," << c.getpassword() << "," << c.getbalance() << endl;
        file.close();
    }

    static void updateEmployeesFile() {
        ofstream file("Employees.txt", ios::trunc);
        for (auto& e : employees)
            file << e.getid() << "," << e.getname() << "," << e.getpassword() << "," << e.getSalary() << endl;
        file.close();
    }

    static void getClients() {
        clients.clear();
        ifstream file("Clients.txt");
        string line;
        while (getline(file, line))
            clients.push_back(Parser::parseToClient(line));
        file.close();
    }

    static void getEmployees() {
        employees.clear();
        ifstream file("Employees.txt");
        string line;
        while (getline(file, line))
            employees.push_back(Parser::parseToEmployee(line));
        file.close();
    }

    static void getAdmins() {
        admins.clear();
        ifstream file("Admins.txt");
        string line;
        while (getline(file, line))
            admins.push_back(Parser::parseToAdmin(line));
        file.close();
    }
    static void clearFile(string fileName, string lastIdFile) {
        ofstream file(fileName, ios::trunc);
        file.close();
        saveLast(lastIdFile, 0);
    }


};