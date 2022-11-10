#pragma once
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	bool read(char* code);
	bool read(int& noofpopulation);
}
#endif // !SDDS_FILE_H_