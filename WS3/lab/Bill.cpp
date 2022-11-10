/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 3, PART 1(LAB)
*/
#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

	void Bill::setEmpty() {
		*m_title = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid()const {
		bool isValid = false;
		int count = 0;
		if (m_title[0] != '\0' && m_items != nullptr) {
			for (int i = 0; i < m_noOfItems;i++) {
				if (m_items[i].isValid() == true) {
					count++;
				}
			}
		}
		if (count == m_noOfItems) {
			isValid = true;
		}
		return isValid;
	}

	double Bill::totalTax()const {
		double totaltax = 0.0;
		for (int i = 0; i < m_noOfItems;i++) {
			totaltax += m_items[i].tax();
		}
		return totaltax;
	}

	double Bill::totalPrice()const {
		double totalprice = 0.0;
		for (int i = 0; i < m_noOfItems;i++) {
			totalprice += m_items[i].price();
		}
		return totalprice;
	}

	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;
		if (Bill::isValid()) {
			cout << "| ";
			cout.width(36);
			cout.setf(ios::left);
			cout << m_title;
			cout.unsetf(ios::left);
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;
		if (Bill::isValid()) {
			cout << "|                Total Tax: ";
			cout.setf(ios::fixed);
			cout.width(10);
			cout.precision(2);
			cout << totalTax();
			cout << " |" << endl;
			cout << "|              Total Price: ";
			cout.width(10);
			cout << totalPrice();
			cout << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout << totalTax() + totalPrice();
			cout << " |" << endl;
			cout.unsetf(ios::fixed);
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems) {
		if (title == 0 || noOfItems <= 0) {
			title = 0;
			noOfItems = 0;
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool addvalidation = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			addvalidation = true;
		}
		return addvalidation;
	}

	void Bill::display()const {
		Bill::Title();
		for (int i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		Bill::footer();
	}

	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}

}