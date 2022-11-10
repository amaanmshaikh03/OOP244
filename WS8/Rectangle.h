/*
Name: Mohammedamaan Shaikh
sudent ID: 157304197
email: mishaikh3@myseneca.ca
Workshop 8
*/
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include <iostream>
#include "LblShape.h"
namespace sdds {
	class Rectangle : public LblShape{
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		~Rectangle();
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif
