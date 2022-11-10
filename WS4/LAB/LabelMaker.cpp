#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LabelMaker.h"
#include "cstring.h"
using namespace std;
namespace sdds {
	LabelMaker::LabelMaker(int noOfLabels) {
		m_number = noOfLabels;
		labels = new Label[m_number + 1];
	}
	void LabelMaker::readLabels() {
		cout << "Enter " << m_number << " labels:" << endl;
		for (int i = 0; i < m_number; i++) {
			cout << "Enter label number " << i + 1 << endl;
			cout << "> ";
			labels[i].readLabel();
		}
	}
	void LabelMaker::printLabels() {
		for (int i = 0; i < m_number; i++)
		{
			labels[i].printLabel() << endl;
		
		}
	}
	LabelMaker::~LabelMaker() {
		delete[] labels;
	}
}