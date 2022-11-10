/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 10
*/

#include <iostream>
#include <fstream>
#include "cstring.h"
#include "Text.h"
using namespace std;
namespace sdds {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }
    const char& Text::operator[](int index)const{
        return m_content[index];
    }
    Text::Text(const char* filename){
 	m_filename = nullptr;
        m_content = nullptr;
        if (filename != nullptr){
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            read();
        }
    }
    Text::~Text(){
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_content;
        m_content = nullptr;
    }
    Text::Text(const Text& text){
        if (text.m_filename != nullptr) {
            m_filename = new char[strLen(text.m_filename) + 1];
            strCpy(m_filename, text.m_filename);
            m_content = new char[strLen(text.m_content) + 1];
            strCpy(m_content, text.m_content);
        }
    }
    Text& Text::operator=(const Text& text){
        if (this != &text){
            delete[] m_filename;
            m_filename = nullptr;
            delete[] m_content;
            m_content = nullptr;
            m_filename = new char[strLen(text.m_filename) + 1];
            strCpy(m_filename, text.m_filename);
            m_content = new char[strLen(text.m_content) + 1];
            strCpy(m_content, text.m_content);
        }
        return *this;
    }
    void Text::read(){
        char a;
        int b = 0;
        delete[] m_content;
        m_content = nullptr;
        m_content = new char[getFileLength() + 1];
        ifstream f(m_filename);
        while (f.get(a)){
            m_content[b] = a;
            b++;
        }
        m_content[b] = '\0';
    }
    void Text::write(std::ostream& ostr)const {
        if (m_content != nullptr) {
            ostr << m_content;
        }
    }
    std::ostream& operator<<(std::ostream& ostr, const Text& text){
        text.write(ostr);
        return ostr;
    }
}