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