/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 6, PART 2(DIY)
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
	void strCat(char* des, const char* src) {
		int a = strLen(des);
		int b = strLen(src);
		int i;
		for (i = a; i < a + b; i++)
			des[i] = src[i - a];
		des[i] = '\0';
	}

}
