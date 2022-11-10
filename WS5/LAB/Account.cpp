/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 5, PART 1(LAB)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }

    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }

    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }

    Account::operator bool() const {
        bool valid = false;
        if (m_number >= 10000 && m_number <= 99999
            && m_balance >= 0) {
            valid = true;
        }
        return valid;
    }

    Account::operator int() const {
        return m_number;
    }

    Account::operator double() const {
        return m_balance;
    }
    bool Account::operator ~() const {
        bool ok = false;
        if (m_number == 0) {
            ok = true;
        }
        return ok;
    }
    Account& Account::operator=(int q) {
        if (q >= 10000 && q <= 99999) {
            if (m_number == 0) {
                m_number = q;
            }
        }
        else {
            setEmpty();
        }
        return *this;
    }

    Account& Account::operator=(Account& a) {
        if (m_number == 0) {
            if (bool(a)) {
                m_balance = a.m_balance;
                m_number = a.m_number;
                a.m_balance = 0;
                a.m_number = 0;
            }
        }
        return *this;
    }

    Account& Account::operator+=(double addingvalue) {
        if (addingvalue > 0 && bool(*this)) {
            m_balance += addingvalue;
        }
        return *this;
    }

    Account& Account::operator-=(double removevalue) {
        if ((m_balance - removevalue) > 0 && removevalue >= 0 && bool(*this)) {
            m_balance -= removevalue;
        }
        return *this;
    }

    Account& Account::operator<<(Account& b) {
        if (b.m_balance >= 0 && m_balance != b.m_balance) {
            m_balance += b.m_balance;
            b.m_balance = 0;
        }
        return *this;
    }

    Account& Account::operator>>(Account& c) {
        if (c.m_balance >= 0 && m_balance != c.m_balance) {
            c.m_balance += m_balance;
            m_balance = 0;
        }
        return *this;
    }

    double operator+(const Account& left, const Account& right) {
        double val = 0.0;
        if (bool(left) && bool(right)){
            val= double(left) + double(right);

        }        
        return val;
    }

    double operator+=(double& left, const Account& right) {
        left += double(right);
        return left;
    }
}

