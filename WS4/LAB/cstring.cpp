/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 4, PART 1(LAB)
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
	
	int strCmp(const char* s1, const char* s2) {
		int a = 0;
		for (int i = 0; s2[i] != '\0'; i++) {
			if (a == 0) {
				if (s1[i] == s2[i]) {
					a = 0;
				}
				else if (s1[i] > s2[i]) {
					a = 1;
				}
				else if (s1[i] < s2[i]) {
					a = -1;
				}
			}
		}
		return a;
	}

	int strLen(const char* s) {
		int i = 0;
		for (i = 0; s[i] != '\0'; i++);
		
		return i;
	}
}

	