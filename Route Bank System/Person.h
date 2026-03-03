#pragma once
#include "Validation.h"
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    string password;
    int id;

public:
    Person() {};
    Person(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }

    void setname(string name) {
        if (Validation::ValidName(name)) this->name = name;
    }

    string getname() const { return name; }
    int getid() const { return id; }

    void setpassword(string password) {
        if (Validation::ValidPassword(password)) this->password = password;
    }

    string getpassword() const { return password; }

    void printdata() {
        cout << "Your ID is " << getid() << endl;
        cout << "Your Name is " << getname() << endl;
        cout << "Your Password is " << getpassword() << endl;


    }
};