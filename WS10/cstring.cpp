/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 10
*/


#include <iostream>
#include "cstring.h"
using namespace std;
namespace sdds {
	void strCpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i] != '\0'; i++) {
			des[i] = src[i];
		}
		des[i] = '\0';
	}

	int strLen(const char* s) {
		int i = 0;
		for (i = 0; s[i] != '\0'; i++);

		return i;
	}
}

