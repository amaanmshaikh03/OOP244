/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 4, PART 1(LAB)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
#define PI 3.14159265
using namespace std;
namespace sdds {

    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_diameter = 10.0;
        m_hieght = 13.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }
    
    bool Canister::isEmpty()const {
        bool valid = false;
        if (m_contentVolume < 0.00001)
            valid = true;
        return valid;
    }

    bool Canister::hasSameContent(const Canister& C)const {
        bool ok = false;
        if (C.m_contentName != NULL && m_contentName != NULL && strCmp(m_contentName, C.m_contentName) == 0)
            ok = true;
        return ok;
    }

    void Canister::setName(const char* Cstr) {
        if (Cstr != NULL && m_usable == true) {
            delete[] m_contentName;
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }

    Canister::Canister() {
        setToDefault();
    }

    Canister::Canister(const char* contentName){
        setToDefault();
        setName(contentName);
    }

    Canister::Canister(double hieght, double diameter, const char* contentName) {
        setToDefault();
        if (hieght >= 10.0 && hieght <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
            m_hieght = hieght;
            m_diameter = diameter;
            m_contentVolume = 0;
            setName(contentName);
        }
        else {
            m_usable = false;
        }
    }

    Canister::~Canister(){
        delete[] m_contentName;
    }

    void Canister::clear() {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }

    double Canister::capacity()const {
        double capacity = PI * (m_hieght - 0.267) * (m_diameter / 2) * (m_diameter / 2);
        return capacity;
    }

    double Canister::volume()const {
        return m_contentVolume;
    }

    Canister& Canister::setContent(const char* contentName) {
        if (contentName == NULL) {
            m_usable = false;
        }
        else if (isEmpty() == true) {
            setName(contentName);
        }
        else if(hasSameContent(contentName) == false){
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(double quantity) {
        if(m_usable == true && quantity > 0 && (quantity+volume()) <= capacity()){
            m_contentVolume += quantity;
        }
        else {
            m_usable = false;
        }
        return *this;
    }

    Canister& Canister::pour(Canister& C) {
        setContent(C.m_contentName);
        if (C.m_contentVolume > (capacity() - volume())) {
            C.m_contentVolume -= (capacity() - volume());
            m_contentVolume = capacity();
        }
        else {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }

    std::ostream& Canister::display()const {
        cout.precision(1);
        cout.width(7);
        cout.setf(ios::fixed);
        cout << capacity();
        cout << "cc (" << m_hieght << "x" << m_diameter << ") Canister";
        if (m_usable == false) {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) {
            cout <<" of ";
            cout.width(7);
            cout << volume();
            cout << "cc   " << m_contentName;
        }
        cout.unsetf(ios::fixed);
        return cout;
    }
}