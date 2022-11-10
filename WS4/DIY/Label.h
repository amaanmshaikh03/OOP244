/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 4, PART 2(DIY)
*/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
#include <string>
namespace sdds {

	class Label {
		char* m_content;
		const char* m_frame;
	
	public:
		void readLabel();
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		std::ostream& printLabel()const;
	};

}
#endif