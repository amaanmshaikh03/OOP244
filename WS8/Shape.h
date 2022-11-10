/*
Name: Mohammedamaan Shaikh
sudent ID: 157304197
email: mishaikh3@myseneca.ca
Workshop 8
*/
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>
namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream&) const = 0;
		virtual void getSpecs(std::istream&) = 0;
		virtual ~Shape();
	};
	std::ostream& operator<<(std::ostream& ostr, const Shape& a);
	std::istream& operator>>(std::istream& istr, Shape& a);
}
#endif