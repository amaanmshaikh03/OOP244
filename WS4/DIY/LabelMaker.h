/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 4, PART 2(DIY)
*/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>
#include "Label.h"
namespace sdds {
	class LabelMaker {
		int m_number;
		Label* labels;
	public:
		LabelMaker(int noOfLabels);
		~LabelMaker();
		void readLabels();
		void printLabels();
	};
}
#endif