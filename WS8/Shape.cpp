/*
Name: Mohammedamaan Shaikh
sudent ID: 157304197
email: mishaikh3@myseneca.ca
Workshop 8
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Shape.h"
namespace sdds {
	Shape::~Shape() {

	}
	std::ostream& operator<<(std::ostream& ostr, const Shape& a) {
		a.draw(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Shape& a) {
		a.getSpecs(istr);
		return istr;
	}
}
