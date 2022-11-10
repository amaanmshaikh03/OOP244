/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 6, PART 2(DIY)
*/

#include <iostream>
namespace sdds {
    class Stats {
        char* s_filename;
        double* s_num;
        double zero;
        unsigned s_noofnums;
        unsigned s_columnwidth;
        unsigned s_noofcol;
        unsigned s_precision;
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfNums();
        void loadnum();
        void saveAs(const char* fileName)const;
        void setEmpty();
    public:
        Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
        Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
        Stats(const Stats&);
        Stats& operator= (const Stats&);
        ~Stats();
        double& operator[](unsigned idx);
        double operator[](unsigned idx)const;
        operator bool()const;
        void sort(bool ascending);
        unsigned size()const;
        const char* name()const;
        unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Stats& text);
    std::istream& operator>>(std::istream& istr, Stats& text);
}