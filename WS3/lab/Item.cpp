/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 3, PART 1(LAB)
*/
#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
#define TAX 0.13
namespace sdds {

    void Item::setName(const char* name) {
        strnCpy(m_itemName, name,20);
        m_itemName[20] = '\0';
    }


    void Item::setEmpty() {
        m_itemName[0] = '\0';
        m_price = 0.00;
    }

    void Item::set(const char* name, double price, bool taxed) {
        if (price < 0 || name == nullptr) {
            setEmpty();
        }
        else {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    double Item::price()const {
        return m_price;
    }

    double Item::tax()const {
        double tax;
        if (m_taxed == false) {
            tax = 0;
        }
        else {
            tax = m_price * TAX;
        }
        return tax;
    }

    bool Item::isValid()const {
        bool ok = false;
        if (m_itemName[0] != '\0') {
            ok = true;
        }
        return ok;
    }


    void Item::display()const {
        bool valid = Item::isValid();
        if (valid == true) {
            cout << "| ";
            cout.width(20);
            cout.fill('.');
            cout.setf(ios::left);
            cout << m_itemName;
            cout.fill(' ');
            cout.unsetf(ios::left);
            cout << " | ";
            cout.setf(ios::fixed);
            cout.precision(2);
            cout.width(7);
            cout << m_price;
            cout.unsetf(ios::fixed);
            cout << " | ";
            if (m_taxed == true) {
                cout << "Yes";
            }
            else {
                cout.setf(ios::left);
                cout.width(3);
                cout << "No";
                cout.unsetf(ios::left);
            }
            cout << " |" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }


}