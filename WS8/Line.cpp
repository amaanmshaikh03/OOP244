/*
Name: Mohammedamaan Shaikh
sudent ID: 157304197
email: mishaikh3@myseneca.ca
Workshop 8
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <string>
#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line() : LblShape() {
		m_length = 0;
	}
	Line::Line(const char* label, int length) : LblShape(label) {
		m_length = length;
	}
	Line::~Line(){}
	void Line::draw(std::ostream& os) const {
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;
			for (int i = 0; i < m_length; i++) {
				os << "=";
			}
		}
	}
	void Line::getSpecs(std::istream& is) {
		string l;
		LblShape::getSpecs(is);
		is >> l;
		is.ignore(2000, '\n');
		stringstream ss(l);
		ss >> m_length;
	}
}