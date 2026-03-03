#pragma once
#include <sstream>
#include <string>
#include <vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

class Parser
{
public:
    static vector<string> split(const string& line) {
        vector<string> data;
        string token;
        stringstream ss(line);
        while (getline(ss, token, ',')) {
            data.push_back(token);
        }
        return data;
    }

    static Client parseToClient(const string& line) {
        vector<string> data = split(line);
        int id = stoi(data[0]);
        string name = data[1];
        string password = data[2];
        double balance = stod(data[3]);
        return Client(id, name, password, balance);
    }

    static Employee parseToEmployee(const string& line) {
        vector<string> data = split(line);
        int id = stoi(data[0]);
        string name = data[1];
        string password = data[2];
        double salary = stod(data[3]);
        return Employee(id, name, password, salary);
    }

    static Admin parseToAdmin(const string& line) {
        vector<string> data = split(line);
        int id = stoi(data[0]);
        string name = data[1];
        string password = data[2];
        double salary = stod(data[3]);
        return Admin(id, name, password, salary);
    }
};