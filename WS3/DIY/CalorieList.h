/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 3, PART 2(DIY)
*/

#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Food.h"
namespace sdds {
    class CalorieList {
        char m_title[51] = " Daily Calorie Consumption";
        Food* m_foods;
        int m_size;
        int m_itemsadded;
        int totalcalorie()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(int size);
        bool add(const char* item_name, int calorie, int when);
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_TRANSCRIPT_H