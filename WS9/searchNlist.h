#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include <iostream>
#include "Collection.h"
using namespace std;
namespace sdds {
	/*Template has two typenames in it, one of which is used for class and other is a key. The parameters in the search function is a reference to a templated object, array , an integer counting the number of elements and a key*/
	template <typename T, typename A>
	bool search(Collection<T>& collect, const T* arr, int num, A key) {
		bool ok = false;
		for (int i = 0; i < num; i++) {
			if (arr[i] == key) {
					ok = true;
					collect.add(arr[i]);
			}

		}
		return ok;
	}
	/*Template has a typename and requires a constant character reference for the title, constant reference for the array and an integer for the number of element in array*/
	template <typename C>
	void listArrayElements(const char* t, const C& arr, int num) {
		cout << t << endl;
		for (int i = 0; i < num; i++) {
			cout << (i + 1) << ": " << arr[i] << endl;
		}
	}
}
#endif