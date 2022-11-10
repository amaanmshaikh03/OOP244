/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 5, PART 1(LAB)
*/


#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool() const;
        operator int() const;
        operator double() const;
        bool operator ~() const;
        Account& operator=(int);
        Account& operator=(Account&);
        Account& operator+=(double);
        Account& operator-=(double);
        Account& operator<<(Account&);
        Account& operator>>(Account&);

    };

    double operator+(const Account&, const Account&);
    double operator+=(double&, const Account&);

}
#endif // SDDS_ACCOUNT_H_
