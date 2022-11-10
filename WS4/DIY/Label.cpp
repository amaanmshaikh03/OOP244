/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 4, PART 2(DIY)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Label.h"
using namespace std;
namespace sdds {

	Label::Label(){
		m_frame = "+-+|+-+|";
		m_content = nullptr;
	}
	
	Label::Label(const char* frameArg) {
		m_content = nullptr;
		m_frame = frameArg;
	}
	Label::Label(const char* frameArg, const char* content) {
		m_frame = frameArg;
		m_content = new char[strLen(content) + 1];
		strCpy(m_content, content);
	}
	Label::~Label() {
		delete[] m_content;
	}
	void Label::readLabel() {
		delete[] m_content;
		char content[71];
		cin.getline(content, 71);
		m_content = new char[strLen(content) + 1];
		strCpy(m_content, content);
	}
	std::ostream& Label::printLabel()const {
		if (m_content != nullptr) {
			cout << m_frame[0];
			int i = strLen(m_content) + 2;
			for (int j = 0; j < i; j++) {
				cout << m_frame[1];
			}
			cout << m_frame[2] << endl;
			cout << m_frame[7];
			for (int j = 0; j < i; j++) {
				cout << " ";
			}
			cout << m_frame[3] << endl;
			cout << m_frame[7] << " ";
			for (int j = 0; j < i-2; j++) {
				cout << m_content[j];
			}
			cout << " " << m_frame[3] << endl;
			cout << m_frame[7];
			for (int j = 0; j < i; j++) {
				cout << " ";
			}
			cout << m_frame[3] << endl;
			cout << m_frame[6];
			for (int j = 0; j < i; j++) {
				cout << m_frame[5];
			}
			cout << m_frame[4];
		}
		
		return cout;
	}
}