/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 6, PART 1(LAB)
*/
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        delete[] m_value;
    }

    void TextFile::setEmpty() {
        if (bool() == false) {
            delete[] m_textLines;
            m_textLines = nullptr;
            delete[] m_filename;
            m_filename = nullptr;
            m_noOfLines = 0;
        }
    }
    void TextFile::setFilename(const char* fname, bool isCopy) {
        delete[] m_filename;
        m_filename = nullptr;
        if (isCopy == false) {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
        else {
            m_filename = new char[strLen(fname) + 3];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
    }
    void TextFile::setNoOfLines() {
        ifstream fin;
        fin.open(name());
        int a = 0;
        string l;
        if (fin.is_open()) {
            do {
                a++;
            } while (getline(fin, l, '\n'));
            if (a == 0) {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfLines = (a + 1);
            }
            fin.close();
        }
    }
    void TextFile::loadText() {
        int a = 0;
        if (bool() == false) {
            delete[] m_textLines;
            m_textLines = nullptr;
            m_textLines = new Line[m_noOfLines];
            ifstream fin;
            fin.open(name());
            string l;
            while (getline(fin, l)) {
                m_textLines[a] = l.c_str();
                a++;
            }
            m_noOfLines = a;
            fin.close();
        }
    }
    void TextFile::saveAs(const char* fileName)const {
        ofstream fin;
        fin.open(fileName);
        if (fin.is_open()) {
            for (unsigned i = 0; i < m_noOfLines; i++) {
                fin << m_textLines[i] << endl;
            }
        }
        fin.close();
    }
    TextFile::TextFile(unsigned pageSize) {
        m_noOfLines = 0;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_pageSize = pageSize;
    }
    TextFile::TextFile(const char* filename, unsigned pageSize) {
        m_pageSize = pageSize;
        m_noOfLines = 0;
        m_textLines = nullptr;
        m_filename = nullptr;
        m_pageSize = pageSize;
        if (filename) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }
    TextFile::TextFile(const TextFile& incomingfile) {
        m_pageSize = incomingfile.m_pageSize;
        m_filename = nullptr;
        m_textLines = nullptr;
        m_noOfLines = 0;
        if (bool(incomingfile)) {
            setFilename(incomingfile.name(), true);
            incomingfile.saveAs(name());
            setNoOfLines();
            loadText();
        }
    }
    TextFile& TextFile::operator=(const TextFile& incomingfile) {
        if (bool(incomingfile)) {
            delete[] m_textLines;
            m_textLines = nullptr;
            incomingfile.saveAs(name());
            setNoOfLines();
            loadText();
        }
        return *this;
    }
    TextFile::~TextFile(){
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
    }
    unsigned TextFile::lines()const{
        return  m_noOfLines;
    }
    std::ostream& TextFile::view(std::ostream& ostr)const {
        unsigned a = 0;
        if (bool(*this) && m_noOfLines >= 1) {
            ostr << m_filename << endl;
            for (int i = 0; i < strLen(m_filename); i++) {
                ostr << '=';
            }
            ostr << endl;
            for (unsigned i = 0; i < m_noOfLines; i++) {
                if (a == m_pageSize)
                {
                    a = 0;
                    ostr << "Hit ENTER to continue...";
                    while (cin.get() != '\n');
                }
                ostr << m_textLines[i].m_value << endl;
                a++;

            }
        }
        return ostr;
    }
    std::istream& TextFile::getFile(std::istream& istr) {
        string input;
        istr >> input;
        cin.ignore();
        setFilename(input.c_str());
        setNoOfLines();
        loadText();
        return istr;
    }
    const char* TextFile::operator[](unsigned index)const {
        const char* l = nullptr;
        if (*this) {
            l = m_textLines[index % m_noOfLines];
        }
        return l;
    }
    const char* TextFile::name()const{
        return m_filename;
    }
    TextFile::operator bool()const {
        bool ok = true;
        if (m_filename == nullptr && m_textLines == nullptr && m_noOfLines == 0) {
            ok = false;
        }
        return ok;
    }
    ostream& operator<<(ostream& ostr, const TextFile& text) {
        text.view(ostr);
        return ostr;
    }
    istream& operator>>(istream& istr, TextFile& text) {
        text.getFile(istr);
        return istr;
    }
}