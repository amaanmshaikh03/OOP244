/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 3, PART 2(DIY)
*/


#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {

	void CalorieList::setEmpty() {
		*m_title = '\0';
		m_foods= nullptr;
	}

	bool CalorieList::isValid()const {
		bool isValid = false;
		int count = 0;
		
		if (m_title[0] != '\0' && m_foods != nullptr) {
			for (int i = 0; i < m_size;i++) {
				if (m_foods[i].isValid() == true) {
					count++;
				}
			}
		}
		if (count == m_size) {
			isValid = true;
		}
		return isValid;
	}

	int CalorieList::totalcalorie()const {
		int totalcalorie = 0;
		for (int i = 0; i < m_size;i++) {
			totalcalorie += m_foods[i].Calorie();
		}
		return totalcalorie;
	}

	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (CalorieList::isValid()) {
			cout << "| ";
			cout.width(50);
			cout.setf(ios::left);
			cout << m_title;
			cout.unsetf(ios::left);
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (CalorieList::isValid()) {
			cout << "|    Total Calories for today:";
			cout.width(9);
			cout.setf(ios::fixed);
			cout << totalcalorie();
			cout << " |            |" << endl;
			
		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::init(int size) {
		if (size <= 0) {
			size = 0;
		}
		else {
			m_size = size;
			m_itemsadded = 0;
			m_foods = new Food[m_size];
			for (int i = 0; i < m_size; i++) {
				m_foods[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* item_name, int calorie, int when){
		bool addvalidation = false;
		if (m_itemsadded < m_size) {
			m_foods[m_itemsadded].set(item_name, calorie, when);
			m_itemsadded++;
			addvalidation = true;
		}
		return addvalidation;
	}

	void CalorieList::display()const {
		CalorieList::Title();
		for (int i = 0; i < m_size; i++) {
			m_foods[i].display();
		}
		CalorieList::footer();
	}

	void CalorieList::deallocate() {
		delete[] m_foods;
		m_foods = nullptr;
	}

}