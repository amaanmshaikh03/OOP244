#ifndef NAMESPACE_Utils_H // replace with relevant names
#define NAMESPACE_Utils_H
namespace sdds {
	// Your header file content goes here
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
}
#endif