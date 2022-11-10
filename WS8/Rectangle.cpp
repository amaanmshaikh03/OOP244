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
#include <sstream>
#include "Rectangle.h"
using namespace std;
namespace sdds {
	Rectangle::Rectangle() : LblShape() {
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label){
		m_height = height;
		m_width = width;
		int a = strlen(LblShape::label());
		if (m_height < 3 || m_width < (a + 2)) {
			m_width = 0;
			m_height = 0;
		}
	}
	Rectangle::~Rectangle() {}
	void Rectangle::draw(std::ostream& os) const {
		if (m_height > 0 && m_width > 0) {
			os << "+";
			for (int i = 0; i < (m_width - 2); i++) {
				os << "-";
			}
			os << "+" << endl;
			os << "|";
			os.width(m_width - 2);
			os << left << label();
			os << "|" << endl;
			for (int i = 0; i < (m_height - 3); i++) {
				os << "|";
				for (int j = 0; j < (m_width - 2); j++) {
					os << " ";
				}
				os << "|" << endl;
			}
			os << "+";
			for (int i = 0; i < (m_width - 2); i++) {
				os << "-";
			}
			os << "+";
		}
	}
	void Rectangle::getSpecs(std::istream& is) {
		string line;
		char del;
		LblShape::getSpecs(is);
		is >> line;
		is.ignore(2000, '\n');

		stringstream ss(line);
		ss >> m_width >> del >> m_height;

	}
}