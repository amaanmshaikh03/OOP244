/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 2, PART 1(LAB)
*/
#pragma once
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes
	bool read(char* empname);
	bool read(int &empnum);
	bool read(double &empsalaray);


}
#endif // !SDDS_FILE_H_