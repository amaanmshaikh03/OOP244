/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 5, PART 2
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
    Mark::Mark() {
        n_marks = 0;
    }
    Mark::Mark(int marks) {
        n_marks = 0;
        if (int(marks)) {
            n_marks = marks;
        }
    }
    Mark::operator int() {
        int m = 0;
        if (n_marks >= 0 && n_marks <= 100) {
            m = n_marks;
        }
        return m;
    }

    int Mark::operator+=(int marks) {
        if (int(marks)) {
            n_marks += marks;
        }
        return *this;
    }
    int Mark::operator=(int& marks) {
        if (int(marks)) {
            n_marks = marks;
        }
        return *this;
    }
    Mark::operator double() {
        double gpa = 0.0; 
        if (int(*this))
        {
            if (n_marks >= 0 && n_marks < 50) {
                gpa = 0.0;
            }
            else if (n_marks >= 50 && n_marks < 60) {
                gpa = 1.0;
            }
            else if (n_marks >= 60 && n_marks < 70) {
                gpa = 2.0;
            }
            else if (n_marks >= 70 && n_marks < 80) {
                gpa = 3.0;
            }
            else {
                gpa = 4.0;
            }
        }

        return gpa;
    }

    Mark::operator char() {
        char grade;
        if (int(*this)) {

            if (n_marks >= 0 && n_marks < 50) {
                grade = 'F';
            }
            else if (n_marks >= 50 && n_marks < 60) {
                grade = 'D';
            }
            else if (n_marks >= 60 && n_marks < 70) {
                grade = 'C';
            }
            else if (n_marks >= 70 && n_marks < 80) {
                grade = 'B';
            }
            else {
                grade = 'A';
            }
        }
        else {
            grade = 'X';
        }
        return grade;
    }

    int operator+=(int& marks, Mark& mrk)
    {
      
        if (int(mrk.n_marks)) {
            marks += mrk.Mark::operator int();
        }
        return marks;
    }
}