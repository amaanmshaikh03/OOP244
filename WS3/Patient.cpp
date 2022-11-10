#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "Patient.h"
#include "utils.h"

using namespace std;
namespace sdds {
    Patient::Patient(int ohipnum, bool ioflag) : t_ticket(ohipnum) {
        p_ioflag = ioflag;
    }
    Patient::~Patient()
    {
        delete[] p_patientname;
    }
    bool Patient::fileIO() const
    {
        return p_ioflag;
    }
    void Patient::fileIO(bool ioflag)
    {
        p_ioflag = ioflag;
    }
    bool Patient::operator ==(char c) const
    {
        bool ok = false;
        if (c == type()) {
            ok = true;
        }
        return ok;
    }
    bool Patient::operator ==(const Patient& currentpatient) const
    {
        bool ok = false;
        if (type() == currentpatient.type()) {
            ok = true;
        }
        return ok;
    }
    void Patient::setArrivalTime()
    {
        t_ticket.resetTime();
    }
    Patient::operator Time() const
    {
        return Time(t_ticket);
    }
    int Patient::number() const
    {
        return t_ticket.number();
    }
    std::ostream& Patient::csvWrite(std::ostream& os) const {
        os << type() << "," << p_patientname << "," << p_ohipnum << "," ;
        return t_ticket.csvWrite(os);
    }
    std::istream& Patient::csvRead(std::istream& is) {
        string l;
        getline(is, l, ',');
        delete[] p_patientname;
        p_patientname = new char[l.length() + 1];
        strcpy(p_patientname, l.c_str());
        is >> p_ohipnum;
        is.ignore();
        return t_ticket.csvRead(is);
    }
    std::ostream& Patient::write(std::ostream& os) const{
        os << t_ticket << '\n';
        for (int i = 0; i < 25 && p_patientname[i]; i++)
        {
            os << p_patientname[i];
        }
        os << ", OHIP: ";
        os << p_ohipnum;
        return os;
    }
    std::istream& Patient::read(std::istream& is){
        cout << "Name: ";
        string l;
        getline(is, l);
        delete[] p_patientname;
        p_patientname = new char[l.length() + 1];
        strcpy(p_patientname, l.c_str());
        cout << "OHIP:";
        p_ohipnum = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ");
        return is;
    }
}