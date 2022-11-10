/*
Name: Mohammedamaan Shaikh
Student ID: #157304197
Email: mishaikh3@myseneca.ca
Subject: OOP244
WORKSHOP 7
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "MotorVehicle.h"

using namespace std;
namespace sdds{
	MotorVehicle::MotorVehicle(const char* licensenum, int yr) {
		strCpy(m_licenseplatenum, licensenum);
		strCpy(m_address, "Factory");
		m_yr = yr;
	}


	void MotorVehicle::moveTo(const char* address) {
		if (strCmp(address, m_address) != 0) {
			cout << "|" << setw(8) << std::right << m_licenseplatenum << "| " << "|" << setw(20) << std::right << m_address << " ---> ";
			strCpy(m_address, address);
			cout << setw(20) << std::left << address << "|" << endl;
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& os) const {
		os << "| " << m_yr << " | " << m_licenseplatenum << " | " << m_address;
		return os;
	}


	std::istream& MotorVehicle::read(std::istream& in) {
		cout << "Built year: ";
		in >> m_yr;
		cout << "License plate: ";
		in >> m_licenseplatenum;
		cout << "Current location: ";
		in >> m_address;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const MotorVehicle& vehicle) {
		return vehicle.write(os);
	}


	std::istream& operator>>(std::istream& in, MotorVehicle& vehicle) {
		return vehicle.read(in);
	}
}