/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 2, PART 2(DIY)
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
	void strnCpy(char* des, const char* src, int len) {
		int i;
		for (i = 0; i < len; i++)
			des[i] = src[i];

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

	int strnCmp(const char* s1, const char* s2, int len) {
		int a = 0;
		for (int i = 0; i < len; i++) {
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
		int a = 0;
		for (int i = 0; s[i] != '\0'; i++)
			a++;

		return a;
	}


	const char* strStr(const char* str1, const char* str2) {
		int c = strLen(str1);
		int b = strLen(str2);
		char* str = nullptr;
		char str6[30] = "";
		int i, k = -1;
		if (c > b) {
			for (i = 0; i < c; i++) {
				if (str1[i] == str2[0]) {
					for (int g = i; g < i + b; g++) {
						str6[g - i] = str1[g];
					}
					if (!strCmp(str6, str2)) {
						k = 0;
						break;
					}
				}
			}
		}
		if (k != -1) {
			return &str1[i];
		}
		else {
			return str;
		}
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

	