/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 2, PART 1(LAB)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    // TODO: Finish the implementation of the 1 arg load function which
    // reads one employee record from the file and loads it into the employee reference
    // argument
    bool load(Employee& employees) {
        bool ok = false;
        char name[128];
        if (read(employees.m_empNo) == true && read(employees.m_salary) == true && read(name) == true) {
            employees.m_name = new char[strLen(name) + 1];
            strCpy(employees.m_name, name);
            ok = true;
        }
        return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function 
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (i = 0;i < noOfEmployees;i++) {
                if (load(employees[i]) == false) {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
                    break;
                }
                else {
                    ok = true;
                }
            }
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        closeFile();
        return ok;
    }

    // TODO: Implementation for the display functions go here
    void display(Employee& employees) {
        cout << employees.m_empNo << ": " << employees.m_name << ", " << employees.m_salary << endl;
    }
    void display()
    {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        sort();
        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }
    // TODO: Implementation for the deallocateMemory function goes here

    void deallocateMemory() {
        delete[] employees;
    }
}