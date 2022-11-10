/*
Name: Mohammedamaan Shaikh
sudent ID: 157304197
email: mishaikh3@myseneca.ca
Workshop 8
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"
using namespace std;
namespace sdds {
	char* LblShape::label() const{
		return m_label;
	}
	LblShape::LblShape() {
		m_label = nullptr;
	}
	LblShape::LblShape(const char* label) {
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}
	LblShape::~LblShape() {
		delete[] m_label;
	}
	void LblShape::getSpecs(istream& istr) {
		string l;
		getline(istr, l, ',');
		delete[] m_label;
		m_label = nullptr;
		m_label = new char[l.length() + 1];
		strcpy(m_label, l.c_str());
	}
}