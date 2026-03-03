#pragma once
#include "Data_Source_Interface.h"
#include "FilesHelper.h"
#include "Employee.h"
#include "Admin.h"

class FileManager : public Data_Source_Interface {
public:
    void addClient(Client& obj) override { FilesHelper::saveClient(obj); }
    void addEmployee(Employee& obj) override { FilesHelper::saveEmployee("Employees.txt", "lastEmployeeId.txt", obj); }
    void addAdmin(Admin& obj) override { FilesHelper::saveEmployee("Admins.txt", "lastAdminId.txt", obj); }

    void getAllClients() override { FilesHelper::getClients(); }
    void getAllEmployees() override { FilesHelper::getEmployees(); }
    void getAllAdmins() override { FilesHelper::getAdmins(); }

    void removeAllClients() override { FilesHelper::clearFile("Clients.txt", "lastClientId.txt"); }
    void removeAllEmployees() override { FilesHelper::clearFile("Employees.txt", "lastEmployeeId.txt"); }
    void removeAllAdmins() override { FilesHelper::clearFile("Admins.txt", "lastAdminId.txt"); }
};