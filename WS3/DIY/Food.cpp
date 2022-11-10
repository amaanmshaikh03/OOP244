/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 3, PART 2(DIY)
*/


#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
#define TAX 0.13
namespace sdds {

    void Food::setName(const char* name) {
        strnCpy(m_itemName, name,30);
        m_itemName[30] = '\0';
    }


    void Food::setEmpty() {
        m_itemName[0] = '\0';
        m_calorie = 0;
    }

    void Food::set(const char* name, int calorie, int time) {
        if (calorie < 0 || name == nullptr) {
            setEmpty();
        }
        else {
            setName(name);
            m_calorie =  calorie;
            m_time = time;
        }
    }

    int Food::Calorie()const {
        return m_calorie;
    }
    

    
    bool Food::isValid()const {
        bool ok = false;
        if (m_itemName[0] != '\0'&& m_calorie > 0 && m_calorie <=3000 && m_time >=1 && m_time <=4) {
            ok = true;
        }
        return ok;
    }


    void Food::display()const {
        bool valid = Food::isValid();
        if (valid == true) {
            cout << "| ";
            cout.width(30);
            cout.fill('.');
            cout.setf(ios::left);
            cout << m_itemName;
            cout.fill(' ');
            cout.unsetf(ios::left);
            cout << " | ";
            cout.setf(ios::fixed);
            cout.width(4);
            cout << m_calorie;
            cout.unsetf(ios::fixed);
            cout << " | ";
            cout.width(10);
            cout.setf(ios::left);
            if (m_time == 1) {
                cout << "Breakfast";
            }
            else if (m_time == 2) {
                cout << "Lunch";
            }
            else if (m_time == 3) {
                cout << "Dinner";
            }
            else if (m_time == 4) {
                cout << "Snack";
            }
            cout.unsetf(ios::left);
            cout << " |" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }


}