
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