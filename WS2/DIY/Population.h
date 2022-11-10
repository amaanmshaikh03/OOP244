/*
Name: Mohammedamaan Shaikh
StudentID: 157304197
Email: mishaikh3@myseneca.ca
Workshop 2 DIY
*/

#pragma once
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define DATAFILE "PCpopulations.csv"

namespace sdds {
	struct Population {
		char* code;
		int noofpopulation;
	};
	bool load(Population& population);
	bool load(const char* filename);
	int display(const Population& populations);
	void display();
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_