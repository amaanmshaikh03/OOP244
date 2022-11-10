/*
Name: Mohammedamaan Shaikh
sudent ID: 157304197
email: mishaikh3@myseneca.ca
Workshop 8
*/
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include <iostream>
#include "Shape.h"
namespace sdds {
	class LblShape : public Shape{
		char* m_label;
	protected:
		char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape& source) = delete;
		LblShape& operator=(const LblShape& source) = delete;
		void getSpecs(std::istream&);
	};
}
#endif