/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 3, PART 2(DIY)
*/

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    class Food {
        char m_itemName[31];
        int m_calorie;
        int m_time;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calorie, int time);
        int Calorie()const;
        void display()const;
        bool isValid()const;
    };
}

#endif // !SDDS_SUBJECT_H