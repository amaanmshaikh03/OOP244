/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 5, PART 2
*/


#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {

    public:
        int n_marks;
        Mark();
        Mark(int);
        operator int();
        int operator+=(int);
        int operator=(int&);
        operator double();
        operator char();

    };
    int operator+=(int&, Mark&);

}
#endif // SDDS_MARK_H_
