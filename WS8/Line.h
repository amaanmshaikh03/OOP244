/*
Name: Mohammedamaan Shaikh
sudent ID: 157304197
email: mishaikh3@myseneca.ca
Workshop 8
*/
#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_
#include <iostream>
#include "LblShape.h"
namespace sdds {
	class Line : public LblShape{
		int m_length;
	public:
		Line();
		Line(const char*, int);
		~Line();
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif